#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "point.h"
#include "linesegment.h"
#include "Line.h"
#include <vector>


/**
 * Classe Ellipse
 * La position représente la position du centre de l'ellipse.
 * du rectangle entourant l'ellipse.
 * Le xRadius correspond au rayon sur l'axe des X.
 * Le yRadius correspond au rayon sur l'axe des Y.
 */
class Ellipse
{

private:
    Point pos_;
    double x_rad_;
    double y_rad_;

public:

    /**
     * Crée une nouvelle ellipse.
     * @param p le coin supérieur gauche du rectangle entourant l'ellipse.
     * @param xRad le rayon sur l'axe des X.
     * @param yRad le rayon sur l'axe des Y.
     */
    Ellipse(const Point& p, double x, double y);
    ~Ellipse();

    /**
     * Vérifie si un segment de droite possède une ou des
     * intersections avec l'ellipse.
     * @param l le segment de droite.
     * @param points un vecteur de points d'intersections.
     * @return le nombre d'intersections entre l'ellipse et la droite.
     */
    int intersects(const LineSegment & ls, std::vector<Point>& points);

    /**
     * Vérifie si une droite possède une ou des intersections
     * avec l'ellipse.
     * @param l la droite.
     * @param points un vecteur de points d'intersections.
     * @return le nombre d'intersections entre l'ellipse et la droite.
     */
    int intersects(const Line& l, std::vector<Point> &points);


};

#endif // ELLIPSE_H
