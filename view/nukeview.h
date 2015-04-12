#ifndef NUKESVIEW_H
#define NUKESVIEW_H

#include <QGraphicsView>
#include <QGraphicsEllipseItem>

#include "obs/observable.h"
#include "obs/observerinterface.h"
#include "model/nuke.h"
#include "view/elementview.h"

class NukeView : public QGraphicsEllipseItem, public ObserverInterface, public ElementView
{
public:
    NukeView(const Nuke & nuke, bool selectable = false);
    inline Nuke * nuke();

    void notify(Observable *sdo, std::string msg, const std::vector<std::string> &args);

    inline bool selectable() const;
    inline void set_selectable(bool value);

private:
    Nuke * nuke_;
    bool selectable_;
};

/* Fonctions inlines */

Nuke * NukeView::nuke()
{
    return nuke_;
}

bool NukeView::selectable() const
{
    return this->selectable_;
}

void NukeView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // NUKESVIEW_H
