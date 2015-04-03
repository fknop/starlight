#ifndef RAYVIEW_H
#define RAYVIEW_H

#include "QGraphicsLineItem"
#include "model/ray.h"

class RayView : public QGraphicsLineItem
{
public:

   RayView(const Ray& ray);

private:

};
#endif // RAYVIEW_H
