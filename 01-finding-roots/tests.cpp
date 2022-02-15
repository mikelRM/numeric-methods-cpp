#include <iostream>
#include <functional>
#include <cmath>
#include "solution.h"
#include "bisection.h"

using std::cout;
using std::endl;

double foo(double x) {
  return pow(x, 2) - 4;
}


int main() {
  Solution sol;
  
  cout << "In this program I find roots for f(x) = x² - 4." << endl << endl;
  cout << "Initial guesses: x1 = -5, x2 = 5:" << endl;
  sol = bisect(foo, -5., 5.);

  sol.print();
  cout << sol << endl << endl;
  cout << (double)sol << endl;
  
  cout << "Initial guesses: x1 = -1, x2 = 5:" << endl;
  sol = bisect(foo, -1., 10.);

  sol.print();
  cout << sol << endl << endl;
  cout << (double)sol << endl;

  cout << "x = " << (float)sol << endl;
}
