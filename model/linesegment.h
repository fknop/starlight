#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "point.h"

class LineSegment
{
    Point p1;
    Point p2;
    double slope;

public:
    /**
     * Instancie un segment de droite sur base de 2 points.
     * @param p1 une extrémité du segment.
     * @param p2 la seconde extrémité du segment.
     */
    LineSegment(const Point& p1, const Point& p2);

    /**
     * Retourne la première extrémité du segment.
     * @return la première extrémité du segment.
     */
    const Point& getP1() const;

    /**
     * Retourne la seconde extrémité du segment.
     * @return la seconde extrémité du segment.
     */
    const Point& getP2() const;

    /**
     * Retourne la pente du segment.
     * @return la pente du segment.
     */
    double getSlope() const;
};

#endif // LINESEGMENT_H
