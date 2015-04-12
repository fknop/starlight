#ifndef SOURCEVIEW_H
#define SOURCEVIEW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
//#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QMediaPlayer>

#include "model/source.h"
#include "view/elementview.h"


/**
 * Modélisation visuelle d’une source.
 */
class SourceView : public QGraphicsPixmapItem, public ElementView //QGraphicsRectItem
{
public:
    /**
     * Construit un carré représentant une source lumineuse qui peut être allumée ou éteinte.
     * @param posX abscisse du coin supérieur gauche de la source.
     * @param posY ordonnée du coin supérieur gauche de la source.
     * @param width longueur du carré représentant la source.
     * @param height hauteur du carré représentant la source.
     */
    SourceView(const Source& source, bool selectable = false);
    Source * source();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    inline bool selectable() const;
    inline void set_selectable(bool value);

private:
    Source* source_;
    QMediaPlayer * sound_;
    bool selectable_;

};

/* Fonctions inlines */

bool SourceView::selectable() const
{
    return this->selectable_;
}

void SourceView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // SOURCEVIEW_H
