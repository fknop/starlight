#ifndef WALL_H
#define WALL_H

#include <iostream>

#include "model/element.h"
#include "model/linesegment.h"
#include "model/point.h"


/**
 * Cette classe modélise les murs utilisés dans le jeu.
 * </p>
 * Les murs sont des segments de droite qui ne réfléchissent
 * pas la lumière.
 */
class Wall : public Element
{
    Point start_;
    Point end_;

    bool movable_;

  public:
    /**
     * Instancie un mur.
     * @param p1 le début du mur.
     * @param p2 la fin du mur.
     * @param movable vrai si le mur est déplaçable, faux sinon.
     * @throws std::string si p1 est égal à p2.
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

    /**
     * Retourne vrai si le mur est déplaçable.
     * @return vrai si le mur est déplaçable.
     */
    inline bool movable() const;

    /**
     * Modifie le point de départ du mur si celui-ci est correct.
     * @param s le point de départ.
     * @return vrai si le nouveau point est correct, faux sinon.
     */
    inline bool set_start(const Point& s);

    /**
     * Modifie le point de fin du mur si celui-ci est correct.
     * @param e le point de fin du mur.
     * @return vrai si le nouveau point est correct, faux sinon
     */
    inline bool set_end(const Point& e);

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

bool Wall::set_start(const Point& s)
{
    bool b {!(s == end_)};
    if (b)
        start_ = s;
    return b;
}

bool Wall::set_end(const Point& e)
{
    bool b {!(e == start_)};
    if (b)
        end_ = e;
    return b;
}

bool Wall::movable() const
{
    return movable_;
}

#endif // WALL_H
