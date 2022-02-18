#include <iostream>
#include <complex>
#include "solution.h"

// Pretty printing complex numbers
template<typename T>
std::ostream& operator << (std::ostream& os, const std::complex<T> z) {
  if (imag(z) >= 0)
    return os << real(z) << " + " << imag(z) << "j";
  return os << real(z) << " - " << -imag(z) << "j";
}


// Solutiion class ////////////////////////////////////////////////////////////
// Added to the ostream, such that we can "std::cout" a Solution object.
std::ostream& operator << (std::ostream& os, const Solution &sol) {
  return os << "x = " << sol.m_x << ",\t f(x) = " << sol.m_fx << ",\t niter = " << sol.m_n;
}

Solution::operator double() const { return m_x; }


// CSolution class ////////////////////////////////////////////////////////////
// Added to the ostream, such that we can "std::cout" a Solution object.
std::ostream& operator << (std::ostream& os, const CSolution &sol) {
  return os << "x = " << sol.m_x << ",\t f(x) = " << sol.m_fx << ",\t niter = " << sol.m_n;
}

CSolution::operator cdouble() const { return m_x; }

