#include "Line.h"
#include "Geometry.h"




Line::Line(const Point& origin, double angle)
{
   this->origin = origin;
   this->angle = angle;

//   this->b = this->origin.getY() - (this->slope * this->origin.getX());
}

Line::Line(const Point& p1, const Point& p2)
{
   this->origin = p1;
   this->angle = Geometry::getSlope(p1, p2);
   // y = ax + b
   // b = y - ax
   //this->b = this->origin.getY() - (this->slope * this->origin.getX());

}


//Point* Line::getIntersection(const Line& l) const
//{
//    int x, y;

//    if (this->slope == l.slope)
//    {
//        return nullptr;
//    }
//    else
//    {
//        x = (l.b - this->b) / (this->slope - l.slope);
//        y = (l.slope * x) + l.b;

//        return new Point(x, y);
//    }
//}

const Point& Line::getPoint() const
{
    return this->origin;
}

void Line::setPoint(const Point &origin)
{
    this->origin = origin;
}

double Line::getAngle() const
{
    return this->angle;
}

void Line::setAngle(double angle)
{
    this->angle = angle;
}



//double Line::getB() const
//{
//    return this->b;
//}
