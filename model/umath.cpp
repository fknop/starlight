#include <cmath>

#include "constants.h"
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
    double rho = (b*b) - (4*a*c);


    return rho;
}

bool umath::equals(double a, double b)
{
    return std::abs(a - b) < EPSILON;
}

bool umath::angle_equals(double a, double b)
{
    a = std::fmod(a, 2*M_PI);
    b = std::fmod(b, 2*M_PI);
    if (a < 0)
        a = (2*M_PI) + a;
    if (b < 0)
        b = (2*M_PI) + b;

    return umath::equals(a, b);
}

bool umath::angle_equals_pi(double a, double b)
{
    a = std::fmod(a, M_PI);
    b = std::fmod(b, M_PI);
    if (a < 0)
        a = a + M_PI;
    if (b < 0)
        b = b + M_PI;

    return umath::equals(a, b);
}
