#include "Geometry.h"

Geometry::Geometry()
{
}


double Geometry::radToDegree(double rad)
{
    return (rad * 180) / M_PI;
}

double Geometry::findSlope(const Point& p1, const Point& p2)
{
    return ( p1.getY() - p2.getY() ) / ( p1.getX() - p2.getX() );
}

double Geometry::getSlopeFromRadian(double rad)
{
    return -tan(rad); // - car on travaille dans un repère inversé
}

double Geometry::getDistance(const Point& p1, const Point& p2)
{
    return sqrt( pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2) );
}
