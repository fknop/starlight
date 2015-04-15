#ifndef LINE_H
#define LINE_H

#include <cstddef>
#include <cmath>

#include "model/point.h"
#include "model/umath.h"

/**
 * Cette classe représente une droite
 * sous la forme ax + by + c = 0.
 * Elle possède également un attribut
 * alpha_ pour préciser l'angle réel de la droite.
 * Si on veut travailler avec des angles négatifs
 * par exemple.
 */
class Line
{
    double a_;
    double b_;
    double c_;

    double alpha_;

    public:

    /**
     * Instancie une nouvelle droite avec les
     * trois paramètres a, b et c donnés.
     * @param a a
     * @param b b
     * @param c c
     */
    Line(double a, double b, double c);

    /**
     * Instancie une nouvelle droite avec deux
     * points donnés.
     * @param a le premier point.
     * @param b le deuxième point.
     */
    Line(const Point& a, const Point& b);

    /**
     * Instancie une nouvelle droite avec un
     * point donné et un angle donné.
     * @param p le point de la droite
     * @param alpha l'angle de la droite
     */
    Line(const Point& p, double alpha);

    /**
     * Retourne a.
     * @return a.
     */
    inline double a() const;

    /**
     * Retourne b.
     * @return b.
     */
    inline double b() const;

    /**
     * Retourne c.
     * @return c.
     */
    inline double c() const;

    /**
     * Retourne l'angle produit par la pente de la droite.
     * @return l'angle produit par la pente de la droite.
     */
    inline double alpha() const;

    /**
     * Retourne la pente de la droite.
     * @return la pente de la droite.
     */
    inline double slope() const;


    /**
     * Retourne le x d'un y donné.
     * Retourne INF (infini) si la droite
     * est horizontale (a = 0) et met
     * is_horizontal à true.
     * @return x si la droite n'est pas horizontale, INF sinon.
     */
    inline double get_x(double y) const;

    /**
     * Retourne le y d'un x donné.
     * Retourne INF (infini) si la droite
     * est verticale (b = 0) et met
     * is_vertical à true.
     * @return y si la droite n'est pas verticale, INF sinon.
     */
    inline double get_y(double x) const;


    /**
     * Retourne vrai si la droite est verticale
     * @return vrai si la droite est verticale, faux sinon.
     */
    inline bool vertical() const;

    /**
     * Retourne vrai si la droite est horizontale.
     * @return vrai si la droite est horizontale, faux sinon.
     */
    inline bool horizontal() const;

    /**
     * Retourne vrai si une droite est parallèle ou confondu
     * à la droite.
     * @return vrai si une droite est parallèle ou confondu
     * à la droite, faux sinon.
     */
    inline bool parallel(const Line& l) const;

    /**
     * Retourne vrai si une droite est perpendiculaire
     * à la droite.
     * @return vrai si une droite est perpendiculaire
     * à la droite, faux sinon.
     */
    inline bool perpendicular(const Line& l) const;

    /**
     * Redéfinition de l'opérateur d'égalité.
     * Retourne vrai si la droite est confondu à
     * une autre droite.
     * @return vrai si la droite est confondu à une
     * autre droite.
     */
    inline bool operator==(const Line& l) const;

};


// Méthodes inlines

double Line::a() const
{
    return this->a_;
}
double Line::b() const
{
    return this->b_;
}
double Line::c() const
{
    return this->c_;
}

double Line::alpha() const
{
    return this->alpha_;
}

double Line::slope() const
{
    return -a_ / b_;
}

double Line::get_x(double y) const
{
    return ((-b_ * y) - c_) / a_;
}

double Line::get_y(double x) const
{
    return ((-a_ * x) -c_) / b_;
}

bool Line::vertical() const
{
    return umath::equals(b_, 0);
}

bool Line::horizontal() const
{
    return umath::equals(a_, 0);
}

bool Line::parallel(const Line& l) const
{
    return (!this->perpendicular(l) &&
            umath::equals(((a_ * l.b()) - (l.a() * b_)), 0));
}

bool Line::perpendicular(const Line& l) const
{
    return umath::equals((a_ * l.a_) + (b_ * l.b_), 0);
}

bool Line::operator==(const Line& l) const
{
    return this->parallel(l) &&
           umath::equals(c_ / b_, l.c_ / l.b_);
}


#endif // LINE_H
