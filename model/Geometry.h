#ifndef GEOMETRY_H
#define GEOMETRY_H


#include <cmath>
#include <vector>

#include "line.h"
#include "linesegment.h"
#include "point.h"


// Pour les utilisateurs de windows,
// M_PI n'est pas défini de base dans cmath.
#ifndef M_PI
    #define M_PI 3.141592653589793238463
#endif
#ifndef M_PI_2
    #define M_PI_2 M_PI / 2
#endif

namespace Geometry
{
    /**
     * Retourne l'angle en degrés d'un angle
     * donné en radians.
     * @param rad l'angle en radians.
     * @return l'angle en degrés.
     */
    double get_degrees(double rad);

    /**
     * Retrouve la pente d'un segment entre deux points.
     * @param p1 le premier point.
     * @param p2 le deuxième point.
     * @return la pente du segment constitué des deux points donnés.
     */
    double get_slope(const Point& p1, const Point& p2);

    /**
     * Transforme un angle en radian en une pente.
     * @param rad l'angle en radian.
     * @return la pente d'un angle.
     */
    double get_slope(double rad);


    /**
     * Vérifie si un point est sur un segment.
     * @param p le point à vérifier.
     * @param ls le segment sur lequel vérifier.
     * @return vrai si le point est sur le segment, faux sinon.
     */
    bool is_in_bounding_box(const Point& p, const LineSegment& ls);

    /**
     * Retourne l'angle en radians de la pente du segment
     * qui rejoint deux points.
     * @param p1 le premier point.
     * @param p2 le dexième point.
     * @return l'angle en radians de la pente.
     */
    double angle(const Point& p1, const Point& p2);

    /**
     * Retourne l'angle en radians de la pente donnée.
     * @param slope la pente.
     * @return l'angle en radians de la pente donnée.
     */
    double angle(double slope);

    /**
     * Retourne l'angle en radians d'un angle donné
     * en degrés.
     * @param degrees l'angle en degrés.
     * @return l'angle en radians.
     */
    double radians(double degrees);

} // namespace Geometry

#endif // GEOMETRY_H
