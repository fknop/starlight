#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <vector>

#include "model/line.h"
#include "model/linesegment.h"
#include "model/point.h"


/**
 * Classe Ellipse
 * La position représente la position du centre de l'ellipse.
 * du rectangle entourant l'ellipse.
 * Le x_rad_ correspond au rayon sur l'axe des X.
 * Le y_rad_ correspond au rayon sur l'axe des Y.
 */
class Ellipse
{

private:
    Point center_;
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


    /**
     * Retourne le point central de l'ellipse.
     * @return le centre de l'ellipse.
     */
    inline const Point& center() const;

    /**
     * Retourne le rayon sur l'axe X.
     * @return le rayon sur l'axe X.
     */
    inline double x_rad() const;

    /**
     * Retourne le rayon sur l'axe Y.
     * @return le rayon sur l'axe Y.
     */
    inline double y_rad() const;

};

/* Fonctions inline */

const Point& Ellipse::center() const
{
    return this->center_;
}

double Ellipse::x_rad() const
{
    return this->x_rad_;
}

double Ellipse::y_rad() const
{
    return this->y_rad_;
}

#endif // ELLIPSE_H
