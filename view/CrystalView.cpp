#include "CrystalView.h"

#include "model/crystal.h"

CrystalView::CrystalView(const Crystal& crystal) : crystal{crystal}
{
    Point p = crystal.getCenter();
    double radius = crystal.getRadius();
    setRect(p.getX() - radius, p.getY() + radius,
            radius + radius, radius + radius);
}
