#ifndef SOURCEVIEW_H
#define SOURCEVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

#include "model/source.h"


/**
 * Modélisation visuelle d’une source.
 */
class SourceView : public QGraphicsRectItem
{
public:
    /**
     * Construit un carré représentant une source lumineuse qui peut être allumée ou éteinte.
     * @param posX abscisse du coin supérieur gauche de la source.
     * @param posY ordonnée du coin supérieur gauche de la source.
     * @param width longueur du carré représentant la source.
     * @param height hauteur du carré représentant la source.
     */
    SourceView(const Source& source);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Source* source_;

};

#endif // SOURCEVIEW_H
