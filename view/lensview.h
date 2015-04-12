#ifndef LENSVIEW_H
#define LENSVIEW_H

#include <QGraphicsEllipseItem>

#include "model/lens.h"
#include "view/elementview.h"

class LensView : public QGraphicsEllipseItem, public ElementView
{
public:
    LensView(const Lens& lens, bool selectable = false);
    Lens * lens();

    inline bool selectable() const;
    inline void set_selectable(bool value);

private:
    const Lens* lens_;
    bool selectable_;
};

/* Fonctions inlines */

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
