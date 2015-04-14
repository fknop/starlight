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
    DestinationView(const Dest& dest, bool selectable = false);
    void notify(Observable *sdo,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());

    inline Dest * dest();

    inline bool selectable() const;
    inline void set_selectable(bool value);

    void translate(double x = .0, double y = .0);




private:
    Dest* dest_;
    bool selectable_;

    void set_rect();
};

/* Fonctions inlines */

Dest * DestinationView::dest()
{
    return dest_;
}

bool DestinationView::selectable() const
{
    return this->selectable_;
}

void DestinationView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // DESTINATIONVIEW_H
