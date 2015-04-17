#ifndef WALL_H
#define WALL_H

#include <iostream>

#include "model/element.h"
#include "model/linesegment.h"
#include "model/point.h"

#include "obs/observable.h"

/**
 * Cette classe modélise les murs utilisés dans le jeu.
 * </p>
 * Les murs sont des segments de droite qui ne réfléchissent
 * pas la lumière.
 */
class Wall : public Element, public Observable
{
    Point start_;
    Point end_;

    bool movable_;

  public:
    /**
     * Instancie un mur.
     * @param p1 le début du mur.
     * @param p2 la fin du mur.
     */
    Wall(const Point& p1, const Point& p2, bool movable = true);

    /**
     * Constructeur de copie.
     * @param wall le mur à copier.
     */
    Wall(const Wall& wall);

    /**
     * Retourne le début du mur.
     * @return le début du mur.
     */
    inline const Point& start() const;

    /**
     * Retourne la fin du mur.
     * @return la fin du mur.
     */
    inline const Point& end() const;

    inline bool movable() const;

    /**
     * Modifie le point de départ du mur.
     * @param s le point de départ.
     */
    inline void set_start(const Point& s);

    /**
     * Modifie le point de fin du mur.
     * @param e le point de fin du mur.
     */
    inline void set_end(const Point& e);

    /**
     * Renvoie le segment correspondant au mur.
     * @return le segment correspondant au mur.
     */
    LineSegment to_line_segment();

    /**
     * Déplace le mur.
     * @param x le déplacement sur l'axe des x.
     * @param y le déplacement sur l'axe des y.
     */
    void translate(double x, double y);

    /**
     * Tourne le mur par rapport à son centre.
     * @param r l'angle de rotation.
     */
    void rotate(double r);

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques du mur sous-jacent
     * en console.
     * @return le flux dans lequel le mur a été imprimé.
     */
    friend std::ostream& operator<<(std::ostream& out,
                                     const Wall& wall);

    /**
     * Redéfinition de l'opérateur d'égalité.
     * Retourne vrai si les murs sont égaux.
     * @param w un mur.
     * @return vrai si les murs sont égaux, faux sinon.
     */
    bool operator==(const Wall& w) const;

};

/* Fonctions inlines */

const Point& Wall::start() const
{
    return start_;
}

const Point& Wall::end() const
{
    return end_;
}

void Wall::set_start(const Point& s)
{
    start_ = s;
}

void Wall::set_end(const Point& e)
{
    end_ = e;
}

bool Wall::movable() const
{
    return movable_;
}

#endif // WALL_H
