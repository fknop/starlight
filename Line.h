#ifndef LINE_H
#define LINE_H

#include "metier_abs/point.h"
#include "Geometry.h"
#include <cstddef>

/* y = ax + b où y = p.y, x = p.x, a = slope, b = b */
class Line
   {
       Point p;
       double slope;
       double b;

       public:
           Line(const Point&, double);
           Line(const Point&, const Point&); // Créer avec 2 points, retrouver la pente et garder un point.
           Point* getIntersection(const Line&);
           const Point& getPoint() const;
           double getB() const;
           double getSlope() const;
   };



#endif // LINE_H
