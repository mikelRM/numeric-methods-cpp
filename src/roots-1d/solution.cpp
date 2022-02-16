#include <iostream>
#include "solution.h"

void Solution::print(bool end_line_jump)
{
  std::cout << "x = " << m_x << ",\t f(x) = " << m_fx
	    << ",\t niter = " << m_n << std::endl;

  if (end_line_jump) std::cout << std::endl;
}

// Added to the ostream, such that we can "std::cout" a Solution object.
std::ostream& operator << (std::ostream &o, const Solution &sol) {
  return o << "x = " << sol.m_x << ",\t f(x) = " << sol.m_fx << ",\t niter = " << sol.m_n;
}


Solution::operator double() const { return m_x; }
Solution::operator float() const { return (float)m_x;}

