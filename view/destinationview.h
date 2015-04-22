#ifndef DESTINATIONVIEW_H
#define DESTINATIONVIEW_H

#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "model/dest.h"

#include "obs/observable.h"
#include "obs/observerinterface.h"

#include "view/elementview.h"

/**
 * Modélisation visuelle de la destination.
 */
class DestinationView : public QGraphicsRectItem, public ObserverInterface, public ElementView
{
    Dest * dest_;
    bool selectable_;

public:
    /**
     * Construit une destination carrée.
     * @param dest la destination à représenter.
     * @param selectable la destination est-elle sélectionnable ?
     */
    DestinationView(const Dest& dest, bool selectable = false);

    /**
     * Retourne la destination représentée.
     * @return la destination représentée.
     */
    inline Dest * dest();

    /**
     * Retourne vrai si la destination est sélectionnable, faux sinon.
     * @return vrai si la destination est sélectionnable, faux sinon.
     */
    inline bool selectable() const;
    /**
     * Modifie le fait que la destination soit sélectionnable.
     * @param value vrai si la destination est sélectionnable, faux sinon.
     */
    inline void set_selectable(bool value);

    void translate(double x = .0, double y = .0);
    void notify(Observable *sdo,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());

private:
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
