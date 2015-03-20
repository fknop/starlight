#include "Geometry.h"

using namespace std;

Geometry::Geometry()
{
}


double Geometry::radToDegree(double rad)
{
    return (rad * 180) / M_PI;
}

double Geometry::findSlope(const Point& p1, const Point& p2)
{
    return  (double) (p1.getY() - p2.getY()) / (double) (p1.getX() - p2.getX());
}

double Geometry::getSlopeFromRadian(double rad)
{
    return -tan(rad); // - car on travaille dans un repère inversé
}

double Geometry::getDistance(const Point& p1, const Point& p2)
{
    return sqrt( pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2) );
}

bool Geometry::isInBoundingBox(const Point& p, const LineSegment& ls)
{
    Point p1 = ls.getP1();
    Point p2 = ls.getP2();

    return ((min(p1.getX(), p2.getX()) <= p.getX()) && (p.getX() <= max(p1.getX(), p2.getX()))
            && ((min(p1.getY(), p2.getY()) <= p.getY()) && (p.getY() <= max(p1.getY(), p2.getY()))));


}

Point * Geometry::getIntersection(const Line& l, const LineSegment& ls)
{
    Point * p = l.getIntersection(Line(ls.getP1(), ls.getP2()));
    if (p != nullptr && Geometry::isInBoundingBox(*p, ls))
        return p;
    else
        return nullptr;


}
