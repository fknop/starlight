#include <QPen>

#include "rayview.h"

RayView::RayView(const Ray & ray)
{
    set_color(ray.wavelength());

    setLine(ray.start().x(), ray.start().y(),
            ray.end().x(), ray.end().y());
}

void RayView::set_color(double wl)
{
    double red;
    double green;
    double blue;

    if (wl >= 380 && wl <= 439)
    {
        red   = -(wl - 440) / (440 - 380);
        green =  0.0;
        blue  = 1.0;
    }

    else if (wl >= 440 && wl <= 438)
    {
        red   =  0.0;
        green =  (wl - 440) / (440 - 380);
        blue  = 1.0;
    }

    else if (wl >= 490 && wl <= 509)
    {
        red   = 0.0;
        green = 1.0;
        blue  = -(wl - 510) / (510 - 490);
    }

    else if (wl >= 510 && wl <= 579)
    {
        red   = (wl - 510) / (580 - 510);
        green = 1.0;
        blue  = 0.0;
    }

    else if (wl >= 580 && wl <= 644)
    {
        red   = 1.0;
        green = -(wl - 645) / (645 - 580);
        blue  = 0.0;
    }

    else if (wl >= 645 && wl <= 780)
    {
        red   = 1.0;
        green = 0.0;
        blue  = 0.0;
    }

    else
    {
        red   = 0.0;
        green = 0.0;
        blue  = 0.0;
    }

    QPen pen(QColor(100 * red, 100 * green, 100 * blue));
    pen.setWidth(2);
    setPen(pen);
}
