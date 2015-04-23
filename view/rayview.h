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
    /**
     * Instancie une représentation visuelle d’un rayon passé en paramètre.
     * @param ray le rayon à afficher.
     */
   RayView(const Ray& ray);

   /**
    * Modifie la couleur du rayon sur base de la longueur d'onde.
    * Source: http://www.efg2.com/Lab/ScienceAndEngineering/Spectra.htm
    * @param wl la longueur d'onde.
    */
   void set_color(double wl);

private:

};
#endif // RAYVIEW_H
