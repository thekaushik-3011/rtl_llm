"""
RTL Generator
Uses LLM to generate synthesizable Verilog RTL from specifications
"""

import os
import logging
from typing import Dict, Any
from openai import OpenAI


class RTLGenerator:
    """Generate Verilog RTL using LLM"""
    
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
        self.max_tokens = int(os.getenv('MAX_TOKENS', '2000'))
    
    def generate(self, spec_data: Dict[str, Any]) -> str:
        """
        Generate RTL from specification
        
        Args:
            spec_data: Structured specification dictionary
        
        Returns:
            Generated Verilog code
        """
        self.logger.info(f"Generating RTL for module: {spec_data.get('module')}")
        
        # Build prompt
        prompt = self._build_generation_prompt(spec_data)
        
        # Call LLM
        response = self._call_llm(prompt)
        
        # Extract and clean Verilog code
        verilog_code = self._extract_verilog(response)
        
        self.logger.info("RTL generation complete")
        return verilog_code
    
    def refine(self, spec_data: Dict[str, Any], 
               current_rtl: str, 
               verification_result: Dict[str, Any]) -> str:
        """
        Refine RTL based on verification feedback
        
        Args:
            spec_data: Original specification
            current_rtl: Current RTL code with issues
            verification_result: Verification errors and warnings
        
        Returns:
            Refined Verilog code
        """
        self.logger.info("Refining RTL based on verification feedback")
        
        # Build refinement prompt
        prompt = self._build_refinement_prompt(
            spec_data, current_rtl, verification_result
        )
        
        # Call LLM
        response = self._call_llm(prompt)
        
        # Extract refined code
        refined_code = self._extract_verilog(response)
        
        self.logger.info("RTL refinement complete")
        return refined_code
    
    def _build_generation_prompt(self, spec_data: Dict[str, Any]) -> str:
        """Build prompt for initial RTL generation"""
        
        module_name = spec_data.get('module', 'design')
        description = spec_data.get('description', '')
        timing = spec_data.get('timing', 'combinational')
        inputs = spec_data.get('inputs', [])
        outputs = spec_data.get('outputs', [])
        operations = spec_data.get('operations', [])
        
        # Format inputs
        inputs_str = "\n".join([
            f"  - {inp['name']}: {inp['width']}-bit {inp.get('description', '')}"
            for inp in inputs
        ])
        
        # Format outputs
        outputs_str = "\n".join([
            f"  - {out['name']}: {out['width']}-bit {out.get('description', '')}"
            for out in outputs
        ])
        
        # Format operations
        operations_str = ", ".join(operations) if operations else "as specified"
        
        prompt = f"""You are an expert hardware design engineer specializing in Verilog RTL design.

Generate SYNTHESIZABLE Verilog RTL code for the following specification:

MODULE NAME: {module_name}

DESCRIPTION:
{description}

TIMING: {timing}

INPUTS:
{inputs_str}

OUTPUTS:
{outputs_str}

OPERATIONS: {operations_str}

CRITICAL REQUIREMENTS:
1. Generate ONLY synthesizable Verilog code
2. Use proper Verilog-2001 syntax
3. For sequential logic: use non-blocking assignments (<=) in always @(posedge clk)
4. For combinational logic: use blocking assignments (=) in always @(*)
5. NO delays (#), NO $display or $monitor statements
6. Include proper reset logic if sequential
7. Use meaningful signal names
8. Add brief comments for clarity
9. Ensure all signals are properly declared
10. Make the code production-ready and lint-clean

TEMPLATE STRUCTURE:
```verilog
module {module_name} (
    // Port declarations
);

// Parameter declarations (if any)

// Internal signal declarations

// Main logic blocks

endmodule
```

Generate the complete, synthesizable Verilog module now:"""
        
        return prompt
    
    def _build_refinement_prompt(self, spec_data: Dict[str, Any],
                                 current_rtl: str,
                                 verification_result: Dict[str, Any]) -> str:
        """Build prompt for RTL refinement"""
        
        module_name = spec_data.get('module', 'design')
        errors = verification_result.get('errors', [])
        warnings = verification_result.get('warnings', [])
        
        errors_str = "\n".join([f"  - {err}" for err in errors])
        warnings_str = "\n".join([f"  - {warn}" for warn in warnings])
        
        prompt = f"""You are an expert hardware design engineer. The following Verilog code has issues that need to be fixed.

MODULE NAME: {module_name}

CURRENT CODE:
```verilog
{current_rtl}
```

ERRORS FOUND:
{errors_str if errors else "  None"}

WARNINGS FOUND:
{warnings_str if warnings else "  None"}

TASK:
Fix ALL errors and warnings in the code. Ensure the corrected code:
1. Is fully synthesizable
2. Has no syntax errors
3. Properly declares all signals
4. Uses correct Verilog constructs
5. Maintains the original functionality
6. Follows best practices

Generate the COMPLETE corrected Verilog module (not just the fixes):"""
        
        return prompt
    
    def _call_llm(self, prompt: str) -> str:
        """
        Call LLM API
        
        Args:
            prompt: Input prompt
        
        Returns:
            LLM response text
        """
        self.logger.debug(f"Calling LLM: {self.model}")
        
        try:
            response = self.client.chat.completions.create(
                model=self.model,
                messages=[
                    {
                        "role": "system",
                        "content": "You are an expert Verilog RTL designer. Generate only synthesizable, production-quality code."
                    },
                    {
                        "role": "user",
                        "content": prompt
                    }
                ],
                temperature=self.temperature,
                max_tokens=self.max_tokens
            )
            
            return response.choices[0].message.content
            
        except Exception as e:
            self.logger.error(f"LLM API call failed: {e}")
            raise
    
    def _extract_verilog(self, response: str) -> str:
        """
        Extract Verilog code from LLM response
        Handles markdown code blocks and other formatting
        """
        # Remove markdown code blocks
        if "```verilog" in response:
            # Extract content between ```verilog and ```
            start = response.find("```verilog") + len("```verilog")
            end = response.find("```", start)
            code = response[start:end].strip()
        elif "```" in response:
            # Generic code block
            start = response.find("```") + 3
            end = response.find("```", start)
            code = response[start:end].strip()
        else:
            # No code blocks, use entire response
            code = response.strip()
        
        # Basic validation
        if "module" not in code or "endmodule" not in code:
            self.logger.warning("Generated code may be incomplete")
        
        return code
    
    def generate_with_examples(self, spec_data: Dict[str, Any],
                              examples: list = None) -> str:
        """
        Generate RTL with few-shot examples
        
        Args:
            spec_data: Specification
            examples: List of (spec, rtl) example pairs
        
        Returns:
            Generated Verilog code
        """
        if not examples:
            return self.generate(spec_data)
        
        # Build few-shot prompt
        examples_text = ""
        for i, (ex_spec, ex_rtl) in enumerate(examples, 1):
            examples_text += f"\n### Example {i}:\nSpec: {ex_spec}\n\nRTL:\n```verilog\n{ex_rtl}\n```\n"
        
        base_prompt = self._build_generation_prompt(spec_data)
        prompt = f"""Here are some examples of specifications and their corresponding Verilog implementations:
{examples_text}

Now, generate RTL for this specification:
{base_prompt}"""
        
        response = self._call_llm(prompt)
        return self._extract_verilog(response)