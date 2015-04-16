#ifndef MIRROR_H
#define MIRROR_H

#include <ostream>

#include "model/element.h"
#include "model/linesegment.h"
#include "model/point.h"

#include "obs/observable.h"

/**
 * Cette classe modélise les miroirs utilisés dans le jeu.
 * </p>
 * Un miroir est un segment de droite dont la propriété est
 * de réfléchir la lumière d'un seul côté uniquement. Si un
 * rayon lumineux touche un miroir du côté non réfléchissant,
 * le miroir se comporte comme un mur.
 * </p>
 * Les miroirs sont capables d'être déplacés et pivotés dans
 *  une certaine limite.
 */
class Mirror : public Element, public Observable
{
    Point pivot_;
    double length_;
    double xpad_;
    double x_min_ {.0};
    double x_max_ {.0};
    double y_min_ {.0};
    double y_max_ {.0};
    double alpha_;
    double alpha_min_ {.0};
    double alpha_max_ {.0};
    bool movable_ {true};

  public:
    /**
     * Instancie un miroir en une position donnée, d'une certaine
     * longueur et orienté d'un certain angle.
     * </p>
     * Comme dans ce constructeur les limites de déplacement et
     * de rotation du miroir ne sont pas définies, ce miroir
     * peut se déplacer et pivoter librement.
     * @param p la position (et le point de pivot) du miroir.
     * @param len la longueur du miroir.
     * @param x le décalage du pivot par rapport au bord gauche
     *          du miroir.
     * @param a l'angle d'inclinaison du miroir.
     */
    Mirror(const Point& p, double xpad, double len, double alpha);

    /**
     * Instancie un miroir en une position donnée, d'une certaine
     * longueur et orienté d'un certain angle.
     * </p>
     * Ce constructeur permet également aux miroirs de pivoter
     * dans une certaine limite.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que
     * a < b, le miroir pivote dans le sens horloger, si a = b le
     * miroir ne peut pas pivoter, si a > b, le miroir
     * pivote dans le sens anti-horloger.
     * @param p la position (et le point de pivot) du miroir.
     * @param len la longueur du miroir.
     * @param x le décalage du pivot par rapport au bord gauche
     *          du miroir.
     * @param a l'angle d'inclinaison du miroir.
     * @param min l'abscisse et l'ordonnée minimum du miroir.
     * @param max l'abscisse et l'ordonnée maximum du miroir.
     * @param amin l'angle d'inclinaison minimum du miroir.
     * @param amax l'angle d'inclinaison maximum du miroir.
     */
    Mirror(const Point& p, double xpad, double len, double alpha,
           const Point& min, const Point& max, double alpha_min, double alpha_max);


    /**
     * Retourne la position (et le pivot) du miroir.
     * @return la position (et le pivot) du miroir.
     */
    inline const Point& pivot() const;

    /**
     * Retourne la longueur du miroir.
     * @return la longueur du miroir
     */
    inline double length() const;

    /**
     * Retourne le décalage du pivot par rapport au bord gauche
     * du miroir.
     * @return le décalage du pivot par rapport au bord gauche
     * du miroir.
     */
    inline double x_pad() const;

    /**
     * Retourne l'inclinaison du miroir.
     * @return l'inclinaison du miroir.
     */
    inline double angle() const;

    /**
     * Retourne l'inclinaison minimum du miroir.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel que
     * a < b, le miroir pivote dans le sens horloger, si a = b
     * le miroir ne peut pas pivoter, si a > b, le miroir pivote
     * dans le sens anti-horloger. Si a = b = 0, le miroir peut
     * être pivoté librement.
     * @return l'inclinaison minimum du miroir.
     */
    inline double min_angle() const;

    /**
     * Retourne l'inclinaison maximum du miroir.
     * </p>
     * Si l'intervalle de limite d'inclinaison [a,b] est tel
     * que a < b, le miroir pivote dans le sens horloger, si
     * a = b le miroir ne peut pas pivoter, si a > b, le miroir
     * pivote dans le sens anti-horloger. Si a = b = 0, le miroir
     * peut être pialphaMax_voté librement.
     * @return l'inclinaison minimum du miroir.
     */
    inline double max_angle() const;

    /**
     * Retourne la position minimum du miroir.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré. Si a = b = 0, le miroir
     * peut être déplacé librement.
     * @return la position minimum du miroir.
     */
    inline Point min_pivot() const;

    /**
     * Retourne la position maximum du miroir.
     * </p>
     * Si l'intervalle de limite de déplacement (e.g., sur les
     * abscisses) [a,b] est tel que a = b, le miroir ne peut
     * être déplacé sur l'axe considéré. Si a = b = 0, le miroir
     * peut être déplacé librement.
     * @return la position maximum du miroir.
     */
    inline Point max_pivot() const;

    /**
     * Déplace le miroir en la position donnée, si c'est
     * autorisé. Retourne vrai si le déplacement a été
     * effectué correctement, retourne faux sinon.
     * @return vrai si le déplacement a été effectué
     * correctement, retourne faux sinon.
     * @see Mirror::getPivot()
     */
    inline bool set_pivot(const Point& pivot);

    /**
     * Modifie le décalage du pivot par rapport au bord gauche du miroir.
     * @param x le nouveau décalage.
     */
    inline void set_xpad(const double x);

    /**
     * Modifie la longueur du miroir.
     * @param len la nouvelle longueur du miroir.
     */
    inline void set_len(const double len);

