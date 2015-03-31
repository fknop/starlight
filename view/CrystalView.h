#ifndef CRYSTALVIEW_H
#define CRYSTALVIEW_H

#include <QGraphicsEllipseItem>

#include "model/crystal.h"

class CrystalView : public QGraphicsEllipseItem
{
public:
    CrystalView(const Crystal &crystal);

private:
    Crystal crystal;
};

#endif // CRYSTALVIEW_H
