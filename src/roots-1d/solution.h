#pragma once

#include <iostream>
#include <complex>

typedef std::complex<double> cdouble;
const cdouble I = {0., 1.};


// Pretty printing complex numbers
template<typename T>
std::ostream& operator << (std::ostream&, const std::complex<T>);


// Real-type solution class
struct Solution {
  double m_x;
  double m_fx;
  int m_n;

  operator double() const;

  Solution() {}
  Solution(double x, double fx, int n) : m_x(x), m_fx(fx), m_n(n) {}
  
  friend std::ostream& operator << (std::ostream&, const Solution&);
};


// Complex version of solution class
struct CSolution {
  cdouble m_x;
  cdouble m_fx;
  int m_n;

  operator cdouble() const;

  CSolution() {}
  CSolution(cdouble x, cdouble fx, int n) : m_x(x), m_fx(fx), m_n(n) {}
  
  friend std::ostream& operator << (std::ostream&, const CSolution&);
};
