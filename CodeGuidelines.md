# How to handle input files?

- input files **must** contain 'model', 'space_dimension', and 'domain'.
- input files for kinetic models **must** contain 'velocity_dimensions', 'time', 'PIC'
- missing necessary keys are not tolerated: std::exit. Use optional and then error handling in a separate function (ChatGPT said so)
- 
- TODO: write input-file generator

**Parameters** are just parameters of the simulation (model name, dimensions, discretization details), NOT initial condition. Initial conditions are different objects, handled separaterly.


# Data Location

- Classes only carry their own data, no initial parameters or else. These must be passed to the functions separately


# Handling different types

- different classes that exhibit the same behaviour, and functions that call them should be handled using std::variant and std::visit (in the type-agnostic function)
    -> Do not use dynamic polymorphism
