#include <iostream>
#include "solution.h"

void Solution::print(bool end_line_jump)
{
  std::cout << "x = " << Solution::x << ",\t f(x) = " << Solution::fx
	    << ",\t niter = " << Solution::n << std::endl;

  if (end_line_jump) std::cout << std::endl;
}

// Added to the ostream, such that we can "std::cout" a Solution object.
std::ostream& operator << (std::ostream &o, const Solution &sol) {
  return o << "x = " << sol.x << ",\t f(x) = " << sol.fx << ",\t niter = " << sol.n;
}


Solution::operator double() const { return x; }
Solution::operator float() const { return (float)x;}

