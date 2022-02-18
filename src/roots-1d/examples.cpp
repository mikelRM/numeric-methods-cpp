#include <iostream>
#include <functional>
#include <cmath>
#include "solution.h"
#include "roots.h"

using std::cout;
using std::endl;


double h (double x) {
  return x*x*x - x - 1.;
}

// Roots at x=-1.12311 and x=7.12311
double f (double x) {
  return x*x - 6*x - 8;
}

// Rewriting f(x)=0 as x=g(x):
double g (double x) {
  return sqrt(6*x + 8);
}

// First derivative of f(x):
double df (double x) {
  return 2*x - 6;
}

// Complex function with roots at z = +- i
cdouble cf (cdouble z) {
  return z*z + 1.;
}

//First derivative of cf(z)
cdouble cdf (cdouble z) {
  return 2.*z;
}


int main() {
  Solution sol;
  CSolution csol;
  
  cout << "In this program I find roots for f(x) = x² - 6x - 8." << endl << endl;

  // BISECTION METHOD /////////////////////////////////////////////////////////
  cout << endl << "========== BISECTION METHOD ==========" << endl;

  cout << "Initial guesses: x1 = -5, x2 = 5:" << endl;
  sol = bisect(f, -5., 5.);
  cout << sol << endl << endl;
  
  cout << "Initial guesses: x1 = -1, x2 = 5:" << endl;
  sol = bisect(f, -1., 10.);
  cout << sol << endl << endl;

  
  // ITERATIVE METHOD /////////////////////////////////////////////////////////
  cout << endl << "========== ITERATIVE METHOD ==========" << endl;

  cout << "Initial guess: x0 = -100" << endl;
  sol = iterative(f, g, -100);
  cout << sol << endl << endl;

  cout << "Initial guess: x0 = -2" << endl;
  sol = iterative(f, g, -2);
  cout << sol << endl << endl;

  sol = iterative(f, g, 0);
  cout << "Initial guess: x0 = 0" << endl;
  cout << sol << endl << endl;

  sol = iterative(f, g, 7);
  cout << "Initial guess: x0 = 7" << endl;
  cout << sol << endl << endl;

  sol = iterative(f, g, 10);
  cout << "Initial guess: x0 = 10" << endl;
  cout << sol << endl << endl;

  sol = iterative(f, g, 50);
  cout << "Initial guess: x0 = 50" << endl;
  cout << sol << endl << endl;


  // NEWTON RAPHSON ///////////////////////////////////////////////////////////
  cout << endl << "========== NEWTON-RAPHSON METHOD ==========" << endl;

  sol = newton_raphson(f, df, -100.);
  cout << "Initial guess: x0 = -100" << endl;
  cout << sol << endl << endl;
  
  sol = newton_raphson(f, df, -10.);
  cout << "Initial guess: x0 = -10" << endl;
  cout << sol << endl << endl;
  
  sol = newton_raphson(f, df, -1.);
  cout << "Initial guess: x0 = -1" << endl;
  cout << sol << endl << endl;
  
  sol = newton_raphson(f, df, 1.);
  cout << "Initial guess: x0 = 1" << endl;
  cout << sol << endl << endl;
  
  sol = newton_raphson(f, df, 10.);
  cout << "Initial guess: x0 = 10" << endl;
  cout << sol << endl << endl;
  
  sol = newton_raphson(f, df, 100.);
  cout << "Initial guess: x0 = 100" << endl;
  cout << sol << endl << endl;


  // MULLER METHOD ////////////////////////////////////////////////////////////
  cout << endl << "========== MULLER METHOD ==========" << endl;

  cout << "Selected points: \t x-2 = 0,  x-1 = 3,  x0 = 10" << endl;
  sol = muller(f, 0., 3., 10);
  cout << sol << endl << endl;

  cout << "Selected points: \t x-2 = -3,  x-1 = 3,  x0 = 10" << endl;
  sol = muller(f, -3., 3., 10);
  cout << sol << endl << endl;

  cout << "Selected points: \t x-2 = -2,  x-1 = -1,  x0 = 0" << endl;
  sol = muller(f, -2., -1., 0);
  cout << sol << endl << endl;

  cout << "The Muller method involves square roots --> it can cause problems" << endl
       << "if we don't care about complex numbers." << endl << endl;


  // COMPLEX FUNCTIONS ////////////////////////////////////////////////////////
  cout << endl << "========== COMPLEX FUNCTIONS (NEWTON) ==========" << endl;

  cout << "Initial guess: z0 = 0.4 + 1j" << endl;
  csol = newton_raphson(cf, cdf, 0.4 + I);
  cout << csol << endl << endl;

  cout << "Initial guess: z0 = -8.3 - 10j" << endl;
  csol = newton_raphson(cf, cdf, -8.3 - I*10.);
  cout << csol << endl << endl;

  cout << "Initial guess: z0 = 8.4 - 3.2j" << endl;
  csol = newton_raphson(cf, cdf, 8.4 - I*3.2);
  cout << csol << endl << endl;

  cout << "Initial guess: z0 = -9.3 + 5.4j" << endl;
  csol = newton_raphson(cf, cdf, -9.3 + I*5.4);
  cout << csol << endl << endl;  
  

}
