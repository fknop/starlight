#include "geometry.h"


double Geometry::get_degrees(double rad)
{
    return (rad * 180.0) / M_PI;
}

double Geometry::radians(double degrees)
{
    return (degrees * M_PI) / 180;
}

double Geometry::angle(const Point& p1, const Point& p2)
{
    return std::atan(get_slope(p1, p2));
}

double Geometry::angle(double slope)
{
    return std::atan(slope);
}

double Geometry::get_slope(const Point& p1, const Point& p2)
{
    return  - ((p1.y() - p2.y()) / (p1.x() - p2.x()));
}

double Geometry::get_slope(double rad)
{
    if (std::abs(rad) == M_PI)
        return 0; // Pour éviter la perte de précision.

    return -tan(rad); // - car on travaille dans un repère inversé
}


bool Geometry::is_in_bounding_box(const Point& p, const LineSegment& ls)
{
    Point start = ls.start();
    Point end = ls.end();

    return ((std::min(start.x(), end.x()) <= p.x()) &&
            (std::max(start.x(), end.x()) >= p.x()) &&
            (std::min(start.y(), end.y()) <= p.y()) &&
            (std::max(start.y(), end.y()) >= p.y()));
}


