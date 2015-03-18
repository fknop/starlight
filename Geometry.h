#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "metier_abs/point.h"
#include <cmath>
#define M_PI 3.14159265358979323846


class Geometry
{
public:
    Geometry();

    /**
     * Transforme des radiants en degrés.
     * @param rad un angle en radiants.
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
     * Transforme un angle en radiant en une pente.
     * @param rad l'angle en radiant.
     * @return la pente d'un angle.
     */
    static double getSlopeFromRadiant(double rad);

    /**
     * Retourne la distance entre deux points.
     * @param p1 le premier point.
     * @param p2 le deuxième point.
     * @return la distance entre deux points.
     */
    static double getDistance(const Point& p1, const Point& p2);
};

#endif // GEOMETRY_H