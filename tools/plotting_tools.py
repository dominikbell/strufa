import argparse

from plot_particles import plot_distribution_function


def main():
  parser = argparse.ArgumentParser(description="Plotting tools for StruFa")
  parser.add_argument("foldername", type=str)
  parser.add_argument("--save_fig", action="store_true", help="Save the figure instead of showing it.")
  subparsers = parser.add_subparsers(dest="command", help="Available commands")

  # Parser for plotting particles
  particles_parser = subparsers.add_parser("particles", help="Plot the distribution function or create a video.")
  particles_parser.add_argument("--plot", type=str, default="positions")
  particles_parser.set_defaults(func=plot_distribution_function)

  args = parser.parse_args()
  # Check if script is being run from the build folder or the top-level path
  if "build" in __file__.split("/"):
    foldername = "../out/" + args.foldername
  else:
    foldername = "out/" + args.foldername
  save_fig = args.save_fig

  # Route to the appropriate function
  if hasattr(args, "func"):
    args.func(foldername, save_fig, args)
  else:
    parser.print_help()

if __name__ == "__main__":
  main()
