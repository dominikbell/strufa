# FEEC (Finite Element Exterior Calculus)


As mentioned in the [main README](../../README.md), a uniform grid with periodic boundary conditions and B-splines as FE basis functions are used.


Splitting the periodic domain $[0,L[$ into $n$ cells (=`N_elements` in the input file) yields $n$ grid points. For basis functions of degree $p$ there are $n+p$ knot points, extending to the left of the left domain boundary, i.e.

$$
x_0 = - p \, \Delta x \qquad x_p = 0 \qquad x_{n-1+p} = (n-1) \Delta x = L - \Delta x
$$


The basis functions (B-splines) of degree $p=0$ are defined as

$$
N^0_i(x) = \begin{cases} 1 & \text{if } x \in [x_i, x_{i+1}[ \\ 0 & \text{else} \end{cases} \qquad i = 0, \ldots, n-1
$$

where $\Delta x$ is the grid spacing. Higher degree basis functions are defined recurrently 

$$
N^p_i(x) = w^p_i(x) \, N^{p-1}_i(x) + \left( 1 - w^p_{i+1}(x) \right) N^{p-1}_{i+1}(x)
$$

where

$$
w^p_i (x) = \frac{x - x_i}{x_{i+p} - x_i}
$$


Introduce the notation of D-splines

$$
D_i^p(x) = \frac{1}{\Delta x} \, N^{p-1}_i(x)
$$

(so the superindex does not correspond to the degree of the polynomial anymore), such that the derivative of an N-spline becomes

$$
\frac{\text{d}}{\text{d} x} N_i^p(x) = D_i^p(x) - D_{i+1}^p(x)
$$

At every point $x$ there are $p+1$ non-zero spline functions of degree $p$. The index of the last basis function which is non-zero at that point is called the span index and can be computed by `floor(x / Delta_x) + p`.

There are $n$ Greville points

$$
\xi_i = \frac{x_i + \ldots + x_{i+p}}{p} \qquad i = 0, \ldots, n-1
$$

from which the spline collocation matrix

$$
(\mathcal{I}_0)_{ij} = N_j^p(\xi_i) \qquad i,j = 0, \ldots, n-1
$$

and the spline histopolation matrix

$$
(\mathcal{I}_1)_{ij} = \int_{\xi_{i-1}}^{\xi_i} N_j^p(x) \, \text{d} x \qquad i,j = 0, \ldots, n-1
$$

can be defined.


In one dimension, the diagram reads

<div align="center">
  <img src="../../res/diagram1D_fred.svg" width="400" />
</div>
