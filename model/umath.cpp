#include <cmath>

#include "umath.h"


double umath::dgcd(double a, double b)
{
    if (b == 0)
        return a;
    else
        return dgcd(b, std::fmod(a, b));
}

double umath::dlcm(double a, double b)
{
    return std::abs(a * b) / dgcd(a, b);
}

double umath::rho(double a, double b, double c)
{
    return (b*b) - (4 * a * c);
}

bool umath::double_equals(double a, double b, double epsilon = 0.0001)
{
    return std::abs(a - b) < epsilon;
}

