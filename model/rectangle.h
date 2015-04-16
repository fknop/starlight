#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>

#include "model/line.h"
#include "model/linesegment.h"
#include "model/point.h"

/**
 * Classe Rectangle :
 * représente un rectangle avec
 * un point supérieur gauche, une longueur
 * et une hauteur.
 */
class Rectangle
{

private:
    Point upper_left_;
    double width_;
    double height_;

public:

    /**
     * Crée un nouveau rectangle.
     * @param upper_left le point supérieur gauche du rectangle.
     * @param width la longueur du rectangle.
     * @param height la hauteur du rectangle.
     */
    Rectangle(const Point& upper_left, double width, double height);

    /**
     * Retourne le coin supérieur gauche du rectangle.
     * @return le coin supérieur gauche du rectangle.
     */
    inline const Point& upper_left() const;

    /**
     * Retourne la longueur du rectangle (axe X).
     * @return la longueur du rectangle.
     */
    inline double width() const;

    /**
     * Retourne la hauteur du rectangle (axe Y).
     * @return la hauteur du rectangle.
     */
    inline double height() const;

};

/* Fonctions inlines */

const Point& Rectangle::upper_left() const
{
    return upper_left_;
}

double Rectangle::width() const
{
    return width_;
}

double Rectangle::height() const
{
    return height_;
}

#endif // RECTANGLE_H
