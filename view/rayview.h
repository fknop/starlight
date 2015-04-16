#ifndef RAYVIEW_H
#define RAYVIEW_H

#include <QGraphicsLineItem>

#include "model/ray.h"

/**
 * Modélisation visuelle d’un rayon de lumière.
 */
class RayView : public QGraphicsLineItem
{
public:
   RayView(const Ray & ray);

   /**
    * Set color on basis of the wavelength.
    * Source: http://www.efg2.com/Lab/ScienceAndEngineering/Spectra.htm
    * @param wl wavelength of a the ray.
    */
   void set_color(double wl);

   inline bool selectable() const;
   inline void set_selectable(bool value);


private:

};
#endif // RAYVIEW_H
