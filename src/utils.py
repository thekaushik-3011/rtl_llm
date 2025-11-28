"""
Utility Functions
Common helpers for the RTL generation pipeline
"""

import os
import yaml
import logging
from pathlib import Path
from typing import Dict, Any
from datetime import datetime


def setup_logging(log_level: str = 'INFO') -> logging.Logger:
    """
    Setup logging configuration
    
    Args:
        log_level: Logging level (DEBUG, INFO, WARNING, ERROR)
    
    Returns:
        Configured logger
    """
    # Create logs directory
    log_dir = Path('logs')
    log_dir.mkdir(exist_ok=True)
    
    # Generate log filename with timestamp
    timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
    log_file = log_dir / f'rtl_pipeline_{timestamp}.log'
    
    # Configure logging
    logging.basicConfig(
        level=getattr(logging, log_level.upper()),
        format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
        handlers=[
            logging.FileHandler(log_file),
            logging.StreamHandler()
        ]
    )
    
    logger = logging.getLogger('RTLPipeline')
    logger.info(f"Logging initialized: {log_file}")
    
    return logger


def load_config(config_path: str = 'config/config.yaml') -> Dict[str, Any]:
    """
    Load configuration from YAML file
    
    Args:
        config_path: Path to config file
    
    Returns:
        Configuration dictionary
    """
    config_file = Path(config_path)
    
    # Default configuration
    default_config = {
        'output_dir': 'output',
        'data_dir': 'data',
        'log_level': 'INFO',
        'max_iterations': 3,
        'llm': {
            'model': 'gpt-4',
            'temperature': 0.2,
            'max_tokens': 2000
        },
        'tools': {
            'verilator': '/usr/bin/verilator',
            'yosys': '/usr/bin/yosys',
            'iverilog': '/usr/bin/iverilog'
        }
    }
    
    # Load config file if exists
    if config_file.exists():
        with open(config_file, 'r') as f:
            user_config = yaml.safe_load(f)
            if user_config:
                default_config.update(user_config)
    else:
        # Create default config file
        config_file.parent.mkdir(parents=True, exist_ok=True)
        with open(config_file, 'w') as f:
            yaml.dump(default_config, f, default_flow_style=False)
    
    return default_config


def save_output(file_path: Path, content: str):
    """
    Save content to file
    
    Args:
        file_path: Output file path
        content: Content to save
    """
    file_path.parent.mkdir(parents=True, exist_ok=True)
    
    with open(file_path, 'w') as f:
        f.write(content)


def read_file(file_path: str) -> str:
    """
    Read content from file
    
    Args:
        file_path: Input file path
    
    Returns:
        File content
    """
    with open(file_path, 'r') as f:
        return f.read()


def format_verilog(code: str) -> str:
    """
    Basic Verilog code formatting
    
    Args:
        code: Verilog code
    
    Returns:
        Formatted code
    """
    lines = code.split('\n')
    formatted = []
    indent_level = 0
    indent_size = 2
    
    for line in lines:
        stripped = line.strip()
        
        # Decrease indent for closing keywords
        if any(stripped.startswith(kw) for kw in ['end', 'endmodule', 'endfunction', 'endtask']):
            indent_level = max(0, indent_level - 1)
        
        # Add indented line
        if stripped:
            formatted.append(' ' * (indent_level * indent_size) + stripped)
        else:
            formatted.append('')
        
        # Increase indent for opening keywords
        if any(stripped.startswith(kw) for kw in ['module', 'function', 'task', 'begin']):
            indent_level += 1
        
        # Handle always blocks
        if 'always' in stripped and stripped.endswith('begin'):
            indent_level += 1
        elif stripped == 'end':
            indent_level = max(0, indent_level - 1)
    
    return '\n'.join(formatted)


def extract_module_info(verilog_code: str) -> Dict[str, Any]:
    """
    Extract basic information from Verilog code
    
    Args:
        verilog_code: Verilog code
    
    Returns:
        Dictionary with module information
    """
    import re
    
    info = {
        'module_name': None,
        'inputs': [],
        'outputs': [],
        'parameters': []
    }
    
    # Extract module name
    module_match = re.search(r'module\s+(\w+)', verilog_code)
    if module_match:
        info['module_name'] = module_match.group(1)
    
    # Extract inputs
    input_matches = re.finditer(r'input\s+(?:\[.*?\]\s+)?(\w+)', verilog_code)
    info['inputs'] = [m.group(1) for m in input_matches]
    
    # Extract outputs
    output_matches = re.finditer(r'output\s+(?:\[.*?\]\s+)?(\w+)', verilog_code)
    info['outputs'] = [m.group(1) for m in output_matches]
    
    # Extract parameters
    param_matches = re.finditer(r'parameter\s+(\w+)\s*=\s*([^;]+)', verilog_code)
    info['parameters'] = [(m.group(1), m.group(2).strip()) for m in param_matches]
    
    return info


