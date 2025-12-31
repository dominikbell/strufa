# strufa

StruPHy but fast. A collection of FE solvers for equations and GEMPIC solvers for kinetic models.

## Build & Run

```
mkdir build
cd build
cmake ..
make
./strufa path/to/input
```

## (Planned) Implementations

- [ ] Phase-Space Advection
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

All models should be implemented in all possible dimensions, i.e. in 1D, 2D, and 3D for models without velocity space, and 1D1V, 1D2V, 1D3V, 2D2V, 2D3V, 3D3V for kinetic models.

## Input Files

For kinetic models using delta-f, direct delta-f, or control variate, the input file must contain either the top-level keyword "background" or "scenario".
