#include "constants.h"
#include "geometry.h"
#include "umath.h"


double Geometry::rad_to_deg(double rad)
{
    return (rad * 180.0) / M_PI;
}

double Geometry::deg_to_rad(double degrees)
{
    return (degrees * M_PI) / 180;
}

double Geometry::slope_to_rad(const Point& p1, const Point& p2)
{
    double slope = rad_to_slope(p1, p2);

    if (std::isinf(slope))
        return M_PI_2;
    else
        return std::atan(slope);
}

double Geometry::slope_to_rad(double slope)
{
    return std::atan(slope);
}

double Geometry::rad_to_slope(const Point& p1, const Point& p2)
{
    return -((p1.y() - p2.y()) / (p1.x() - p2.x()));
}

double Geometry::rad_to_slope(double rad)
{
    if (umath::double_equals(std::abs(rad), M_PI))
        return 0; // Pour éviter la perte de précision.

    return -tan(rad); // - car on travaille dans un repère inversé
}




