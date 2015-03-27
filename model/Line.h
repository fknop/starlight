#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <cstddef>


/**
 * Droite de la forme D ≡ ax + by + c = 0
 * @param p un point de la ligne.
 * @param rad l'
 */
class Line
{
    Point p;
    double slope;
    double b;

public:
    /**
     * Instancie une droite, avec un point donné et
     * un angle donné correspondant à la pente.
     * @param p un point de la droite.
     * @param rad l’angle de la pente.
     */
    Line(const Point& p, double rad);

    /**
     * Instancie une droite avec deux points donnés.
     * @param p1 un premier point de la droite.
     * @param p2 un deuxième point de la droite.
     */
    Line(const Point& p1, const Point& p2);


    /**
     * Obtient un point d’intersection entre la droite
     * et une autre droite donnée.
     * @param l une autre droite.
     * @return un point d’intersection entre les deux droites ou
     * null s’il n’y a pas d’intersection.
     */
    Point* getIntersection(const Line& l) const;

    /**
     * Renvoie un point de la droite.
     * @return un point de la droite.
     */
    const Point& getPoint() const;

    /**
     * Retourne l’ordonnée à l’origine.
     * @return l’ordonnée à l’origine.
     */
    double getB() const;

    /**
     * Retourne la pente de la droite.
     * @return la pente de la droite.
     */
    double getSlope() const;
};

#endif // LINE_H
