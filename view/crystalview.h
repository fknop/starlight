#ifndef CRYSTALVIEW_H
#define CRYSTALVIEW_H

#include <QGraphicsEllipseItem>

#include "model/crystal.h"
#include "view/elementview.h"

#include "obs/observable.h"
#include "obs/observerinterface.h"

class CrystalView : public QGraphicsEllipseItem, public ElementView, public ObserverInterface
{
public:
    CrystalView(const Crystal & crystal, bool selectable = false);
    inline Crystal * crystal();

    inline bool selectable() const;
    inline void set_selectable(bool value);

    void translate(double x = .0, double y = .0);

    void notify(Observable *sdo,
                std::string msg,
                const std::vector<std::string>& args = std::vector<std::string>());



private:
    Crystal * crystal_;
    bool selectable_;

    void set_rect();
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
