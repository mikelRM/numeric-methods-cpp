#include <iostream>
#include <cmath>
#include <algorithm>
#include "solution.h"
#include "roots.h"

using std::cout;
using std::endl;


Solution muller (double (*f)(double), double x2, double x1, double x0,
		 double const tol, int const nmax)
{
  double x_aux;
  double y0, y1, y2;
  double A, B, C, Q;

  y0 = f(x0);
  y1 = f(x1);
  y2 = f(x2);

  for (int n=1; n<=nmax; n++) {
    Q = (x0 - x1) / (x1 - x2);
    A = Q*y0 - Q*(1-Q)*y1 + Q*Q*y2;
    B = (2*Q+1)*y0 - pow(1+Q, 2)*y1 + Q*Q*y2;
    C = (1+Q) * y0;

    x_aux = x0 - 2*C*(x0 - x1) / std::max(B + sqrt(B*B - 4*A*C),
					  B - sqrt(B*B - 4*A*C));

    if (std::isnan(x_aux)) {
      cout << "ERROR: square root of negative value (not real value)." << endl;
      return Solution(NAN, NAN, n);
    }
      
    
    if (x_aux < x2) {
      x0 = x1;
      x1 = x2;
      x2 = x_aux;
    } else if (x_aux > x0) {
      x2 = x1;
      x1 = x0;
      x0 = x_aux;
    } else  if (x_aux < x1) {
      x0 = x1;
      x1 = x_aux;
    } else {
      x2 = x1;
      x1 = x_aux;
    }
    
    y0 = f(x0);
    y1 = f(x1);
    y2 = f(x2);

    if (fabs(y0) < tol)
      return Solution(x0, y0, n);
    
    if (fabs(y1) < tol)
      return Solution(x1, y1, n);
    
    if (fabs(y2) < tol)
      return Solution(x2, y2, n);
    
  }

  cout << "ERROR: after " << nmax << " iterations the root was not obtained." << endl;

  return Solution(NAN, NAN, nmax);


}
