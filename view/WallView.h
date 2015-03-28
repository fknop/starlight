#ifndef WALLVIEW_HPP
#define WALLVIEW_HPP

#include <QGraphicsView>
#include <QGraphicsLineItem>

#include <QGraphicsSceneMouseEvent>

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
    WallView(int x1, int y1, int x2, int y2);

private:
    QPointF initialPos;
};


#endif // WALLVIEW_HPP