def create_example_specs():
    """Create example specification files"""
    
    examples_dir = Path('data/specs/simple')
    examples_dir.mkdir(parents=True, exist_ok=True)
    
    # Example 1: Counter
    counter_spec = {
        'module': 'counter',
        'description': '8-bit up counter with synchronous reset and enable',
        'timing': 'sequential',
        'inputs': [
            {'name': 'clk', 'width': 1, 'description': 'Clock signal'},
            {'name': 'rst', 'width': 1, 'description': 'Synchronous reset'},
            {'name': 'enable', 'width': 1, 'description': 'Count enable'}
        ],
        'outputs': [
            {'name': 'count', 'width': 8, 'description': 'Counter value'}
        ]
    }
    
    with open(examples_dir / 'counter.json', 'w') as f:
        import json
        json.dump(counter_spec, f, indent=2)
    
    # Example 2: ALU
    alu_spec = {
        'module': 'alu',
        'description': '8-bit ALU with arithmetic and logic operations',
        'timing': 'combinational',
        'inputs': [
            {'name': 'a', 'width': 8, 'description': 'Operand A'},
            {'name': 'b', 'width': 8, 'description': 'Operand B'},
            {'name': 'opcode', 'width': 3, 'description': 'Operation select'}
        ],
        'outputs': [
            {'name': 'result', 'width': 8, 'description': 'Operation result'},
            {'name': 'zero', 'width': 1, 'description': 'Zero flag'}
        ],
        'operations': ['ADD', 'SUB', 'AND', 'OR', 'XOR']
    }
    
    with open(examples_dir / 'alu.json', 'w') as f:
        import json
        json.dump(alu_spec, f, indent=2)
    
    # Example 3: Register File
    regfile_spec = {
        'module': 'register_file',
        'description': '8-register file with dual read ports and single write port',
        'timing': 'sequential',
        'inputs': [
            {'name': 'clk', 'width': 1},
            {'name': 'rst', 'width': 1},
            {'name': 'rd_addr1', 'width': 3, 'description': 'Read address 1'},
            {'name': 'rd_addr2', 'width': 3, 'description': 'Read address 2'},
            {'name': 'wr_addr', 'width': 3, 'description': 'Write address'},
            {'name': 'wr_data', 'width': 8, 'description': 'Write data'},
            {'name': 'wr_enable', 'width': 1, 'description': 'Write enable'}
        ],
        'outputs': [
            {'name': 'rd_data1', 'width': 8, 'description': 'Read data 1'},
            {'name': 'rd_data2', 'width': 8, 'description': 'Read data 2'}
        ]
    }
    
    with open(examples_dir / 'register_file.json', 'w') as f:
        import json
        json.dump(regfile_spec, f, indent=2)
    
    print(f"Example specifications created in {examples_dir}")


def validate_verilog_syntax(code: str) -> tuple[bool, list]:
    """
    Basic Verilog syntax validation
    
    Args:
        code: Verilog code
    
    Returns:
        Tuple of (is_valid, error_list)
    """
    errors = []
    
    # Check for module declaration
    if 'module' not in code:
        errors.append("Missing module declaration")
    
    # Check for matching module/endmodule
    module_count = code.count('module ')
    endmodule_count = code.count('endmodule')
    if module_count != endmodule_count:
        errors.append(f"Mismatched module/endmodule ({module_count}/{endmodule_count})")
    
    # Check for matching begin/end
    begin_count = code.count('begin')
    end_count = code.count(' end') + code.count('\nend') + code.count(';end')
    if begin_count > end_count:
        errors.append(f"Potentially mismatched begin/end ({begin_count}/{end_count})")
    
    # Check for common syntax issues
    if '=#' in code:
        errors.append("Contains delay (#) - not synthesizable")
    
    if '$display' in code or '$monitor' in code:
        errors.append("Contains simulation-only constructs ($display/$monitor)")
    
    return len(errors) == 0, errors


def get_project_stats() -> Dict[str, Any]:
    """Get statistics about generated outputs"""
    
    output_dir = Path('output')
    
    stats = {
        'total_modules': 0,
        'total_testbenches': 0,
        'total_simulations': 0,
        'total_syntheses': 0
    }
    
    # Count generated RTL files
    rtl_dir = output_dir / 'generated_rtl'
    if rtl_dir.exists():
        stats['total_modules'] = len(list(rtl_dir.glob('*.v')))
    
    # Count testbenches
    tb_dir = output_dir / 'testbenches'
    if tb_dir.exists():
        stats['total_testbenches'] = len(list(tb_dir.glob('*.v')))
    
    # Count simulation results
    sim_dir = output_dir / 'simulation_results'
    if sim_dir.exists():
        stats['total_simulations'] = len(list(sim_dir.glob('*.log')))
    
    # Count synthesis reports
    synth_dir = output_dir / 'synthesis_reports'
    if synth_dir.exists():
        stats['total_syntheses'] = len(list(synth_dir.glob('*_report.txt')))
    
    return stats