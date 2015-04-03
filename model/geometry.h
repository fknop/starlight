#ifndef GEOMETRY_H
#define GEOMETRY_H


#include <cmath>
#include <vector>

#include "line.h"
#include "linesegment.h"
#include "point.h"
#include "constants.h"

namespace Geometry
{
    /**
     * Retourne l'angle en degrés d'un angle
     * donné en radians.
     * @param rad l'angle en radians.
     * @return l'angle en degrés.
     */
    double rad_to_deg(double rad);

    /**
     * Retrouve la pente d'un segment entre deux points.
     * @param p1 le premier point.
     * @param p2 le deuxième point.
     * @return la pente du segment constitué des deux points donnés.
     */
    double rad_to_slope(const Point& p1, const Point& p2);

    /**
     * Transforme un angle en radian en une pente.
     * @param rad l'angle en radian.
     * @return la pente d'un angle.
     */
    double rad_to_slope(double rad);


    /**
     * Retourne l'angle en radians de la pente du segment
     * qui rejoint deux points.
     * @param p1 le premier point.
     * @param p2 le dexième point.
     * @return l'angle en radians de la pente.
     */
    double slope_to_rad(const Point& p1, const Point& p2);

    /**
     * Retourne l'angle en radians de la pente donnée.
     * @param slope la pente.
     * @return l'angle en radians de la pente donnée.
     */
    double slope_to_rad(double slope);

    /**
     * Retourne l'angle en radians d'un angle donné
     * en degrés.
     * @param degrees l'angle en degrés.
     * @return l'angle en radians.
     */
    double deg_to_rad(double degrees);

} // namespace Geometry

#endif // GEOMETRY_H
