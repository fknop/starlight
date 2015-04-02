#ifndef WALL_H
#define WALL_H

#include <iostream>

#include "element.h"
#include "linesegment.h"
#include "point.h"


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

  public:
    /**
     * Instancie un mur.
     * @param p1 le début du mur.
     * @param p2 la fin du mur.
     */
    Wall(const Point& p1, const Point& p2);

    Wall(const Wall&);

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

    LineSegment to_line_segment();

    /**
     * Surcharge l'opérateur de flux de sortie pour afficher
     * un récapitulatif des caractéristiques du mur sous-jacent
     * en console.
     * @return le flux dans lequel le mur a été imprimé.
     */
    friend std::ostream& operator<<(std::ostream& out,
                                     const Wall& wall);
};

/* Fonctions inlines */

const Point& Wall::start() const
{
    return this->start_;
}

const Point& Wall::end() const
{
    return this->end_;
}

#endif // WALL_H
