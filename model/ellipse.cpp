#include <cmath>

#include "model/ellipse.h"

#include "utils/umath.h"
#include "utils/constants.h"


Ellipse::Ellipse(const Point& p, double x_rad, double y_rad)
        : center_{p}, x_rad_(x_rad), y_rad_(y_rad)
{
    if (x_rad <= 0 || y_rad <= 0)
        throw std::string("Les rayons de l'ellipse doivent être strictement positifs.");
}
