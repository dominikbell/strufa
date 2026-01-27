# Goals and TODOs

Collect the goals and TODOs here.

## Near-term Goals

- [ ] Implement FEEC for degree=1
  - [x] Grid points, knots, grevilles points, find span
  - [ ] Projectors: histopolator and collocator
  - [ ] Spline histopolation and collocation matrices
  - [ ] Matrix-free gradient, curl, divergence
  - [ ] Matrix-free mass operators
  - [ ] Matrix-free matrix inverse
  - [ ] Evaluate spline functions

## Long-term Goals

- [ ] Parallelize FE with MPI
- [ ] Have higher-degree splines

## Smaller Things

- [ ] replace `call_function` in sine and cosine with variads.

## Annoying Things

- [ ] Fix the path finding for outputting to the correct folder provided by the user
