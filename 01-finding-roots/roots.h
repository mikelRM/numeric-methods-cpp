#pragma once

#include "solution.h"

Solution bisect (double (*f)(double), double, double, double = 1e-8, int = 100);

Solution iterative (double (*f)(double), double (*h)(double), double, double = 1e-8, int = 100);
