#include "Geometry.h"

using namespace std;

Geometry::Geometry()
{
}


double Geometry::getDegrees(double rad)
{
    return (rad * 180) / M_PI;
}

double Geometry::getSlope(const Point& p1, const Point& p2)
{
    return  (double) (p1.getY() - p2.getY()) / (double) (p1.getX() - p2.getX());
}

double Geometry::getSlope(double rad)
{
    return -tan(rad); // - car on travaille dans un repère inversé
}


bool Geometry::isInBoundingBox(const Point& p, const LineSegment& ls)
{
    Point p1 = ls.getStart();
    Point p2 = ls.getEnd();

    return (( min(p1.getX(), p2.getX()) <= p.getX() )
            && ( p.getX() <= max(p1.getX(), p2.getX()) )
            && (( min(p1.getY(), p2.getY()) <= p.getY() )
            && ( p.getY() <= max(p1.getY(), p2.getY()) )));
}

Point * Geometry::getIntersection(const Line& l, const LineSegment& ls)
{
    Point * p = l.getIntersection(Line(ls.getStart(), ls.getEnd()));

    if (p != nullptr && Geometry::isInBoundingBox(*p, ls))
        return p;
    else
        return nullptr;
}
