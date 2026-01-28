import h5py
import matplotlib.pyplot as plt
import numpy as np


def plot_distribution_function(
  foldername,
  save_fig,
  args):
  filename = foldername + "/particles.h5"
  do_plot = args.plot

  # Make grids for plotting
  n_x = 50
  n_v = 80
  x_grid = np.linspace(0, 1, n_x)
  dx = x_grid[1] - x_grid[0]
  v_grid = np.linspace(-5, 5, n_v)
  dv = v_grid[1] - v_grid[0]

  # Choose the timestep index where to plot
  ind_t = 0

  with h5py.File(filename, "r") as f:
    weights = f["weights"][:]
    positions = f["positions0"][:]
    velocities = f["velocities0"][:]

    n_markers = np.shape(weights)[1]

    # Create histogram from sampled markers
    if do_plot == "phase_space":
      hist, _, _ = np.histogram2d(
        x=positions[ind_t, :],
        y=velocities[ind_t, :],
        bins=[x_grid, v_grid],
        weights=weights[ind_t, :]
      )
      hist /= n_markers
      x_grid_mesh, v_grid_mesh = np.meshgrid(x_grid, v_grid, indexing="ij")

      cmap = "seismic"
      vmin = []
      vmax = []
      vmin += [np.min(hist) / 3]
      vmax += [np.max(hist) / 3]
      vmin = np.min(vmin)
      vmax = np.max(vmax)
      vscale = np.max(np.abs([vmin, vmax]))
      fig, ax = plt.subplots(figsize=(12, 8))
      im = ax.pcolormesh(x_grid_mesh, v_grid_mesh, hist, cmap=cmap, vmin=-vscale, vmax=vscale)

      fig.colorbar(im, ax=ax)
      plt.show()
      exit()
    elif do_plot == "positions":
      hist, _ = np.histogram(
        positions[ind_t, :],
        bins=x_grid,
        weights=weights[ind_t, :]
      )
    elif do_plot == "velocities":
      hist, _ = np.histogram(
        velocities[ind_t, :],
        bins=v_grid
      )
    else:
      print(f"Invalid choice '{do_plot}' for do_plot, exiting..")
      exit()
    hist = np.array(hist, dtype=np.float64)
    hist /= n_markers

    # Plot the results
    if do_plot == "both":
      hist /= dx * dv
      fig = plt.figure(figsize=(15, 8))
      subplot_positions = fig.add_subplot(121)
      subplot_positions.plot(
        x_grid[:-1] + dx/2,
        hist[:, n_v//2]
      )
      subplot_positions.set_xlabel("x")
      subplot_velocities = fig.add_subplot(122)
      subplot_velocities.plot(
        v_grid[:-1] + dv/2,
        hist[0, :]
      )
      subplot_velocities.set_xlabel("v")
    elif do_plot == "positions":
      hist /= dx
      plt.plot(
        x_grid[:-1] + dx/2,
        np.cos(2 * np.pi * x_grid[:-1] + dx/2)
      )
      plt.plot(
        x_grid[:-1] + dx/2,
        hist,
        "r*"
      )
      plt.xlabel("x")
    elif do_plot == "velocities":
      hist /= dv
      plt.plot(
        v_grid[:-1] + dv/2,
        1/np.sqrt(2*np.pi) * \
        np.exp( -(v_grid[:-1] + dv/2)**2 / 2)
      )
      plt.plot(
        v_grid[:-1] + dv/2,
        hist,
        "r*"
      )
      plt.xlabel("v")

    # Save the figure or show it
    if save_fig:
      plt.savefig(foldername + "/particles_" + do_plot + ".png", dpi=400)
    else:
      plt.show()
