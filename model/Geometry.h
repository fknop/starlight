#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "point.h"
#include <cmath>
#include <vector>
#include "linesegment.h"
#include "Line.h"


#define M_PI 3.14159265358979323846


class Geometry
{
public:
    Geometry();

    /**
     * Transforme des radians en degrés.
     * @param rad un angle en radians.
     * @return un angle en degrés.
     */
    static double radToDegree(double rad);

    /**
     * Retrouve la pente d'un segment entre deux points.
     * @param p1 le premier point.
     * @param p2 le deuxième point.
     * @return la pente du segment constitué des deux points donnés.
     */
    static double findSlope(const Point& p1, const Point& p2);

    /**
     * Transforme un angle en radian en une pente.
     * @param rad l'angle en radian.
     * @return la pente d'un angle.
     */
    static double getSlopeFromRadian(double rad);

    /**
     * Retourne la distance entre deux points.
     * @param p1 le premier point.
     * @param p2 le deuxième point.
     * @return la distance entre deux points.
     */
    static double getDistance(const Point& p1, const Point& p2);

    static bool isInBoundingBox(const Point& p, const LineSegment& ls);
    static Point* getIntersection(const Line&, const LineSegment&);
};

#endif // GEOMETRY_H
