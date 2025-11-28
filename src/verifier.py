"""
RTL Verifier
Runs linting and simulation to verify generated RTL
"""

import os
import subprocess
import tempfile
import logging
from pathlib import Path
from typing import Dict, Any, List
import re


class RTLVerifier:
    """Verify RTL through linting and simulation"""
    
    def __init__(self, config: Dict[str, Any]):
        self.config = config
        self.logger = logging.getLogger(__name__)
        
        # Tool paths
        self.verilator_path = os.getenv('VERILATOR_PATH', 'verilator')
        self.iverilog_path = os.getenv('IVERILOG_PATH', 'iverilog')
        
        # Output directory
        self.sim_dir = Path(config.get('output_dir', 'output')) / 'simulation_results'
        self.sim_dir.mkdir(parents=True, exist_ok=True)
    
    def verify(self, module_name: str, rtl_code: str, 
               tb_code: str, spec_data: Dict[str, Any]) -> Dict[str, Any]:
        """
        Run complete verification flow
        
        Args:
            module_name: Name of module
            rtl_code: RTL Verilog code
            tb_code: Testbench code
            spec_data: Original specification
        
        Returns:
            Verification results dictionary
        """
        self.logger.info(f"Starting verification for: {module_name}")
        
        results = {
            'passed': False,
            'errors': [],
            'warnings': [],
            'lint_passed': False,
            'sim_passed': False
        }
        
        # Step 1: Lint check
        lint_result = self._run_lint(module_name, rtl_code)
        results['lint_passed'] = lint_result['passed']
        results['errors'].extend(lint_result['errors'])
        results['warnings'].extend(lint_result['warnings'])
        
        if not lint_result['passed']:
            self.logger.error("Linting failed")
            return results
        
        self.logger.info("Linting passed")
        
        # Step 2: Simulation
        sim_result = self._run_simulation(module_name, rtl_code, tb_code)
        results['sim_passed'] = sim_result['passed']
        results['errors'].extend(sim_result['errors'])
        results['warnings'].extend(sim_result['warnings'])
        
        if not sim_result['passed']:
            self.logger.error("Simulation failed")
            return results
        
        self.logger.info("Simulation passed")
        
        # Both passed
        results['passed'] = True
        return results
    
    def _run_lint(self, module_name: str, rtl_code: str) -> Dict[str, Any]:
        """
        Run Verilator lint check
        
        Returns:
            Dict with 'passed', 'errors', 'warnings'
        """
        self.logger.info("Running Verilator lint check")
        
        result = {
            'passed': False,
            'errors': [],
            'warnings': []
        }
        
        # Create temporary file for RTL
        with tempfile.NamedTemporaryFile(mode='w', suffix='.v', 
                                        delete=False) as f:
            f.write(rtl_code)
            rtl_file = f.name
        
        try:
            # Run Verilator
            cmd = [
                self.verilator_path,
                '--lint-only',
                '-Wall',
                rtl_file
            ]
            
            self.logger.debug(f"Lint command: {' '.join(cmd)}")
            
            proc = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=30
            )
            
            # Parse output
            output = proc.stdout + proc.stderr
            
            # Extract errors and warnings
            for line in output.split('\n'):
                if '%Error' in line:
                    result['errors'].append(line.strip())
                elif '%Warning' in line:
                    result['warnings'].append(line.strip())
            
            # Check if passed (return code 0 and no errors)
            result['passed'] = (proc.returncode == 0 and len(result['errors']) == 0)
            
            # Log results
            if result['errors']:
                self.logger.warning(f"Lint errors found: {len(result['errors'])}")
                for err in result['errors'][:5]:  # Show first 5
                    self.logger.warning(f"  {err}")
            
            if result['warnings']:
                self.logger.info(f"Lint warnings: {len(result['warnings'])}")
            
        except subprocess.TimeoutExpired:
            result['errors'].append("Lint check timed out")
            self.logger.error("Lint check timed out")
        except Exception as e:
            result['errors'].append(f"Lint check failed: {str(e)}")
            self.logger.error(f"Lint check exception: {e}")
        finally:
            # Cleanup
            try:
                os.unlink(rtl_file)
            except:
                pass
        
        return result
    
    def _run_simulation(self, module_name: str, 
                       rtl_code: str, tb_code: str) -> Dict[str, Any]:
        """
        Run Icarus Verilog simulation
        
        Returns:
            Dict with 'passed', 'errors', 'warnings'
        """
        self.logger.info("Running simulation")
        
        result = {
            'passed': False,
            'errors': [],
            'warnings': []
        }
        
        # Create temporary files
        with tempfile.NamedTemporaryFile(mode='w', suffix='.v', 
                                        delete=False) as f:
            f.write(rtl_code)
            rtl_file = f.name
        
        with tempfile.NamedTemporaryFile(mode='w', suffix='.v', 
                                        delete=False) as f:
            f.write(tb_code)
            tb_file = f.name
        
        # Output files
        vvp_file = self.sim_dir / f"{module_name}.vvp"
        vcd_file = self.sim_dir / f"{module_name}.vcd"
        log_file = self.sim_dir / f"{module_name}.log"
        
        try:
            # Step 1: Compile with iverilog
            compile_cmd = [
                self.iverilog_path,
                '-o', str(vvp_file),
                rtl_file,
                tb_file
            ]
            
            self.logger.debug(f"Compile command: {' '.join(compile_cmd)}")
            
            proc = subprocess.run(
                compile_cmd,
                capture_output=True,
                text=True,
                timeout=30
            )
            
            if proc.returncode != 0:
                result['errors'].append(f"Compilation failed: {proc.stderr}")
                self.logger.error("Compilation failed")
                return result
            
            # Step 2: Run simulation with vvp
            run_cmd = ['vvp', str(vvp_file)]
            
            self.logger.debug(f"Simulation command: {' '.join(run_cmd)}")
            
            proc = subprocess.run(
                run_cmd,
                capture_output=True,
                text=True,
                timeout=60
            )
            
            # Save output log
            with open(log_file, 'w') as f:
                f.write(proc.stdout)
                f.write(proc.stderr)
            
            # Parse simulation output
            output = proc.stdout + proc.stderr
            
            # Look for common error patterns
            error_patterns = [
                r'ERROR',
                r'FAILED',
                r'FAIL:',
                r'\$fatal',
                r'assertion.*failed'
            ]
            
            for pattern in error_patterns:
                matches = re.findall(pattern, output, re.IGNORECASE)
                if matches:
                    result['errors'].append(f"Simulation error: {pattern}")
            
            # Look for success indicators
            success_patterns = [
                r'PASSED',
                r'SUCCESS',
                r'All tests passed',
                r'\d+/\d+ tests passed'
            ]
            
            has_success = any(
                re.search(pattern, output, re.IGNORECASE) 
                for pattern in success_patterns
            )
            
            # Determine pass/fail
            if proc.returncode == 0 and not result['errors']:
                result['passed'] = True
                self.logger.info("Simulation completed successfully")
            elif has_success and not result['errors']:
                result['passed'] = True
                self.logger.info("Simulation passed (success pattern found)")
            else:
                if proc.returncode != 0:
                    result['errors'].append(f"Simulation exited with code {proc.returncode}")
                self.logger.warning("Simulation completed with issues")
            
            # Save VCD location
            if vcd_file.exists():
                self.logger.info(f"Waveform saved to: {vcd_file}")
            
        except subprocess.TimeoutExpired:
            result['errors'].append("Simulation timed out")
            self.logger.error("Simulation timed out")
        except Exception as e:
            result['errors'].append(f"Simulation failed: {str(e)}")
            self.logger.error(f"Simulation exception: {e}")
        finally:
            # Cleanup temporary files
            try:
                os.unlink(rtl_file)
                os.unlink(tb_file)
            except:
                pass
        
        return result
    
    def check_functionality(self, log_file: Path, 
                          expected_results: List[str]) -> bool:
        """
        Check if simulation output matches expected results
        
        Args:
            log_file: Path to simulation log
            expected_results: List of expected output strings
        
        Returns:
            True if all expected results found
        """
        if not log_file.exists():
            return False
        
        with open(log_file, 'r') as f:
            log_content = f.read()
        
        for expected in expected_results:
            if expected not in log_content:
                self.logger.warning(f"Expected result not found: {expected}")
                return False
        
        return True