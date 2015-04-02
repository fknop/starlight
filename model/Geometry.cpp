#include "Geometry.h"

double Geometry::getDegrees(double rad)
{
    return (rad * 180.0) / M_PI;
}

double Geometry::getRadians(double degrees)
{
    return (degrees * M_PI) / 180;
}

double Geometry::getAngle(const Point& p1, const Point& p2)
{
    return std::atan(getSlope(p1, p2));
}

double Geometry::getAngle(double slope)
{
    return std::atan(slope);
}

double Geometry::getSlope(const Point& p1, const Point& p2)
{
    return  - ((p1.y() - p2.y()) / (p1.x() - p2.x()));
}

double Geometry::getSlope(double rad)
{
    if (std::abs(rad) == M_PI)
        return 0; // Pour éviter la perte de précision.

    return -tan(rad); // - car on travaille dans un repère inversé
}


bool Geometry::isInBoundingBox(const Point& p, const LineSegment& ls)
{
    Point start = ls.getStart();
    Point end = ls.getEnd();

    return ((std::min(start.x(), end.x()) <= p.x()) &&
            (std::max(start.x(), end.x()) >= p.x()) &&
            (std::min(start.y(), end.y()) <= p.y()) &&
            (std::max(start.y(), end.y()) >= p.y()));
}


