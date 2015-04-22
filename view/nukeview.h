#ifndef NUKESVIEW_H
#define NUKESVIEW_H

#include <QGraphicsEllipseItem>
#include <QGraphicsView>

#include "model/nuke.h"
#include "obs/observerinterface.h"
#include "view/elementview.h"

/**
 * Modélisation visuelle d’une bombe.
 */
class NukeView : public QGraphicsEllipseItem, public ObserverInterface, public ElementView
{
    Nuke * nuke_;
    bool selectable_;

public:
    NukeView(const Nuke & nuke, bool selectable = false);

    inline Nuke * nuke();

    inline bool selectable() const;
    inline void set_selectable(bool value);

    void translate(const double x = .0, const double y = .0) override;
    void notify(Observable * o,
                const std::string& msg,
                const std::vector<std::string>& args) override;


private:
    void set_rect();
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
