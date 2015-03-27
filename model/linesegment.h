#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "point.h"

class LineSegment
{
    Point start;
    Point end;

public:
    /**
     * Instancie un segment de droite sur base de 2 points.
     * @param start une extrémité du segment.
     * @param end la seconde extrémité du segment.
     */
    LineSegment(const Point& start, const Point& end);

    /**
     * Retourne la première extrémité du segment.
     * @return la première extrémité du segment.
     */
    const Point& getStart() const;

    /**
     * Retourne la seconde extrémité du segment.
     * @return la seconde extrémité du segment.
     */
    const Point& getEnd() const;

    /**
     * Modifie le point de début du segment.
     * @param start le nouveau point de début du segment.
     */
    void setStart(const Point& start);

    /**
     * Modifie le point de fin du segment.
     * @param end le nouveau point de fin du segment.
     */
    void setEnd(const Point& end);
};

#endif // LINESEGMENT_H
