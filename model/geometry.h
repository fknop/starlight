#ifndef GEOMETRY_H
#define GEOMETRY_H


#include <cmath>
#include <vector>

#include "model/line.h"
#include "model/linesegment.h"
#include "model/point.h"
#include "model/ellipse.h"
#include "model/rectangle.h"

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

    bool is_on_good_side(const Line& l, const Point &ref, const Point& p);

    /**
     * Retourne vrai si la droite possède une intersection
     * avec une autre droite et retourne également
     * le point d'intersection en paramètre et met
     * is_point à vrai si l'intersection est un point.
     * @param l1 la première droite.
     * @param l2 la deuxième droite.
     * @param point le point d'intersection.
     * @param is_point vrai si l'intersection est un point, faux sinon.
     * @return vrai si les droites possèdent une intersection.
     */
    bool intersects(const Line& l1, const Line& l2, Point& point, bool& is_point);
//    bool intersects(const Line& l1, const Line& l2, Point **p);

    /**
     * Retourne vrai si la droite possède une intersection
     * avec un segment et retourne également
     * le point d'intersection en paramètre.
     * @param line la droite
     * @param ls le segment.
     * @param intersecion le point d'intersection.
     * @return vrai si la droite et le segment possède une intersection.
     */
      bool intersects(const Line& line, const LineSegment& ls, Point& point, LineSegment &segment, bool& is_point);
      bool intersects(const LineSegment& ls1, const LineSegment& ls2, Point& point, bool& is_point);
//    bool intersects(const Line& line, const LineSegment& ls, Point **p);
//    bool intersects(const LineSegment& ls1, const LineSegment& ls2, Point **p);

    /**
     * Vérifie si une droite possède une ou des intersections
     * avec l'ellipse.
     * @param ellipse l'ellipse
     * @param l la droite.
     * @param points un vecteur de points d'intersections.
     * @return le nombre d'intersections entre l'ellipse et la droite.
     */
    int intersects(const Ellipse& ellipse, const Line& line,
                   std::vector<Point> &points);

    /**
     * Vérifie si un segment de droite possède une ou des
     * intersections avec l'ellipse.
     * @param ellipse l'ellipse.
     * @param l le segment de droite.
     * @param points un vecteur de points d'intersections.
     * @return le nombre d'intersections entre l'ellipse et la droite.
     */
    int intersects(const Ellipse& ellipse, const LineSegment& ls,
                   std::vector<Point> &points);

    /**
     * Vérifie si une droite coupe un rectangle.
     * @param rec le rectangle.
     * @param line la droite.
     * @param points le vecteur de points d'intersections trouvés.
     * @return le nombre d'intersections.
     */
    int intersects(const Rectangle& rec, const Line& line,
                   std::vector<Point> &points);

    /**
     * Vérifie si un segment de droite coupe un rectangle.
     * @param rec le rectangle.
     * @param ls le segment de droite.
     * @param points le vecteur de points d'intersections trouvés.
     * @return le nombre d'intersections.
     */
    int intersects(const Rectangle& rec, const LineSegment& ls,
                   std::vector<Point>& points);

    bool vertical_line_intersection(const Line& l1, const Line& l2,
                                                  Point** intersection);


} // namespace Geometry

#endif // GEOMETRY_H