    /**
     * Modifie la position minimale du miroir.
     * @param x abscisse minimale du miroir.
     * @param y ordonnée minimale du miroir.
     */
    inline void set_min(const Point& min);

    /**
     * Modifie la position maximale du miroir.
     * @param x abscisse maximale du miroir.
     * @param y ordonnée maximale du miroir.
     */
    inline void set_max(const Point& max);

    /**
     * Modifie l’angle d’inclinaison minimum du miroir.
     * @param amin le nouvel angle d’inclinaison minimal.
     */
    inline void set_alpha_min(const double min);

    /**
     * Modifie l’angle d’inclinaison maximum du miroir.
     * @param amax le nouvel angle d’inclinaison maximal.
     */
    inline void set_alpha_max(const double max);

    /**
     * Pivote le miroir sur un angle donné, si c'est
     * autorisé. Retourne vrai si la rotation a été effectuée
     * correctement, retourne faux sinon.
     * @return vrai si la rotation a été effectuée
     * correctement, retourne faux sinon.
     * @see Mirror::getAngle()
     */
    inline bool set_angle(const double angle);

    /**
     * Modifie le comportement du miroir.
     * @param value vrai si le miroir peut être
     * déplacé ou tourné, faux sinon.
     */
    inline void set_movable(const bool value);

    /**
     * Retourne vrai si le miroir peut être déplacé
     * ou tourné.
     * @return vrai si le miroir peut être déplacé
     * ou tourné.
     */
    inline bool movable() const;

    /**
     * Retoune vrai si le miroir peut être pivoté sur
     * l'angle donné, retourne faux sinon.
     * @return vrai si le miroir peut être pivoté sur
     * l'angle donné, retourne faux sinon.
     * @see Mirror::getAngle()
     */
    bool check_angle_range(double angle) const;

    /**
     * Retoune vrai si le miroir peut être déplacé en la
     * position donnée, retourne faux sinon.
     * @return vrai si le miroir peut être déplacé en
     * la position donnée, retourne faux sinon.
     * @see Mirror::getPivot()
     */
    bool check_pivot_range(const Point& pivot) const;

    /**
     * Modifie l'inclinaison de l'angle
     * @param l'inclinaison à ajouter.
     */
    void rotate(double angle);


    /**
     * Déplace le pivot par rapport à une ordonnée et une abscisse.
     * @param x l'abscisse.
     * @param y l'ordonnée.
     */
    void translate(const double x, const double y);

    /**
     * Renvoie le segment correspondant au miroir.
     * @return le segment correspondant au miroir.
     */
    LineSegment to_line_segment() const;

    /**
     * Surcharge l'opérateur de flux de sortie pour
     * afficher un récapitulatif des caractéristiques du
     * miroir sous-jacent en console.
     * @return le flux dans lequel le miroir a été imprimé
     */
    friend std::ostream& operator<<(std::ostream& out,
                                     const Mirror& m);

    /**
     * Redéfinition de l'opérateur d'égalité.
     * Retourne vrai si les mirroirs sont égaux.
     * @param m un mirroir.
     * @return vrai si les mirroirs sont égaux, faux sinon.
     */
    bool operator==(const Mirror& m) const;

};

/* Fonctions inlines */


const Point& Mirror::pivot() const
{
    return pivot_;
}

double Mirror::length() const
{
    return length_;
}

double Mirror::x_pad() const
{
    return xpad_;
}

double Mirror::angle() const
{
    return alpha_;
}

double Mirror::min_angle() const
{
    return alpha_min_;
}

double Mirror::max_angle() const
{
    return alpha_max_;
}

Point Mirror::min_pivot() const
{
    return Point {x_min_, y_min_};
}

Point Mirror::max_pivot() const
{
    return Point {x_max_, y_max_};
}

bool Mirror::set_pivot(const Point& p)
{
    bool r {check_pivot_range(p)};
    if (r)
        pivot_ = p;
    return r;
}

void Mirror::set_xpad(const double x)
{
    if (x > length_)
        xpad_ = length_;

    if (x < 0)
        xpad_ = 0;

    xpad_ = x;
}

void Mirror::set_len(const double len)
{
    length_ = len;
    if (length_ > xpad_)
        xpad_ = length_;
}

void Mirror::set_min(const Point& min)
{
    x_min_ = min.x();
    y_min_ = min.y();

    if (!check_pivot_range(pivot_))
    {
        if (pivot_.x() < x_min_)
            pivot_.set_x(x_min_);

        if (pivot_.y() < y_min_)
            pivot_.set_y(y_min_);
    }
}

void Mirror::set_max(const Point& max)
{
    x_max_ = max.x();
    y_max_ = max.y();
    if (!check_pivot_range(pivot_))
    {
        if (pivot_.x() > x_max_)
            pivot_.set_x(x_max_);

        if (pivot_.y() > y_max_)
            pivot_.set_y(y_max_);
    }
}

void Mirror::set_alpha_min(const double min)
{
    alpha_min_ = min;

    if (!check_angle_range(alpha_))
        alpha_ = alpha_min_;
}

void Mirror::set_alpha_max(const double max)
{
    alpha_max_ = max;

    if (!check_angle_range(alpha_))
        alpha_ = alpha_max_;
}

bool Mirror::set_angle(const double a)
{
    bool r {check_angle_range(a)};
    if (r)
        this->alpha_ = a;
    return r;
}

void Mirror::set_movable(const bool value)
{
    movable_ = value;
}

bool Mirror::movable() const
{
    return movable_;
}

#endif // MIRROR_H
