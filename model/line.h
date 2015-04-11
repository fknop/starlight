#ifndef LINE_H
#define LINE_H

#include <cstddef>

#include "linesegment.h"
#include "point.h"

/*
 * y = (-y*b)x + -a/y
 * a = - by - c / x
 * ax + by + c = 0;
 * pente = -a / b
 * terme = -c / b
 *
 * y = -ax -c / b
 * y = -a/b
 * x = -c/b
 * Verticale si b = 0
 * |a/b| > infini
 */

/**
 * Cette classe représente une droite.
 * Elle possède un point d'origine et un
 * angle. De cette manière on peut
 * trouver n'importe quel point se trouvant
 * sur la droite en ayant une distance.
 */
class Line
{
    Point origin_;
    double angle_;

public:
    /**
     * Instancie une droite, avec un point donné et
     * un angle en radians correspondant à la pente.
     * @param origin un point de la droite.
     * @param angle l’angle de la pente.
     */
    Line(const Point& origin, double angle);

    /**
     * Instancie une droite avec deux points donnés.
     * @param p1 un premier point de la droite.
     * @param p2 un deuxième point de la droite.
     */
    Line(const Point& p1, const Point& p2);

    /**
     * Renvoie un point de la droite.
     * @return un point de la droite.
     */
    inline const Point& origin() const;

    /**
     * Modifie le point d'origine de la droite.
     * @param origin le nouveau point d'origine.
     */
    inline void set_origin(const Point& origin);

    /**
     * Retourne la pente de la droite.
     * @return la pente de la droite.
     */
    inline double angle() const;

    /**
     * Modifie l'angle de la droite.
     * @param le nouvel angle en radians de la droite.
     */
    inline void set_angle(double rad);

    double get_x(double y) const;
    double get_y(double x) const;

    /**
     * Redéfinition de l'opérateur d'égalité, renvoie vrai
     * si les deux droites ont le même angle et point
     * d'origine.
     * @param l1 la première droite.
     * @param l2 la deuxième droite.
     * @return vrai si les droites sont égales, faux sinon.
     */
    friend bool operator==(const Line& l1, const Line& l2);

private:
    static bool vertical_line_intersection(const Line& l1, const Line& l2,
                                              Point** intersection);
};

/* Fonctions inlines */


const Point& Line::origin() const
{
    return this->origin_;
}

void Line::set_origin(const Point &origin)
{
    this->origin_ = origin;
}

double Line::angle() const
{
    return this->angle_;
}

void Line::set_angle(double angle)
{
    this->angle_ = angle;
}

#endif // LINE_H
