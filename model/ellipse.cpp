#include "ellipse.h"

Ellipse::Ellipse(const Point & p, double xRad, double yRad)
        : pos{p}, xRadius(xRad), yRadius(yRad)
{
    if (xRad <= 0 || yRad <= 0)
        throw "Les rayons de l'ellipse doivent être strictement positif";
}

Ellipse::~Ellipse()
{

}

bool Ellipse::intersects(const LineSegment & l, std::vector<Point>& points)
{

    double x;
    double y;
    double a = xRadius * 2;
    double b = yRadius * 2;



    /*

      ((x - x1)² / a²) + ((y- y1)² / b²) = 1
       x1 et y1 sont les coordonnées du centre.
        a est la longueur : xRad * 2
        b est la hauteur : yRad * 2

     */



}

