"""
RTL Synthesizer
Uses Yosys to synthesize and analyze RTL designs
"""

import os
import subprocess
import tempfile
import logging
import re
from pathlib import Path
from typing import Dict, Any


class RTLSynthesizer:
    """Synthesize and analyze RTL designs"""
    
    def __init__(self, config: Dict[str, Any]):
        self.config = config
        self.logger = logging.getLogger(__name__)
        
        # Tool path
        self.yosys_path = os.getenv('YOSYS_PATH', 'yosys')
        
        # Output directory
        self.synth_dir = Path(config.get('output_dir', 'output')) / 'synthesis_reports'
        self.synth_dir.mkdir(parents=True, exist_ok=True)
    
    def synthesize(self, module_name: str, rtl_code: str) -> Dict[str, Any]:
        """
        Synthesize RTL and extract metrics
        
        Args:
            module_name: Name of module
            rtl_code: Verilog RTL code
        
        Returns:
            Synthesis results with metrics
        """
        self.logger.info(f"Synthesizing module: {module_name}")
        
        results = {
            'success': False,
            'gate_count': 0,
            'cell_count': 0,
            'metrics': {},
            'errors': []
        }
        
        # Create temporary RTL file
        with tempfile.NamedTemporaryFile(mode='w', suffix='.v', 
                                        delete=False) as f:
            f.write(rtl_code)
            rtl_file = f.name
        
        # Create Yosys script
        script_content = self._generate_yosys_script(module_name, rtl_file)
        
        with tempfile.NamedTemporaryFile(mode='w', suffix='.ys', 
                                        delete=False) as f:
            f.write(script_content)
            script_file = f.name
        
        # Output files
        log_file = self.synth_dir / f"{module_name}_synth.log"
        stat_file = self.synth_dir / f"{module_name}_stat.txt"
        
        try:
            # Run Yosys
            cmd = [self.yosys_path, '-s', script_file]
            
            self.logger.debug(f"Synthesis command: {' '.join(cmd)}")
            
            proc = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=60
            )
            
            # Save log
            output = proc.stdout + proc.stderr
            with open(log_file, 'w') as f:
                f.write(output)
            
            # Parse results
            if proc.returncode == 0:
                results['success'] = True
                results['metrics'] = self._parse_synthesis_output(output)
                results['gate_count'] = results['metrics'].get('total_cells', 0)
                results['cell_count'] = results['metrics'].get('total_cells', 0)
                
                self.logger.info(f"Synthesis successful: {results['gate_count']} gates")
            else:
                results['errors'].append(f"Synthesis failed with code {proc.returncode}")
                # Try to extract error messages
                error_lines = [line for line in output.split('\n') 
                              if 'ERROR' in line.upper()]
                results['errors'].extend(error_lines[:5])
                
                self.logger.error("Synthesis failed")
        
        except subprocess.TimeoutExpired:
            results['errors'].append("Synthesis timed out")
            self.logger.error("Synthesis timed out")
        except Exception as e:
            results['errors'].append(f"Synthesis exception: {str(e)}")
            self.logger.error(f"Synthesis exception: {e}")
        finally:
            # Cleanup
            try:
                os.unlink(rtl_file)
                os.unlink(script_file)
            except:
                pass
        
        return results
    
    def _generate_yosys_script(self, module_name: str, rtl_file: str) -> str:
        """Generate Yosys synthesis script"""
        
        script = f"""# Yosys synthesis script for {module_name}

# Read design
read_verilog {rtl_file}

# Elaborate design
hierarchy -check -top {module_name}

# Optimization passes
proc
opt
fsm
opt
memory
opt

# Technology mapping (generic)
techmap
opt

# Print statistics
stat

# Check design
check

# Clean up
clean
"""
        return script
    
    def _parse_synthesis_output(self, output: str) -> Dict[str, Any]:
        """
        Parse Yosys output to extract metrics
        
        Returns:
            Dictionary of synthesis metrics
        """
        metrics = {
            'total_cells': 0,
            'total_wires': 0,
            'total_area': 0,
            'cell_types': {}
        }
        
        # Look for statistics section
        stat_section = False
        
        for line in output.split('\n'):
            line = line.strip()
            
            # Detect statistics section
            if 'Number of cells:' in line or 'Printing statistics' in line:
                stat_section = True
                continue
            
            if not stat_section:
                continue
            
            # Parse cell counts
            # Example: "  $_AND_     15"
            cell_match = re.match(r'\s*(\$?\w+)\s+(\d+)', line)
            if cell_match:
                cell_type = cell_match.group(1)
                count = int(cell_match.group(2))
                metrics['cell_types'][cell_type] = count
                metrics['total_cells'] += count
            
            # Parse wire counts
            if 'Number of wires:' in line:
                wire_match = re.search(r'(\d+)', line)
                if wire_match:
                    metrics['total_wires'] = int(wire_match.group(1))
            
            # Parse area if available
            if 'Chip area' in line or 'Area' in line:
                area_match = re.search(r'(\d+\.?\d*)', line)
                if area_match:
                    metrics['total_area'] = float(area_match.group(1))
        
        # Calculate derived metrics
        if metrics['total_cells'] > 0:
            # Count logic gates (AND, OR, NOT, XOR, etc.)
            logic_gates = sum(
                count for cell_type, count in metrics['cell_types'].items()
                if any(gate in cell_type.upper() 
                      for gate in ['AND', 'OR', 'NOT', 'XOR', 'NAND', 'NOR'])
            )
            metrics['logic_gates'] = logic_gates
            
            # Count flip-flops
            flip_flops = sum(
                count for cell_type, count in metrics['cell_types'].items()
                if 'DFF' in cell_type.upper() or 'DFFE' in cell_type.upper()
            )
            metrics['flip_flops'] = flip_flops
            
            # Count multiplexers
            muxes = sum(
                count for cell_type, count in metrics['cell_types'].items()
                if 'MUX' in cell_type.upper()
            )
            metrics['muxes'] = muxes
        
        return metrics
    
    def estimate_area_timing(self, metrics: Dict[str, Any]) -> Dict[str, Any]:
        """
        Estimate area and timing (rough approximations)
        
        Args:
            metrics: Synthesis metrics
        
        Returns:
            Estimated area and timing
        """
        estimates = {}
        
        # Rough area estimation (in equivalent gates)
        logic_gates = metrics.get('logic_gates', 0)
        flip_flops = metrics.get('flip_flops', 0)
        muxes = metrics.get('muxes', 0)
        
        # Weights (relative to 2-input NAND gate)
        gate_weight = 1.0
        ff_weight = 6.0  # Flip-flop ≈ 6 gates
        mux_weight = 3.0  # 2:1 MUX ≈ 3 gates
        
        total_area = (
            logic_gates * gate_weight +
            flip_flops * ff_weight +
            muxes * mux_weight
        )
        
        estimates['estimated_area_gates'] = int(total_area)
        
        # Rough timing estimation (critical path depth)
        # This is very approximate
        if flip_flops > 0:
            # Sequential design: estimate based on logic depth
            logic_depth = max(1, int(logic_gates / max(1, flip_flops)))
            estimates['estimated_logic_depth'] = logic_depth
            estimates['estimated_max_freq_mhz'] = int(1000 / (logic_depth * 0.5 + 1))
        else:
            # Combinational design
            logic_depth = max(1, int(logic_gates ** 0.5))
            estimates['estimated_logic_depth'] = logic_depth
            estimates['estimated_delay_ns'] = logic_depth * 0.3
        
        return estimates
    
    def generate_synthesis_report(self, module_name: str, 
                                 results: Dict[str, Any]) -> str:
        """
        Generate human-readable synthesis report
        
        Returns:
            Path to report file
        """
        report_file = self.synth_dir / f"{module_name}_report.txt"
        
        metrics = results.get('metrics', {})
        estimates = self.estimate_area_timing(metrics)
        
        report = f"""
╔══════════════════════════════════════════════════════════════╗
║         SYNTHESIS REPORT - {module_name.upper()}                      
╚══════════════════════════════════════════════════════════════╝

Status: {'SUCCESS' if results.get('success') else 'FAILED'}

═══════════════════════════════════════════════════════════════
RESOURCE UTILIZATION
═══════════════════════════════════════════════════════════════
Total Cells:        {metrics.get('total_cells', 0)}
Logic Gates:        {metrics.get('logic_gates', 0)}
Flip-Flops:         {metrics.get('flip_flops', 0)}
Multiplexers:       {metrics.get('muxes', 0)}
Total Wires:        {metrics.get('total_wires', 0)}

═══════════════════════════════════════════════════════════════
CELL BREAKDOWN
═══════════════════════════════════════════════════════════════
"""
        
        # Add cell type breakdown
        cell_types = metrics.get('cell_types', {})
        for cell_type, count in sorted(cell_types.items(), 
                                      key=lambda x: x[1], reverse=True):
            report += f"{cell_type:20s}: {count:6d}\n"
        
        report += f"""
═══════════════════════════════════════════════════════════════
ESTIMATES
═══════════════════════════════════════════════════════════════
Area (equiv gates): {estimates.get('estimated_area_gates', 0)}
Logic Depth:        {estimates.get('estimated_logic_depth', 'N/A')}
"""
        
        if 'estimated_max_freq_mhz' in estimates:
            report += f"Max Freq (est):     {estimates['estimated_max_freq_mhz']} MHz\n"
        if 'estimated_delay_ns' in estimates:
            report += f"Delay (est):        {estimates['estimated_delay_ns']:.2f} ns\n"
        
        if results.get('errors'):
            report += "\n═══════════════════════════════════════════════════════════════\n"
            report += "ERRORS\n"
            report += "═══════════════════════════════════════════════════════════════\n"
            for error in results['errors']:
                report += f"  • {error}\n"
        
        report += "\n╚══════════════════════════════════════════════════════════════╝\n"
        
        with open(report_file, 'w') as f:
            f.write(report)
        
        self.logger.info(f"Synthesis report saved to: {report_file}")
        
        return str(report_file)