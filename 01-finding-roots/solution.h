#pragma once

#include <iostream>

struct Solution {
  double x;
  double fx;
  int n;

  operator double() const;
  operator float() const;
  
  void print(bool = true);
  friend std::ostream& operator << (std::ostream &o, const Solution &sol);
};
