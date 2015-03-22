#include "Line.h"
#include "Geometry.h"




Line::Line(const Point& p, double rad)
{
   this->p = p;
   this->slope = Geometry::getSlopeFromRadian(rad);
   // y = ax + b
   // b = y - ax
   this->b = this->p.getY() - (this->slope * this->p.getX());


}


Line::Line(const Point& p1, const Point& p2)
{
   this->p = p1;
   this->slope = Geometry::findSlope(p1, p2);
   // y = ax + b
   // b = y - ax
   this->b = this->p.getY() - (this->slope * this->p.getX());

   if (std::isinf(slope))
           std::cout << b;

}


Point* Line::getIntersection(const Line& l) const
{

    int x, y;

    if (this->slope == l.slope)
    {
        return nullptr;

    }
    else
    {
        x = (l.b - this->b) / (this->slope - l.slope);

        y = (l.slope * x) + l.b;


        return new Point(x, y);
    }
}

const Point& Line::getPoint() const
{
    return this->p;
}

double Line::getSlope() const
{
    return this->slope;
}

double Line::getB() const
{
    return this->b;
}
