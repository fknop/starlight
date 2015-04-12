#ifndef WALLVIEW_HPP
#define WALLVIEW_HPP

#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>

#include "model/wall.h"
#include "view/elementview.h"

/**
 * Modélisation visuelle d’un mur (ne reflétant pas la lumière).
 */
class WallView : public QGraphicsLineItem, public ElementView
{
public:
    /**
     * Construit un segment de droite représentant un mur.
     * @param x1 abscisse de la première extrémité du mur.
     * @param y1 ordonnée da la première extrémité du mur.
     * @param x2 abscisse de l’autre extrémité du mur.
     * @param y2 ordonnée de l’autre extrémité du mur.
     */
    WallView(const Wall& wall, bool selectable = false);
    inline Wall * wall();

    inline bool selectable() const;
    inline void set_selectable(bool value);

private:
    Wall * wall_;
    bool selectable_;

};

/* Fonctions inlines */

Wall * WallView::wall()
{
    return wall_;
}

bool WallView::selectable() const
{
    return this->selectable_;
}

void WallView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}


#endif // WALLVIEW_HPP

