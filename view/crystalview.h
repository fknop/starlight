#ifndef CRYSTALVIEW_H
#define CRYSTALVIEW_H

#include <QGraphicsEllipseItem>

#include "model/crystal.h"
#include "view/elementview.h"

class CrystalView : public QGraphicsEllipseItem, public ElementView
{
public:
    CrystalView(const Crystal & crystal, bool selectable = false);
    inline Crystal * crystal();

    inline bool selectable() const;
    inline void set_selectable(bool value);

private:
    Crystal * crystal_;
    bool selectable_;
};

/* Fonctions inlines */

Crystal * CrystalView::crystal()
{
    return crystal_;
}

bool CrystalView::selectable() const
{
    return this->selectable_;
}

void CrystalView::set_selectable(bool value)
{
    this->selectable_ = value;
    setFlag(QGraphicsItem::ItemIsSelectable, this->selectable_);
}

#endif // CRYSTALVIEW_H
