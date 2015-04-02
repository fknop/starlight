#include "CrystalView.h"
#include "model/crystal.h"

CrystalView::CrystalView(const Crystal& crystal) : crystal{crystal}
{
    Point p = crystal.getCenter();
    double radius = crystal.getRadius();
    setRect(p.x() - radius, p.y() + radius,
            radius + radius, radius + radius);
}
