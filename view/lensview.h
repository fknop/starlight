#ifndef LENSVIEW_H
#define LENSVIEW_H

#include <QGraphicsEllipseItem>

#include "model/lens.h"
#include "obs/observable.h"
#include "obs/observerinterface.h"
#include "view/elementview.h"


class LensView : public QGraphicsEllipseItem, public ElementView, public ObserverInterface
{
public:
    LensView(const Lens & lens, bool selectable = false);

    inline Lens * lens();

    inline bool selectable() const;
    inline void set_selectable(bool value);

    void translate(double x = .0, double y = .0);
    void notify(Observable *sdo,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());

private:
    Lens * lens_;

    bool selectable_;
    void set_rect();
};

/* Fonctions inlines */

Lens * LensView::lens()
{
    return lens_;
}

bool LensView::selectable() const
{
    return this->selectable_;
}

void LensView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // LENSVIEW_H
