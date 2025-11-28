"""
Specification Parser
Converts various input formats (JSON, YAML, natural language) into structured spec
"""

import json
import yaml
import re
from pathlib import Path
from typing import Dict, Any, List
import logging


class SpecificationParser:
    """Parse and structure hardware specifications"""
    
    def __init__(self, config: Dict[str, Any]):
        self.config = config
        self.logger = logging.getLogger(__name__)
    
    def parse(self, spec_path: str) -> Dict[str, Any]:
        """
        Parse specification file
        
        Args:
            spec_path: Path to specification file
        
        Returns:
            Structured specification dictionary
        """
        spec_file = Path(spec_path)
        
        if not spec_file.exists():
            raise FileNotFoundError(f"Specification file not found: {spec_path}")
        
        # Determine file type and parse accordingly
        if spec_file.suffix == '.json':
            return self._parse_json(spec_file)
        elif spec_file.suffix in ['.yaml', '.yml']:
            return self._parse_yaml(spec_file)
        elif spec_file.suffix == '.txt':
            return self._parse_natural_language(spec_file)
        else:
            raise ValueError(f"Unsupported file format: {spec_file.suffix}")
    
    def _parse_json(self, spec_file: Path) -> Dict[str, Any]:
        """Parse JSON specification"""
        self.logger.info(f"Parsing JSON spec: {spec_file}")
        
        with open(spec_file, 'r') as f:
            spec_data = json.load(f)
        
        return self._validate_and_normalize(spec_data)
    
    def _parse_yaml(self, spec_file: Path) -> Dict[str, Any]:
        """Parse YAML specification"""
        self.logger.info(f"Parsing YAML spec: {spec_file}")
        
        with open(spec_file, 'r') as f:
            spec_data = yaml.safe_load(f)
        
        return self._validate_and_normalize(spec_data)
    
    def _parse_natural_language(self, spec_file: Path) -> Dict[str, Any]:
        """Parse natural language specification"""
        self.logger.info(f"Parsing natural language spec: {spec_file}")
        
        with open(spec_file, 'r') as f:
            text = f.read()
        
        # Extract structured information from natural language
        spec_data = self._extract_from_text(text)
        
        return self._validate_and_normalize(spec_data)
    
    def _extract_from_text(self, text: str) -> Dict[str, Any]:
        """
        Extract structured data from natural language
        Uses pattern matching and heuristics
        """
        spec_data = {
            'description': text,
            'inputs': [],
            'outputs': [],
            'parameters': []
        }
        
        # Extract module name
        module_match = re.search(r'module\s+(\w+)', text, re.IGNORECASE)
        if module_match:
            spec_data['module'] = module_match.group(1)
        else:
            # Try to infer from common patterns
            if 'counter' in text.lower():
                spec_data['module'] = 'counter'
            elif 'alu' in text.lower():
                spec_data['module'] = 'alu'
            else:
                spec_data['module'] = 'design'
        
        # Extract bit widths
        width_pattern = r'(\d+)[-\s]bit'
        widths = re.findall(width_pattern, text, re.IGNORECASE)
        default_width = int(widths[0]) if widths else 32
        
        # Extract inputs
        input_patterns = [
            r'input[s]?:?\s*([a-zA-Z_,\s]+)',
            r'takes?\s+(?:in\s+)?([a-zA-Z_,\s]+)\s+as\s+input',
        ]
        for pattern in input_patterns:
            matches = re.findall(pattern, text, re.IGNORECASE)
            for match in matches:
                signals = [s.strip() for s in match.split(',')]
                for sig in signals:
                    if sig and sig not in [i['name'] for i in spec_data['inputs']]:
                        spec_data['inputs'].append({
                            'name': sig,
                            'width': default_width
                        })
        
        # Extract outputs
        output_patterns = [
            r'output[s]?:?\s*([a-zA-Z_,\s]+)',
            r'produces?\s+([a-zA-Z_,\s]+)\s+as\s+output',
        ]
        for pattern in output_patterns:
            matches = re.findall(pattern, text, re.IGNORECASE)
            for match in matches:
                signals = [s.strip() for s in match.split(',')]
                for sig in signals:
                    if sig and sig not in [o['name'] for o in spec_data['outputs']]:
                        spec_data['outputs'].append({
                            'name': sig,
                            'width': default_width
                        })
        
        # Determine if sequential or combinational
        sequential_keywords = ['clock', 'clk', 'reset', 'register', 'flip-flop', 'sequential']
        if any(keyword in text.lower() for keyword in sequential_keywords):
            spec_data['timing'] = 'sequential'
            # Add clock and reset if not present
            if not any(i['name'] == 'clk' for i in spec_data['inputs']):
                spec_data['inputs'].insert(0, {'name': 'clk', 'width': 1})
            if not any(i['name'] == 'rst' for i in spec_data['inputs']):
                spec_data['inputs'].insert(1, {'name': 'rst', 'width': 1})
        else:
            spec_data['timing'] = 'combinational'
        
        # Extract operations/functionality
        operations = []
        operation_keywords = {
            'add': 'ADD',
            'subtract': 'SUB',
            'multiply': 'MUL',
            'divide': 'DIV',
            'and': 'AND',
            'or': 'OR',
            'xor': 'XOR',
            'shift': 'SHIFT',
            'rotate': 'ROTATE'
        }
        
        for keyword, op in operation_keywords.items():
            if keyword in text.lower():
                operations.append(op)
        
        if operations:
            spec_data['operations'] = operations
        
        return spec_data
    
    def _validate_and_normalize(self, spec_data: Dict[str, Any]) -> Dict[str, Any]:
        """
        Validate and normalize specification data
        Ensures all required fields are present
        """
        # Required fields
        if 'module' not in spec_data:
            spec_data['module'] = 'design'
        
        if 'description' not in spec_data:
            spec_data['description'] = f"Module: {spec_data['module']}"
        
        # Ensure inputs/outputs lists exist
        if 'inputs' not in spec_data:
            spec_data['inputs'] = []
        
        if 'outputs' not in spec_data:
            spec_data['outputs'] = []
        
        # Normalize port definitions
        spec_data['inputs'] = self._normalize_ports(spec_data['inputs'])
        spec_data['outputs'] = self._normalize_ports(spec_data['outputs'])
        
        # Set default timing if not specified
        if 'timing' not in spec_data:
            # Check if clock/reset signals present
            has_clock = any(
                p['name'].lower() in ['clk', 'clock'] 
                for p in spec_data['inputs']
            )
            spec_data['timing'] = 'sequential' if has_clock else 'combinational'
        
        # Add metadata
        spec_data['metadata'] = {
            'parsed': True,
            'total_inputs': len(spec_data['inputs']),
            'total_outputs': len(spec_data['outputs'])
        }
        
        self.logger.info(f"Spec validated: {spec_data['module']}")
        self.logger.debug(f"Spec data: {json.dumps(spec_data, indent=2)}")
        
        return spec_data
    
    def _normalize_ports(self, ports: List) -> List[Dict[str, Any]]:
        """Normalize port definitions to standard format"""
        normalized = []
        
        for port in ports:
            if isinstance(port, str):
                # Convert string to dict
                normalized.append({
                    'name': port,
                    'width': 1
                })
            elif isinstance(port, dict):
                # Ensure required fields
                if 'name' not in port:
                    continue
                
                normalized.append({
                    'name': port['name'],
                    'width': port.get('width', 1),
                    'description': port.get('description', '')
                })
        
        return normalized
    
    def generate_spec_template(self, output_path: str):
        """Generate a template specification file"""
        template = {
            'module': 'example_module',
            'description': 'Description of what the module does',
            'timing': 'sequential',  # or 'combinational'
            'inputs': [
                {'name': 'clk', 'width': 1, 'description': 'Clock signal'},
                {'name': 'rst', 'width': 1, 'description': 'Reset signal'},
                {'name': 'data_in', 'width': 32, 'description': 'Input data'}
            ],
            'outputs': [
                {'name': 'data_out', 'width': 32, 'description': 'Output data'},
                {'name': 'valid', 'width': 1, 'description': 'Valid signal'}
            ],
            'parameters': [
                {'name': 'WIDTH', 'value': 32, 'description': 'Data width'}
            ],
            'operations': ['ADD', 'SUB', 'AND', 'OR'],
            'constraints': {
                'max_frequency': '100MHz',
                'area': 'minimize'
            }
        }
        
        with open(output_path, 'w') as f:
            json.dump(template, f, indent=2)
        
        self.logger.info(f"Template generated: {output_path}")