#include <iostream>
#include <cmath>
#include "solution.h"
#include "roots.h"

using std::cout;
using std::endl;


Solution newton_raphson (double (*f)(double), double (*df)(double), double const x0,
			 double const tol, int const nmax)
{
  double x1 = x0, x2;

  for (int n=1; n <= nmax; ++n) {
    x2 = x1 - f(x1)/df(x1);

    if (fabs(f(x2)) < tol)
      return Solution(x2, f(x2), n);
    
    x1 = x2;
  }

  cout << "ERROR: after " << nmax << " iterations the root was not obtained." << endl;
  return Solution(NAN, NAN, nmax);  
}
