# Goals and TODOs

Collect the goals and TODOs here.

## Near-term Goals

- [ ] Implement FEEC
  - [x] Grid points, knots, grevilles points, find span
  - [x] Evaluate spline at points
  - [ ] Projectors: histopolator and collocator
  - [ ] Spline histopolation and collocation matrices
  - [ ] Matrix-free gradient, curl, divergence
  - [ ] Matrix-free mass operators
  - [ ] Matrix-free matrix inverse
  - [ ] Evaluate FE functions at a point / on a grid
  - [ ] Precompile coefficients for eval_spline with given MAX_DEGREE and use them during run-time
- [ ] Put models in their own folders with READMEs
- [ ] Implement scenarios
- [ ] Add tests

## Long-term Goals

- [ ] Parallelize FE with MPI
- [ ] Write a parameter file generator

## Smaller Things

- [ ] replace `call_function` in sine and cosine with variads.
