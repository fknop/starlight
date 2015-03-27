#ifndef POLARPOINT_H
#define POLARPOINT_H

#include "point.h"

class PolarPoint
{

private:
    double distance;
    double angle;
public:

    /**
     * Instancie un nouveau point à coordonnées polaires.
     * @param p le point à transformer.
     */
    PolarPoint(const Point & p);

    /**
     * Instancie un nouveau point à coordonnées polaires
     * avec la distance et l'angle donnés.
     * @param distance la distance par rapport à l'origine du répère.
     * @param angle l'angle par rapport à l'origine du repère.
     */
    PolarPoint(double distance, double angle);

    ~PolarPoint();

    /**
     * Modifie l'angle du point polaire.
     * Le point est donc déplacé par rapport aux coordonnées
     * cartésiennes.
     * @param a le nouvel angle.
     */
    void setAngle(double a);

    /**
     * Modifie la distance du point polaire.
     * Le point est donc déplacé par rapport aux  coordonnées
     * cartésiennes.
     * @param d la nouvelle distance.
     */
    void setDistance(double d);

    /**
     * Retourne l'angle.
     * @return l'angle.
     */
    double getAngle() const;

    /**
     * Retourne la distance.
     * @return la distance.
     */
    double getDistance() const;

    /**
     * Transforme le point polaire en point cartésien.
     * @return le point cartésien correspondant au point polaire.
     */
    Point * toPoint();


};

#endif // POLARPOINT_H
