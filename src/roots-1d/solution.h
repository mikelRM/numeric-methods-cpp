#pragma once

#include <iostream>

struct Solution {
  double m_x;
  double m_fx;
  int m_n;

  operator double() const;
  operator float() const;

  Solution() {}
  Solution(double x, double fx, int n) : m_x(x), m_fx(fx), m_n(n) {}
  
  void print(bool = true);
  friend std::ostream& operator << (std::ostream &o, const Solution &sol);
};
