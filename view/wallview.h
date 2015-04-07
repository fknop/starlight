#ifndef WALLVIEW_HPP
#define WALLVIEW_HPP

#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>

#include "model/wall.h"

/**
 * Modélisation visuelle d’un mur (ne reflétant pas la lumière).
 */
class WallView : public QGraphicsLineItem
{
public:
    /**
     * Construit un segment de droite représentant un mur.
     * @param x1 abscisse de la première extrémité du mur.
     * @param y1 ordonnée da la première extrémité du mur.
     * @param x2 abscisse de l’autre extrémité du mur.
     * @param y2 ordonnée de l’autre extrémité du mur.
     */
    WallView(const Wall& wall);

private:

};


#endif // WALLVIEW_HPP

