#ifndef GEOM_UTILS_H
#define GEOM_UTILS_H

#include <cmath>
#include <vector>

static const double EPS = 1e-9;
static const double PI  = 3.14159265358979323846;

inline bool nearlyEqual(double a, double b) {
    return std::fabs(a - b) < EPS;
}

#endif