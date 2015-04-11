#ifndef DESTINATIONVIEW_H
#define DESTINATIONVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "obs/observable.h"
#include "obs/observerinterface.h"
#include "model/dest.h"
#include "view/elementview.h"
/**
 * Modélisation visuelle de la destination.
 */
class DestinationView : public QGraphicsRectItem, public ObserverInterface, public ElementView
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
    void notify(Observable *sdo,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());

private:
    Dest* dest_;

};

#endif // DESTINATIONVIEW_H
