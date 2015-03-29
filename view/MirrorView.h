#ifndef MirrorView_HPP
#define MirrorView_HPP

#include <QGraphicsView>
#include <QGraphicsLineItem>

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

#include <iostream>
#include "model/mirror.h"

/**
 * Modélisation visuelle d’un miroir.
 */
class MirrorView : public QGraphicsLineItem
{
public:
    /**
     * Construit un miroir capable de refléter la lumière du rayon émis depuis la source.
     * @param pivotX abscisse du pivot du miroir.
     * @param pivotY ordonnée du pivot du miroir.
     * @param xpad distance entre le pivot et l’extrémité gauche du miroir.
     * @param len longueur totale du miroir.
     * @param angle angle d’inclinaison du miroir.
     */
    MirrorView(const Mirror& MirrorView);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    int getRotation();
    void setRotation(qreal angle);

private:
    QPointF initialPos;
    qreal rotation;
    Mirror mirror;


};


#endif // MirrorView_HPP
