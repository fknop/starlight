#ifndef POLARPOINT_H
#define POLARPOINT_H

#include "point.h"

class PolarPoint
{

private:
    double distance_;
    double angle_;

public:

    /**
     * Instancie un nouveau point à coordonnées polaires.
     * @param p le point à transformer.
     */
    PolarPoint(const Point& p);

    /**
     * Instancie un nouveau point à coordonnées polaires
     * avec la distance et l'angle donnés.
     * @param distance la distance par rapport à l'origine du répère.
     * @param angle l'angle par rapport à l'origine du repère.
     */
    PolarPoint(double distance, double angle);

    /**
     * Modifie l'angle du point polaire.
     * Le point est donc déplacé par rapport aux coordonnées
     * cartésiennes.
     * @param a le nouvel angle.
     */
    inline void set_angle(double a);

    /**
     * Modifie la distance du point polaire.
     * Le point est donc déplacé par rapport aux  coordonnées
     * cartésiennes.
     * @param d la nouvelle distance.
     */
    inline void set_distance(double d);

    /**
     * Retourne l'angle.
     * @return l'angle.
     */
    inline double angle() const;

    /**
     * Retourne la distance.
     * @return la distance.
     */
    inline double distance() const;

    /**
     * Transforme le point polaire en point cartésien.
     * @return le point cartésien correspondant au point polaire.
     */
    Point to_point();

    friend std::ostream& operator<<(std::ostream& out, const PolarPoint& p);


};

/* Fonctions inlines */


void PolarPoint::set_angle(double a)
{
    this->angle_ = a;
}

double PolarPoint::angle() const
{
    return this->angle_;
}

void PolarPoint::set_distance(double d)
{
    if (this->distance_ < 0)
      throw "La distance ne peut pas être négative";

    this->distance_ = d;
}

double PolarPoint::distance() const
{
    return this->distance_;
}

#endif // POLARPOINT_H
