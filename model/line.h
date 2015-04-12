#ifndef LINE_H
#define LINE_H

#include <cstddef>
#include <cmath>
#include "point.h"
#include "umath.h"

///*
// * y = (-y*b)x + -a/y
// * a = - by - c / x
// * ax + by + c = 0;
// * pente = -a / b
// * terme = -c / b
// *
// * y = -ax -c / b
// * y = -a/b
// * x = -c/b
// * Verticale si b = 0
// * |a/b| > infini
// */

///**
// * Cette classe représente une droite.
// * Elle possède un point d'origine et un
// * angle. De cette manière on peut
// * trouver n'importe quel point se trouvant
// * sur la droite en ayant une distance.
// */
//class Line
//{
//    Point origin_;
//    double angle_;

//public:
//    /**
//     * Instancie une droite, avec un point donné et
//     * un angle en radians correspondant à la pente.
//     * @param origin un point de la droite.
//     * @param angle l’angle de la pente.
//     */
//    Line(const Point& origin, double angle);

//    /**
//     * Instancie une droite avec deux points donnés.
//     * @param p1 un premier point de la droite.
//     * @param p2 un deuxième point de la droite.
//     */
//    Line(const Point& p1, const Point& p2);

//    /**
//     * Renvoie un point de la droite.
//     * @return un point de la droite.
//     */
//    inline const Point& origin() const;

//    /**
//     * Modifie le point d'origine de la droite.
//     * @param origin le nouveau point d'origine.
//     */
//    inline void set_origin(const Point& origin);

//    /**
//     * Retourne la pente de la droite.
//     * @return la pente de la droite.
//     */
//    inline double angle() const;

//    /**
//     * Modifie l'angle de la droite.
//     * @param le nouvel angle en radians de la droite.
//     */
//    inline void set_angle(double rad);

//    double get_x(double y) const;
//    double get_y(double x) const;

//    /**
//     * Redéfinition de l'opérateur d'égalité, renvoie vrai
//     * si les deux droites ont le même angle et point
//     * d'origine.
//     * @param l1 la première droite.
//     * @param l2 la deuxième droite.
//     * @return vrai si les droites sont égales, faux sinon.
//     */
//    friend bool operator==(const Line& l1, const Line& l2);

//private:
//    static bool vertical_line_intersection(const Line& l1, const Line& l2,
//                                              Point** intersection);
//};

///* Fonctions inlines */


//const Point& Line::origin() const
//{
//    return this->origin_;
//}

//void Line::set_origin(const Point &origin)
//{
//    this->origin_ = origin;
//}

//double Line::angle() const
//{
//    return this->angle_;
//}

//void Line::set_angle(double angle)
//{
//    this->angle_ = angle;
//}
class Line
{
    double a_;
    double b_;
    double c_;

    double alpha_;

    public:

    Line(double a, double b, double c);
    Line(const Point& a, const Point& b);
    Line(const Point& a, double alpha);

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
