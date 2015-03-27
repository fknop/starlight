#include "Geometry.h"



double Geometry::getDegrees(double rad)
{
    return (rad * 180) / M_PI;
}

double Geometry::getAngle(const Point& p1, const Point& p2)
{
    return std::atan(getSlope(p1, p2));
}

double Geometry::getAngle(double slope)
{
    return std::atan(slope);
}

double Geometry::getRadians(double degrees)
{
    return (degrees * M_PI) / 180;
}

double Geometry::getSlope(const Point& p1, const Point& p2)
{
    return  - ((p1.getY() - p2.getY()) / (p1.getX() - p2.getX()));
}

double Geometry::getSlope(double rad)
{
    return -tan(rad); // - car on travaille dans un repère inversé
}


bool Geometry::isInBoundingBox(const Point& p, const LineSegment& ls)
{
    Point p1 = ls.getStart();
    Point p2 = ls.getEnd();

    return (( std::min(p1.getX(), p2.getX()) <= p.getX() )
            && ( p.getX() <= std::max(p1.getX(), p2.getX()) )
            && (( std::min(p1.getY(), p2.getY()) <= p.getY() )
            && ( p.getY() <= std::max(p1.getY(), p2.getY()) )));
}

Point * Geometry::getIntersection(const Line& l, const LineSegment& ls)
{
//    Point * p = l.getIntersection(Line(ls.getStart(), ls.getEnd()));

//    if (p != nullptr && Geometry::isInBoundingBox(*p, ls))
//        return p;
//    else
        return nullptr;
}
