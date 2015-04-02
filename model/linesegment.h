#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "point.h"

class LineSegment
{
    Point start_;
    Point end_;

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
    const Point& get_start() const;

    /**
     * Retourne la seconde extrémité du segment.
     * @return la seconde extrémité du segment.
     */
    const Point& get_end() const;

    /**
     * Modifie le point de début du segment.
     * @param start le nouveau point de début du segment.
     */
    void set_start(const Point& start);

    /**
     * Modifie le point de fin du segment.
     * @param end le nouveau point de fin du segment.
     */
    void set_end(const Point& end);
};

#endif // LINESEGMENT_H
