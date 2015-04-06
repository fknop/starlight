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

    if (slope == INFINITY)
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
//    if (umath::double_equals(std::abs(rad), M_PI))
//        return 0; // Pour éviter la perte de précision.

    return -tan(rad); // - car on travaille dans un repère inversé
}

bool Geometry::is_on_good_side(const Line& l, const Point& p)
{
    double angle = l.angle();

    // Angle à 90°
    if (umath::double_equals(angle, M_PI_2)
            || umath::double_equals(angle, -M_PI_2_3))
            return umath::double_equals(p.x(), l.origin().x())
                && p.y() < l.origin().y();

    // Angle à 270°
    if (umath::double_equals(angle, M_PI_2_3)
            || umath::double_equals(angle, -M_PI_2))
            return p.y() > l.origin().y();

    // Angle à 180°
    if (umath::double_equals(angle, M_PI)
            || umath::double_equals(angle, -M_PI))
        return umath::double_equals(p.y(), l.origin().y())
                && p.x() < l.origin().x();

    // Angle à 0°
    if (umath::double_equals(angle, 0)
            || umath::double_equals(std::abs(angle), 2*M_PI))
        return umath::double_equals(p.y(), l.origin().y())
                && p.x() > l.origin().x();

    // Premier quadrant
    if ((angle > 0 && angle < M_PI_2) ||
            (angle < -M_PI_2_3 && angle > -(2*M_PI)))
        return p.x() > l.origin().x() && p.y() < l.origin().y();

    // Deuxième quadrant
    else if ((angle > M_PI_2 && angle < M_PI) ||
             (angle < -M_PI && angle > -M_PI_2_3))
        return p.x() < l.origin().x() && p.y() < l.origin().y();

    // Troisième quadrant
    else if ((angle > M_PI && angle < M_PI_2_3) ||
             (angle < -M_PI_2 && angle > -M_PI))
        return p.x() < l.origin().x() && p.y() > l.origin().y();

    // Quatrième quadrant
    else
        return p.x() > l.origin().x() && p.y() > l.origin().y();
}
