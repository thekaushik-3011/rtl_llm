#!/usr/bin/env python3
"""
RTL Generation Pipeline - Main Orchestrator
Coordinates the entire flow from specification to verified RTL
"""

import os
import sys
import json
import yaml
import logging
from pathlib import Path
from typing import Dict, Any, Optional
from datetime import datetime
import click
from rich.console import Console
from rich.table import Table
from rich.progress import Progress, SpinnerColumn, TextColumn
from dotenv import load_dotenv

# Import project modules
from spec_parser import SpecificationParser
from rtl_generator import RTLGenerator
from testbench_generator import TestbenchGenerator
from verifier import RTLVerifier
from synthesizer import RTLSynthesizer
from utils import setup_logging, save_output, load_config

# Load environment variables
load_dotenv()

# Initialize console for rich output
console = Console()

class RTLPipeline:
    """Main pipeline orchestrator for RTL generation"""
    
    def __init__(self, config_path: str = "config/config.yaml"):
        """Initialize the pipeline with configuration"""
        self.config = load_config(config_path)
        self.logger = setup_logging(self.config.get('log_level', 'INFO'))
        
        # Initialize components
        self.spec_parser = SpecificationParser(self.config)
        self.rtl_generator = RTLGenerator(self.config)
        self.tb_generator = TestbenchGenerator(self.config)
        self.verifier = RTLVerifier(self.config)
        self.synthesizer = RTLSynthesizer(self.config)
        
        # Create output directory
        self.output_dir = Path(self.config.get('output_dir', 'output'))
        self.output_dir.mkdir(parents=True, exist_ok=True)
        
        # Results storage
        self.results = {
            'timestamp': datetime.now().isoformat(),
            'stages': {},
            'metrics': {}
        }
    
    def run(self, spec_path: str, iterations: int = 3) -> Dict[str, Any]:
        """
        Run the complete RTL generation pipeline
        
        Args:
            spec_path: Path to specification file (JSON/YAML/TXT)
            iterations: Maximum number of refinement iterations
        
        Returns:
            Dictionary containing results and metrics
        """
        console.print("\n[bold cyan]RTL Generation Pipeline Started[/bold cyan]\n")
        
        with Progress(
            SpinnerColumn(),
            TextColumn("[progress.description]{task.description}"),
            console=console
        ) as progress:
            
            # Stage 1: Parse Specification
            task1 = progress.add_task("[cyan]Parsing specification...", total=None)
            spec_data = self._parse_specification(spec_path)
            progress.update(task1, completed=True)
            console.print("[green]✓[/green] Specification parsed successfully\n")
            
            # Stage 2: Generate RTL
            task2 = progress.add_task("[cyan]Generating RTL...", total=None)
            rtl_code = self._generate_rtl(spec_data)
            progress.update(task2, completed=True)
            console.print("[green]✓[/green] RTL generated\n")
            
            # Stage 3: Generate Testbench
            task3 = progress.add_task("[cyan]Generating testbench...", total=None)
            tb_code = self._generate_testbench(spec_data, rtl_code)
            progress.update(task3, completed=True)
            console.print("[green]✓[/green] Testbench generated\n")
            
            # Stage 4: Verify and Refine
            task4 = progress.add_task("[cyan]Verifying RTL...", total=None)
            verified_rtl = self._verify_and_refine(
                spec_data, rtl_code, tb_code, iterations
            )
            progress.update(task4, completed=True)
            console.print("[green]✓[/green] Verification complete\n")
            
            # Stage 5: Synthesize
            task5 = progress.add_task("[cyan]Synthesizing design...", total=None)
            synth_results = self._synthesize(spec_data, verified_rtl)
            progress.update(task5, completed=True)
            console.print("[green]✓[/green] Synthesis complete\n")
        
        # Generate final report
        self._generate_report()
        
        console.print("\n[bold green]Pipeline completed successfully![/bold green]\n")
        return self.results
    
    def _parse_specification(self, spec_path: str) -> Dict[str, Any]:
        """Parse input specification"""
        self.logger.info(f"Parsing specification from {spec_path}")
        
        try:
            spec_data = self.spec_parser.parse(spec_path)
            self.results['stages']['parsing'] = {
                'status': 'success',
                'module_name': spec_data.get('module'),
                'spec_path': spec_path
            }
            return spec_data
        except Exception as e:
            self.logger.error(f"Specification parsing failed: {e}")
            self.results['stages']['parsing'] = {
                'status': 'failed',
                'error': str(e)
            }
            raise
    
    def _generate_rtl(self, spec_data: Dict[str, Any]) -> str:
        """Generate RTL from specification"""
        self.logger.info("Generating RTL")
        
        try:
            rtl_code = self.rtl_generator.generate(spec_data)
            
            # Save RTL
            module_name = spec_data.get('module', 'design')
            rtl_path = self.output_dir / 'generated_rtl' / f"{module_name}.v"
            rtl_path.parent.mkdir(parents=True, exist_ok=True)
            save_output(rtl_path, rtl_code)
            
            self.results['stages']['rtl_generation'] = {
                'status': 'success',
                'output_path': str(rtl_path),
                'lines_of_code': len(rtl_code.split('\n'))
            }
            
            return rtl_code
        except Exception as e:
            self.logger.error(f"RTL generation failed: {e}")
            self.results['stages']['rtl_generation'] = {
                'status': 'failed',
                'error': str(e)
            }
            raise
    
    def _generate_testbench(self, spec_data: Dict[str, Any], 
                           rtl_code: str) -> str:
        """Generate testbench"""
        self.logger.info("Generating testbench")
        
        try:
            tb_code = self.tb_generator.generate(spec_data, rtl_code)
            
            # Save testbench
            module_name = spec_data.get('module', 'design')
            tb_path = self.output_dir / 'testbenches' / f"tb_{module_name}.v"
            tb_path.parent.mkdir(parents=True, exist_ok=True)
            save_output(tb_path, tb_code)
            
            self.results['stages']['testbench_generation'] = {
                'status': 'success',
                'output_path': str(tb_path)
            }
            
            return tb_code
        except Exception as e:
            self.logger.error(f"Testbench generation failed: {e}")
            self.results['stages']['testbench_generation'] = {
                'status': 'failed',
                'error': str(e)
            }
            raise
    
    def _verify_and_refine(self, spec_data: Dict[str, Any], 
                          rtl_code: str, tb_code: str, 
                          max_iterations: int) -> str:
        """Verify RTL and refine if needed"""
        self.logger.info("Starting verification")
        
        module_name = spec_data.get('module', 'design')
        current_rtl = rtl_code
        iteration = 0
        
        while iteration < max_iterations:
            self.logger.info(f"Verification iteration {iteration + 1}/{max_iterations}")
            
            # Run verification
            verification_result = self.verifier.verify(
                module_name, current_rtl, tb_code, spec_data
            )
            
            if verification_result['passed']:
                self.logger.info("Verification passed!")
                self.results['stages']['verification'] = {
                    'status': 'success',
                    'iterations': iteration + 1,
                    'lint_passed': verification_result.get('lint_passed', False),
                    'simulation_passed': verification_result.get('sim_passed', False)
                }
                return current_rtl
            
            # If verification failed, try to refine
            self.logger.warning(f"Verification failed: {verification_result.get('errors')}")
            
            if iteration < max_iterations - 1:
                console.print(f"[yellow]⚠[/yellow] Attempting refinement (iteration {iteration + 2})...\n")
                current_rtl = self.rtl_generator.refine(
                    spec_data, current_rtl, verification_result
                )
            
            iteration += 1
        
        # Max iterations reached
        self.results['stages']['verification'] = {
            'status': 'partial',
            'iterations': max_iterations,
            'message': 'Max iterations reached, manual review recommended'
        }
        
        return current_rtl
    
    def _synthesize(self, spec_data: Dict[str, Any], rtl_code: str) -> Dict[str, Any]:
        """Synthesize the RTL"""
        self.logger.info("Running synthesis")
        
        try:
            synth_results = self.synthesizer.synthesize(
                spec_data.get('module', 'design'), rtl_code
            )
            
            self.results['stages']['synthesis'] = {
                'status': 'success',
                'gate_count': synth_results.get('gate_count'),
                'cell_count': synth_results.get('cell_count')
            }
            
            self.results['metrics'] = synth_results.get('metrics', {})
            
            return synth_results
        except Exception as e:
            self.logger.error(f"Synthesis failed: {e}")
            self.results['stages']['synthesis'] = {
                'status': 'failed',
                'error': str(e)
            }
            return {}
    
    def _generate_report(self):
        """Generate final summary report"""
        report_path = self.output_dir / 'pipeline_report.json'
        save_output(report_path, json.dumps(self.results, indent=2))
        
        # Display summary table
        table = Table(title="Pipeline Results Summary")
        table.add_column("Stage", style="cyan")
        table.add_column("Status", style="green")
        table.add_column("Details", style="yellow")
        
        for stage_name, stage_data in self.results['stages'].items():
            status = stage_data.get('status', 'unknown')
            details = stage_data.get('output_path', 
                     stage_data.get('iterations', 
                     stage_data.get('message', '-')))
            
            status_emoji = {
                'success': '✓',
                'failed': '✗',
                'partial': '⚠'
            }.get(status, '?')
            
            table.add_row(
                stage_name.replace('_', ' ').title(),
                f"{status_emoji} {status}",
                str(details)
            )
        
        console.print("\n")
        console.print(table)
        console.print(f"\n[cyan]Full report saved to:[/cyan] {report_path}\n")


@click.command()
@click.option('--spec', '-s', required=True, help='Path to specification file')
@click.option('--config', '-c', default='config/config.yaml', 
              help='Path to configuration file')
@click.option('--iterations', '-i', default=3, help='Max refinement iterations')
@click.option('--verbose', '-v', is_flag=True, help='Enable verbose logging')
def main(spec: str, config: str, iterations: int, verbose: bool):
    """RTL Generation Pipeline - Generate Verilog from natural language specs"""
    
    # Override log level if verbose
    if verbose:
        os.environ['LOG_LEVEL'] = 'DEBUG'
    
    try:
        # Initialize and run pipeline
        pipeline = RTLPipeline(config)
        results = pipeline.run(spec, iterations)
        
        # Exit with success
        sys.exit(0)
        
    except KeyboardInterrupt:
        console.print("\n[red]Pipeline interrupted by user[/red]")
        sys.exit(1)
    except Exception as e:
        console.print(f"\n[red]Pipeline failed: {e}[/red]")
        if verbose:
            import traceback
            traceback.print_exc()
        sys.exit(1)


if __name__ == "__main__":
    main()