#include "rayview.h"
#include "QPen"

RayView::RayView(const Ray& ray)
{
    QPen myPen(Qt::blue);
    myPen.setWidth(2);
    setPen(myPen);
    setLine(ray.start().x(), ray.start().y(),
            ray.end().x(), ray.end().y());



}

