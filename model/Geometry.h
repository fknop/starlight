#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "point.h"
#include <cmath>
#include <vector>
#include "linesegment.h"
#include "Line.h"


namespace Geometry
{


    #define M_PI 3.141592653589793238463

    /**
     * Transforme des radians en degrés.
     * @param rad un angle en radians.
     * @return un angle en degrés.
     */
    double getDegrees(double rad);

    /**
     * Retrouve la pente d'un segment entre deux points.
     * @param p1 le premier point.
     * @param p2 le deuxième point.
     * @return la pente du segment constitué des deux points donnés.
     */
    double getSlope(const Point& p1, const Point& p2);

    /**
     * Transforme un angle en radian en une pente.
     * @param rad l'angle en radian.
     * @return la pente d'un angle.
     */
    double getSlope(double rad);


    /**
     * Vérifie si un point est sur un segment.
     * @param p le point à vérifier.
     * @param ls le segment sur lequel vérifier.
     * @return vrai si le point est sur le segment, faux sinon.
     */
    bool isInBoundingBox(const Point& p, const LineSegment& ls);

    /**
     * Retourne le point d’intersection entre une ligne et un segment.
     * @param l une ligne.
     * @param li un segment.
     * @return le point d’intersection entre la ligne et le segment.
     */
    Point* getIntersection(const Line& l, const LineSegment& li);

    double getAngle(const Point& p1, const Point& p2);

    double getAngle(double slope);

    double getRadians(double degrees);
}

#endif // GEOMETRY_H
