#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "model/point.h"
#include "model/line.h"

/**
 * Modélise un segment de droite
 * possédant un point de départ et un point
 * d'arrivée.
 */
class LineSegment
{
    Point start_ {0,0};
    Point end_ {1,1};

public:


    LineSegment() = default;

    /**
     * Instancie un segment de droite sur base de 2 points.
     * @param start une extrémité du segment.
     * @param end la seconde extrémité du segment.
     */
    LineSegment(const Point& start, const Point& end);

    /**
     * Retourne la première extrémité du segment.
     * @return la première extrémité du segment.
     */
    inline const Point& start() const;

    /**
     * Retourne la seconde extrémité du segment.
     * @return la seconde extrémité du segment.
     */
    inline const Point& end() const;

    /**
     * Modifie le point de début du segment.
     * @param start le nouveau point de début du segment.
     */
    inline void set_start(const Point& start);

    /**
     * Modifie le point de fin du segment.
     * @param end le nouveau point de fin du segment.
     */
    inline void set_end(const Point& end);

    /**
     * Vérifie si un point est sur un segment.
     * @param p le point à vérifier.
     * @param ls le segment sur lequel vérifier.
     * @return vrai si le point est sur le segment, faux sinon.
     */
    bool contains(const Point& point) const;

    /**
     * Transforme le segment en droite.
     * @return la droite correspondante au segment.
     */
    Line to_line() const;

    /**
     * Déplace le segment.
     * @param x le déplacement sur l'axe x.
     * @param y le déplacement sur l'axe y.
     */
    void translate(const double x, const double y);

    /**
     * Effectue une rotation sur le segment selon un point
     * de pivot situé sur ce dernier.
     * @param pivot le point de rotation.
     * @param angle l'angle de rotation.
     */
    void rotate(const Point& pivot, double angle);

    /**
     * Redéfinition de l'opérateur d'égalité.
     * Retourne vrai si les segments sont égaux.
     * Les segments sont agaux si les extrémités
     * sont égales peu importe le sens.
     * @param ls un segment.
     * @return vrai si les segments sont égaux, faux sinon.
     */
    bool operator==(const LineSegment& ls) const;
};

/* Fonctions inline */

const Point& LineSegment::start() const
{
    return this->start_;
}

const Point& LineSegment::end() const
{
    return this->end_;
}

void LineSegment::set_start(const Point& start)
{
    this->start_ = start;
}

void LineSegment::set_end(const Point& end)
{
    this->end_ = end;
}

#endif // LINESEGMENT_H
