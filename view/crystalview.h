#ifndef CRYSTALVIEW_H
#define CRYSTALVIEW_H

#include <QGraphicsEllipseItem>

#include "model/crystal.h"
#include "view/elementview.h"

class CrystalView : public QGraphicsEllipseItem, public ElementView
{
public:
    CrystalView(const Crystal & crystal_);
    Crystal * crystal();

private:
    const Crystal * crystal_;
};

#endif // CRYSTALVIEW_H
