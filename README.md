# strufa

StruPHy but fast. A collection of Finite Element (FE) solvers for equations and [GEMPIC](https://doi.org/10.1017/S002237781700040X) solvers for kinetic models.

## Dependencies

The [json library by nlohmann](https://github.com/nlohmann/json) and the [hdf5 library "highfive"](https://github.com/highfive-devs/highfive?tab=readme-ov-file) are dependencies and must be located in `include/`.


## Build & Run

```
mkdir build
cd build
cmake ..
make
./strufa path/to/input
```
where the `path/to/input` is a mandatory input and is taken relative to the top-level path of the project. An output folder name can be provided by `-o output_folder_name` which will be created in the `out/` folder at the top-level path of the project.

## Input Files

For kinetic models using delta-f, direct delta-f, or control variate, the input file must contain either the top-level keyword "background" or "scenario".


## (Planned) Implementations

- [x] Phase-Space Advection
- [ ] Poisson
- [ ] Vlasov-Poisson
- [ ] Vlasov-Ampère
- [ ] Vlasov-Maxwell
- [ ] Vlasov-Ampère with control-variate method
- [ ] Vlasov-Maxwell with control-variate method
- [ ] Linearized Vlasov-Ampère with direct-delta-f method
- [ ] Linearized Vlasov-Maxwell with direct-delta-f method
- [ ] Geometric Linearized Vlasov-Ampère (delta-f)
- [ ] Geometric Linearized Vlasov-Maxwell (delta-f)
- [ ] Geometric Vlasov-Ampère (delta-f)
- [ ] Geometric Vlasov-Maxwell (delta-f)

All models are (will be) implemented in all possible dimensions, i.e. in 1D, 2D, and 3D for models without velocity space, and 1D1V, 1D2V, 1D3V, 2D2V, 2D3V, 3D3V for kinetic models. All kinetice models are single-species only.

FE discretization is on a single, uniform grid.


## Templating

Names of template typenames shall always start with a capital "T". Templated structs are in the order
```template <typename TModel, typename TDimensions, typename TType>```
where `TType` can be, e.g., the type of particles.


## Running with OpenMP and OpenMPI

Run the code with MPI by using `mpirun -np 2 ./src/strufa` and set the number of OpenMP threads via `OMP_NUM_THREADS=4 ./src/strufa` for a single run or `export OMP_NUM_THREADS=4` for a change in

For now, only OpenMP parallelization is implemented. On Mac, if cmake fails due to missing Open_MP_C_FLAGS, try `export OpenMP_ROOT=$(brew --prefix libomp)` in your terminal and then cmake again.
