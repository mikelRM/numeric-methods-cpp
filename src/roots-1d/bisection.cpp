#include <iostream>
#include <cmath>
#include "solution.h"
#include "roots.h"

using std::cout;
using std::endl;


// Solution bisect (function<double(double)> f, double x1, double x2, double tol, int nmax) {

Solution bisect (double (*f)(double), double x1, double x2, double tol, int nmax) {
  double fx1, fx2, fx3;
  double x3;
  
  fx1 = f(x1);
  fx2 = f(x2);

  if (tol <= 0) {
    cout << "ERROR: tol value must be positive" << endl;
    return Solution(NAN, NAN, 0);
  }
  
  if (fx1 * fx2 > 0) {
    cout << "ERROR: the function has the same sign at both boundaries" << endl;
    return Solution(NAN, NAN, 0);
  }

  for (int n=1; n<=nmax; n++) {
    x3 = (x1 + x2) / 2.;
    fx3 = f(x3);

    if (fabs(fx1) < tol) {
      return Solution(x1, fx1, n);
    }

    if (fabs(fx2) < tol) {
      return Solution(x2, fx2, n);
    }

    if (fabs(fx3) < tol) {
      return Solution(x3, fx3, n);
    }

    // Check where the crossing of the y=0 line happens
    if (fx1 * fx3 > 0) {
      x1 = x3;
      fx1 = fx3;
    } else {
      x2 = x3;
      fx2 = fx3;
    }
  }
  
  cout << "ERROR: after " << nmax << " iterations the root was not obtained." << endl;
  return Solution(NAN, NAN, nmax);
}
