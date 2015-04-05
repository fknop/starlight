#include "crystalview.h"
#include "model/crystal.h"


CrystalView::CrystalView(const Crystal& crystal) : crystal_{crystal}
{
    Point p = crystal.center();
    double radius = crystal.radius();
    setRect(p.x() - radius, p.y() + radius,
            radius + radius, radius + radius);
}
