#ifndef CRYSTALVIEW_H
#define CRYSTALVIEW_H

#include <QGraphicsEllipseItem>

#include "model/crystal.h"

class CrystalView : public QGraphicsEllipseItem
{
public:
    CrystalView(const Crystal & crystal_);

private:
    const Crystal * crystal_;
};

#endif // CRYSTALVIEW_H
