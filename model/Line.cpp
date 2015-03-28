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

/**
 * @brief Line::intersects
 * @param l
 * @param intersection
 * @return
 */
bool Line::intersects(const Line &l, Point ** intersection)
{
    /* Passage par pointeur de pointeur
       car un pointeur est passé par valeur et donc ne sera pas
       le même que celui de base et l'assignation de la valeur
       se fera sur un autre pointeur.
      */
    double x1, y1, b1, slope1;
    double x2, y2, b2, slope2;


    // Même droite
    if (*this == l ||
            (std::fmod(this->angle, M_PI) == std::fmod(l.angle, M_PI)))
    {
        *intersection = nullptr;
        return false;
    }

    // Même origine donc intersection == origin
    if (this->origin == l.origin)
    {
        *intersection = new Point(this->origin);
        return true;
    }


   // Droites verticales
   // Faire une méthode pour refactor
   if (std::abs(std::fmod(this->angle, M_PI)) == (M_PI / 2))
   {
        x1     = this->origin.getX();
        x2     = x1;
        slope2 = Geometry::getSlope(l.angle);
        b2     = l.origin.getY() - (slope2 * l.origin.getX());
        y2     = (x2 * slope2) + b2;

        *intersection = new Point(x2, y2);

   }
   else if (std::abs(std::fmod(l.angle, M_PI)) == (M_PI / 2))
   {
        x2     = l.origin.getX();
        x1     = x2;
        slope1 = Geometry::getSlope(this->angle);
        b1     = this->origin.getY() - (slope1 * l.origin.getX());
        y1     = (x1 * slope1) + b1;

        *intersection = new Point(x1, x2);
   }
   else
   {
       slope1 = Geometry::getSlope(this->angle);
       slope2 = Geometry::getSlope(l.angle);
       b1     = this->origin.getY() - (slope1 * l.origin.getX());
       b2     = l.origin.getY() - (slope2 * l.origin.getX());
       x1     = (b2 - b1) / (slope1 - slope2);
       y1     = (slope2 * x1) + b2;

       *intersection = new Point(x1, y1);
   }

   return true;

}

bool Line::intersects(const LineSegment &ls, Point ** intersection)
{

    Point start = ls.getStart();
    Point end = ls.getEnd();
    double rad = Geometry::getAngle(start, end);
    std::cout << rad << std::endl;
    if (intersects(Line(start, rad), intersection))
    {
        std::cout << **intersection << std::endl;
        if (!Geometry::isInBoundingBox(**intersection, ls))
        {
            *intersection = nullptr;
            return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

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

bool operator==(const Line& l1, const Line& l2)
{
    return l1.angle == l2.angle && l1.origin == l2.origin;
}

