SIM_EXE = sim.out
SRC_RTL = $(wildcard ../rtl/*.sv)
SRC_TB  = $(wildcard ../tb/*.sv)

run: build
	@echo "Running simulation..."
	@./build/$(SIM_EXE) > sim.log && echo "✅ Simulation Passed"

build:
	@mkdir -p build
	verilator --cc --exe --build -Wall --trace $(SRC_RTL) $(SRC_TB) -o build/$(SIM_EXE)

lint:
	verilator --lint-only $(SRC_RTL)

clean:
	rm -rf build sim.log obj_dir
