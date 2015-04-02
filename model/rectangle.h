#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>

#include "line.h"
#include "linesegment.h"
#include "point.h"


class Rectangle
{

private:
    Point upper_left_;
    double width_;
    double height_;

public:
    Rectangle(const Point&, double, double);

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

    /**
     * Vérifie si une droite coupe un rectangle.
     * @param line la droite.
     * @param points le vecteur de points d'intersections trouvés.
     * @return le nombre d'intersections.
     */
    int intersects(const Line& line, std::vector<Point>& points);

    /**
     * Vérifie si un segment de droite coupe un rectangle.
     * @param ls le segment de droite.
     * @param points le vecteur de points d'intersections trouvés.
     * @return le nombre d'intersections.
     */
    int intersects(const LineSegment& ls, std::vector<Point>& points);
};

/* Fonctions inlines */

const Point& Rectangle::upper_left() const
{
    return this->upper_left_;
}

double Rectangle::width() const
{
    return this->width_;
}

double Rectangle::height() const
{
    return this->height_;
}

#endif // RECTANGLE_H
