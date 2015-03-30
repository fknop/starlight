#include "Line.h"
#include "Geometry.h"




Line::Line(const Point& origin, double angle)
{
   this->origin = origin;
   this->angle = angle;
}

Line::Line(const Point& p1, const Point& p2)
{
   this->origin = p1;
   this->angle = Geometry::getSlope(p1, p2);
}

// méthode privée
Point * Line::verticalLineIntersection(const Line& verticalL, const Line line)
{
    double x     = verticalL.origin.getX();
    double slope = Geometry::getSlope(line.angle);
    double b     = line.origin.getY() - (slope * line.origin.getX());
    double y     = (x * slope) + b;

    return new Point(x, y);
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
    double x, y;
    double b1, b2;
    double slope1, slope2;

    // Même droite ou parallèles
    if ((*this == l) ||
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
   if (std::abs(std::fmod(this->angle, M_PI)) == (M_PI_2))
   {
       *intersection = verticalLineIntersection(*this, l);
   }
   else if (std::abs(std::fmod(l.angle, M_PI)) == (M_PI_2))
   {
       *intersection = verticalLineIntersection(l, *this);
   }
   else
   {
       slope1 = Geometry::getSlope(this->angle);
       slope2 = Geometry::getSlope(l.angle);
       b1     = this->origin.getY() - (slope1 * l.origin.getX());
       b2     = l.origin.getY()     - (slope2 * l.origin.getX());
       x     = (b2 - b1) / (slope1 - slope2);
       y     = (slope2 * x) + b2;

       *intersection = new Point(x, y);
   }

   return true;

}

bool Line::intersects(const LineSegment &ls, Point ** intersection)
{
    Point start = ls.getStart();
    Point end = ls.getEnd();
    double rad = Geometry::getAngle(start, end);

    if ((intersects(Line(start, rad), intersection)) &&
         (Geometry::isInBoundingBox(**intersection, ls)))
            return true;
    

    delete *intersection;
    *intersection = nullptr;
    return false;
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

