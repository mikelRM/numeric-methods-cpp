#pragma once

#include "solution.h"

Solution bisect (double (*)(double), double, double, double = 1e-8, int = 100);

Solution iterative (double (*)(double), double (*)(double), double, double = 1e-8, int = 100);

Solution newton_raphson (double (*)(double), double (*)(double), double, double = 1e-8, int = 100);

