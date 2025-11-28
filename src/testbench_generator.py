"""
Testbench Generator
Generates Verilog testbenches for verification
"""

import os
import logging
from typing import Dict, Any
from openai import OpenAI


class TestbenchGenerator:
    """Generate Verilog testbenches"""
    
    def __init__(self, config: Dict[str, Any]):
        self.config = config
        self.logger = logging.getLogger(__name__)
        
        # Initialize OpenAI client
        api_key = os.getenv('OPENAI_API_KEY')
        if not api_key:
            raise ValueError("OPENAI_API_KEY not found in environment")
        
        self.client = OpenAI(api_key=api_key)
        self.model = os.getenv('DEFAULT_MODEL', 'gpt-4')
        self.temperature = float(os.getenv('TEMPERATURE', '0.2'))
    
    def generate(self, spec_data: Dict[str, Any], rtl_code: str) -> str:
        """
        Generate testbench for RTL module
        
        Args:
            spec_data: Module specification
            rtl_code: RTL code to test
        
        Returns:
            Testbench Verilog code
        """
        self.logger.info(f"Generating testbench for: {spec_data.get('module')}")
        
        # Build prompt
        prompt = self._build_testbench_prompt(spec_data, rtl_code)
        
        # Call LLM
        response = self._call_llm(prompt)
        
        # Extract testbench code
        tb_code = self._extract_verilog(response)
        
        self.logger.info("Testbench generation complete")
        return tb_code
    
    def _build_testbench_prompt(self, spec_data: Dict[str, Any], 
                                rtl_code: str) -> str:
        """Build prompt for testbench generation"""
        
        module_name = spec_data.get('module', 'design')
        timing = spec_data.get('timing', 'combinational')
        inputs = spec_data.get('inputs', [])
        outputs = spec_data.get('outputs', [])
        operations = spec_data.get('operations', [])
        
        # Format test scenarios based on operations
        test_scenarios = self._generate_test_scenarios(spec_data)
        
        prompt = f"""You are an expert verification engineer. Generate a comprehensive Verilog testbench for the following RTL module.

MODULE NAME: {module_name}
TIMING: {timing}

RTL CODE TO TEST:
```verilog
{rtl_code}
```

TESTBENCH REQUIREMENTS:
1. Create testbench module named: tb_{module_name}
2. Instantiate the DUT (Device Under Test)
3. {"Generate clock signal (period = 10ns)" if timing == 'sequential' else "No clock needed (combinational)"}
4. {"Apply reset sequence" if timing == 'sequential' else ""}
5. Apply test vectors covering:
   {test_scenarios}
6. Display test results with $display statements
7. Include:
   - Test vector application
   - Expected vs actual output comparison
   - Pass/Fail indication for each test
   - Final summary (tests passed/total tests)
8. Use initial block for test sequence
9. Include $dumpfile and $dumpvars for waveform generation
10. End simulation with $finish

TESTBENCH STRUCTURE:
```verilog
`timescale 1ns/1ps

module tb_{module_name};
    // Signal declarations
    // Clock generation (if needed)
    // DUT instantiation
    // Test sequence in initial block
    // Output display and checking
endmodule
```

Generate the COMPLETE testbench now:"""
        
        return prompt
    
    def _generate_test_scenarios(self, spec_data: Dict[str, Any]) -> str:
        """Generate test scenario descriptions based on specification"""
        
        operations = spec_data.get('operations', [])
        timing = spec_data.get('timing', 'combinational')
        
        scenarios = []
        
        if operations:
            # Test each operation
            scenarios.append(f"- All operations: {', '.join(operations)}")
        
        # Add timing-specific tests
        if timing == 'sequential':
            scenarios.extend([
                "- Reset behavior",
                "- Sequential operation over multiple clock cycles",
                "- Edge cases (overflow, underflow if applicable)"
            ])
        else:
            scenarios.extend([
                "- Various input combinations",
                "- Boundary conditions",
                "- Corner cases"
            ])
        
        # Add general tests
        scenarios.extend([
            "- Normal operation",
            "- Edge cases",
            "- Random test vectors (10-20 tests)"
        ])
        
        return "\n   ".join(scenarios)
    
    def _call_llm(self, prompt: str) -> str:
        """Call LLM API"""
        self.logger.debug(f"Calling LLM for testbench: {self.model}")
        
        try:
            response = self.client.chat.completions.create(
                model=self.model,
                messages=[
                    {
                        "role": "system",
                        "content": "You are an expert verification engineer. Generate comprehensive, well-structured testbenches."
                    },
                    {
                        "role": "user",
                        "content": prompt
                    }
                ],
                temperature=self.temperature,
                max_tokens=2500
            )
            
            return response.choices[0].message.content
            
        except Exception as e:
            self.logger.error(f"LLM API call failed: {e}")
            raise
    
    def _extract_verilog(self, response: str) -> str:
        """Extract Verilog code from LLM response"""
        # Remove markdown code blocks
        if "```verilog" in response:
            start = response.find("```verilog") + len("```verilog")
            end = response.find("```", start)
            code = response[start:end].strip()
        elif "```" in response:
            start = response.find("```") + 3
            end = response.find("```", start)
            code = response[start:end].strip()
        else:
            code = response.strip()
        
        # Validation
        if "module tb_" not in code or "endmodule" not in code:
            self.logger.warning("Generated testbench may be incomplete")
        
        return code
    
    def generate_directed_testbench(self, spec_data: Dict[str, Any],
                                   rtl_code: str,
                                   test_vectors: list) -> str:
        """
        Generate testbench with specific test vectors
        
        Args:
            spec_data: Module specification
            rtl_code: RTL code
            test_vectors: List of (inputs, expected_outputs) tuples
        
        Returns:
            Testbench code
        """
        self.logger.info("Generating directed testbench")
        
        # Format test vectors
        vectors_str = ""
        for i, (inputs, outputs) in enumerate(test_vectors):
            vectors_str += f"\nTest {i+1}: Inputs={inputs}, Expected={outputs}"
        
        prompt = self._build_testbench_prompt(spec_data, rtl_code)
        prompt += f"\n\nUSE THESE SPECIFIC TEST VECTORS:\n{vectors_str}"
        
        response = self._call_llm(prompt)
        return self._extract_verilog(response)