#include <iostream>
#include <functional>
#include <cmath>
#include "solution.h"
#include "roots.h"

using std::cout;
using std::endl;


// Roots at x=-1.12311 and x=7.12311
double f (double x) {
  return x*x - 6*x - 8;
}

// Rewriting f(x)=0 as x=g(x):
double g (double x) {
  return sqrt(6*x + 8);
}

int main() {
  Solution sol;
  
  cout << "In this program I find roots for f(x) = x² - 6x - 8." << endl << endl;

  // BISECTION METHOD /////////////////////////////////////////////////////////
  cout << endl << "========== BISECTION METHOD ==========" << endl;
  cout << "Initial guesses: x1 = -5, x2 = 5:" << endl;
  sol = bisect(f, -5., 5.);

  sol.print();
  cout << sol << endl << endl;
  
  cout << "Initial guesses: x1 = -1, x2 = 5:" << endl;
  sol = bisect(f, -1., 10.);

  sol.print();
  cout << sol << endl << endl;

  
  // ITERATIVE METHOD  ////////////////////////////////////////////////////////
  cout << endl << "========== ITERATIVE METHOD ==========" << endl;

  cout << "Initial guess: x0 = -100" << endl;
  sol = iterative(f, g, -100);
  cout << sol << endl;

  cout << "Initial guess: x0 = -2" << endl;
  sol = iterative(f, g, -2);
  cout << sol << endl;

  sol = iterative(f, g, 0);
  cout << "Initial guess: x0 = 0" << endl;
  cout << sol << endl;

  sol = iterative(f, g, 7);
  cout << "Initial guess: x0 = 7" << endl;
  cout << sol << endl;

  sol = iterative(f, g, 10);
  cout << "Initial guess: x0 = 10" << endl;
  cout << sol << endl;

  sol = iterative(f, g, 50);
  cout << "Initial guess: x0 = 50" << endl;
  cout << sol << endl;
}
