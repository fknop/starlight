#include <cmath>

#include "ellipse.h"
#include "geometry.h"
#include "umath.h"
#include "constants.h"


Ellipse::Ellipse(const Point & p, double xRad, double yRad)
        : center_{p}, x_rad_(xRad), y_rad_(yRad)
{
    if (xRad <= 0 || yRad <= 0)
        throw std::string("Les rayons de l'ellipse doivent être strictement positifs.");
}
