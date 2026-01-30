# FEEC (Finite Element Exterior Calculus)


As mentioned in the [main README](../../README.md), a uniform grid with periodic boundary conditions and B-splines as FE basis functions are used. Because higher dimensions $d>1$ are constructed by taking the tensor product of $d$ one-dimensional FE spaces, we present the 1D case and then generalize.


## In 1 Dimension

### Basis Functions

Splitting the periodic domain $[0,L[$ into $n$ cells (=`N_elements` in the input file) yields $n$ grid points. For basis functions of degree $p$ there are $n+p$ knot points, extending to the left of the left domain boundary, i.e.

$$
x_j = (j - p) \\, \Delta x
$$

with the special points

$$
x_0 = - p \\, \Delta x \qquad x_p = 0 \qquad x_{n-1+p} = (n-1) \Delta x = L - \Delta x
$$


The basis functions (B-splines) of degree $p=0$ are defined as

$$
N^0_i(x) = \begin{cases} 1 & \text{if } x \in [x_i, x_{i+1}[ \\\ 0 & \text{else} \end{cases} \qquad i = 0, \ldots, n-1
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
D_i^p(x) = \frac{1}{\Delta x} \\, N^{p-1}_i(x)
$$

(so the superindex does not correspond to the degree of the polynomial anymore), such that the derivative of an N-spline becomes

$$
\frac{\text{d}}{\text{d} x} N_i^p(x) = D_i^p(x) - D_{i+1}^p(x)
$$

At every point $x$ there are $p+1$ non-zero spline functions of degree $p$. The index of the last basis function which is non-zero at that point is called the span index and can be computed by `floor(x / Delta_x) + p`.


### Spline Collocation and Histopolation Matrix

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
(\mathcal{I}_1)_{ij} = \int_{\xi_{i-1}}^{\xi_i} N_j^p(x) \\, \text{d} x \qquad i,j = 0, \ldots, n-1
$$

can be defined. Since the grid is uniform and periodic, these matrices are circulant.


### de Rham diagram

In one dimension, the diagram reads

<div align="center">
  <img src="../../res/diagram1D.svg" width="400"/>
</div>

connecting the Sobolev spaces

$$
\begin{aligned}
	L^2(\Omega) & = \left\\{ f : \Omega \to \mathbb{R} \\; \\; \bigg\rvert \; \int_\Omega |f|^2 \\, \text{d} x < \infty \right\\} & H^1(\Omega) & = \left\\{ f \in L^2(\Omega) \\; \\; \bigg\rvert \\; \frac{\partial f}{\partial x} \in L^2(\Omega) \right\\}
\end{aligned}
$$

and finite-dimensional subspaces of them

$$
\begin{aligned}
	V_0 & = \text{span}\left\{ \left(N_j^p(x)\right)_{0\le j \le n-1} \right\} & V_1 & = \text{span}\left\{ \left(D_j^p(x)\right)_{0\le j \le n-1} \right\}
\end{aligned}
$$


The operators $\sigma^k, k=0,1$ are the evaluation at the Greville points

$$
\sigma_i^0 (f) = f (\xi_i)
$$

and the histopolation between two Greville points

$$
\sigma_i^1(f) = \int_{\xi_{i-1}}^{\xi_i} f(x) \\, \text{d} x
$$

The gradient matrix $\mathbb{G}$ connects the spaces of coefficients

$$
\mathbb{G} = \begin{pmatrix}
	-1 & 1 & 0 & \ldots & & 0 \\
	0 & -1 & 1 & & & \vdots \\
	\vdots \\
	1 & \ldots & & & 0 & -1
\end{pmatrix} \quad \in \mathbb{R}^{n, n}
$$

Finally, the operators $S_0$ and $S_1$ map the coefficients to a continuous function in the subspaces $V_0$ and $V_1$:
$$
\begin{aligned}
	S_0 : \;& \mathcal{D}_0 \to V_0 & S_1 : \;& \mathcal{D}_1 \to V_1 \\
	& \, f_i \; \mapsto \sum_{i=0}^{n-1} f_i N_i^k(x) & & \, g_i \; \mapsto \sum_{i=0}^{n-1} g_i D_i^k(x) 
\end{aligned}
$$



## de Rham Diagrams

In two dimensions we take a vector gradient and a scalar curl such that we can preserve divergence-freeness strongly

<div align="center">
  <img src="../../res/diagram2D.svg" width="650"/>
</div>

And the diagram for three dimensions is a tensor product of three times one dimension

<div align="center">
    <img src="../../res/diagram3D.svg" width="1000"/>
</div>


# Implementation

## Matrices

Matrices are implemented in a matrix-free fashion, i.e. only their product with a vector is implemented.

## Spline Functions

The nonzero B-spline basis functions for a point in the first cell of the domain $[x_p, x_{p+1})$ are summarized by a $(p+2) \times (p+1)$ matrix

| $\mathbf{k / j}$ | $\mathbf{0}$ | $\mathbf{1}$ | $\mathbf{\ldots}$ | $\mathbf{p-2}$ | $\mathbf{p-1}$ | $\mathbf{p}$ | ghost |
| :---: | :---: | :---: | :---: | :---: | :---: | :---:| :---: |
| $\mathbf{0}$ | $0$ | $0$ | | $0$ | $0$ | $N_p^0$ | $0$ |
| $\mathbf{1}$ | $0$ | $0$ | | $0$ | $N_{p-1}^1$ | $N_p^1$ | $0$ |
| $\mathbf{2}$ | $0$ | $0$ | | $N_{p-2}^2$ | $N_{p-1}^2$ | $N_p^2$ | $0$ |
| $\mathbf{\vdots}$ | |
| $\mathbf{p-1}$ | $0$ | $N_1^{p-1}$ | | $N_{p-2}^{p-1}$ | $N_{p-1}^{p-1}$ | $N_p^{p-1}$ | $0$ |
| $\mathbf{p}$ | $N_0^p$ | $N_1^p$ | | $N_{p-2}^p$ | $N_{p-1}^p$ | $N_p^p$ | $0$ |

Every row is computed from the preceding row by using the recurrence relation for B-splines, where

$$
\begin{aligned}
w_j^k & = \frac{x - x_j}{x_{k+j} - x_j} = \frac{x - (j - p) \Delta x }{k \Delta x} = \frac{\frac{x}{\Delta x} + p - j}{k} \\
1 - w_{j+1}^k & = 1 - \frac{\frac{x}{\Delta x} + p - j -1 }{k} = \frac{j + 1 + k - p - \frac{x}{\Delta x}}{k}
\end{aligned}
$$

where $k = 0, \ldots, p$ and $j = p - k, \ldots, p$ and we have used that $x_j = (j-p) \Delta x$.

For our implementation we use the global variable `MAX_DEGREE` (located in `src/main.hpp`) to denote the maximal degree for which the program is compiled such that we can allocate memory on the stack. In the above table $p$ is replaced by `MAX_DEGREE` and we compute only up to the $k$ that is the degree of the current run.
