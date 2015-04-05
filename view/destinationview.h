#ifndef DESTINATIONVIEW_H
#define DESTINATIONVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "model/dest.h"
/**
 * Modélisation visuelle de la destination.
 */
class DestinationView : public QGraphicsRectItem
{
public:
    /**
     * Construit une destination carrée.
     * @param posX abscisse du point supérieur gauche.
     * @param posY ordonnée du point supérieur gauche.
     * @param width longueur de la destination.
     * @param height hauteur de la destination.
     */
    DestinationView(const Dest&);

private:
    Dest dest_;

};

#endif // DESTINATIONVIEW_H
