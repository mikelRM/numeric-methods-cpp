#include "solution.h"
#include "roots.h"
#include <iostream>
#include <cmath>

// First we will not make any discussion on the convergence frame
// TODO: Deal with complex numbers.
Solution iterative (double (*f)(double), double (*g)(double), double const x0,
		    double const tol, int const nmax)
{
  double x2, x1;
  
  x1 = x0;

  for (int n=1; n <= nmax; n++) {
    x2 = g(x1);

    if (fabs(x2 - x1) < tol && fabs(f(x2)) < tol) return Solution(x2, f(x2), n);

    x1 = x2;
  }
  
  std::cout << "ERROR: after " << nmax << " iterations the root was not obtained." << std::endl;
  return Solution(NAN, NAN, nmax);  
}
