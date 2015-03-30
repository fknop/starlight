#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <cstddef>
#include "linesegment.h"


/**
 * Cette classe représente une droite.
 * Elle possède un point d'origine et un
 * angle. De cette manière on peut
 * trouver n'importe quel point se trouvant
 * sur la droite en ayant une distance.
 */
class Line
{
    Point origin;
    double angle;

public:
    /**
     * Instancie une droite, avec un point donné et
     * un angle en radians correspondant à la pente.
     * @param origin un point de la droite.
     * @param angle l’angle de la pente.
     */
    Line(const Point& origin, double angle);

    /**
     * Instancie une droite avec deux points donnés.
     * @param p1 un premier point de la droite.
     * @param p2 un deuxième point de la droite.
     */
    Line(const Point& p1, const Point& p2);


    /**
     * Retourne vrai si la droite possède une intersection
     * avec une autre droite et retourne également
     * le point d'intersection en paramètre.
     * @param l la deuxième droite.
     * @param intersecion le point d'intersection.
     * @return vrai si les droites possèdent une intersection.
     */
    bool intersects(const Line& l, Point ** intersecion);

    /**
     * Retourne vrai si la droite possède une intersection
     * avec un segment et retourne également
     * le point d'intersection en paramètre.
     * @param ls le segment.
     * @param intersecion le point d'intersection.
     * @return vrai si la droite et le segment possède une intersection.
     */
    bool intersects(const LineSegment& ls, Point ** intersection);

    /**
     * Renvoie un point de la droite.
     * @return un point de la droite.
     */
    const Point& getPoint() const;

    /**
     * Modifie le point d'origine de la droite.
     * @param origin le nouveau point d'origine.
     */
    void setPoint(const Point& origin);

    /**
     * Retourne la pente de la droite.
     * @return la pente de la droite.
     */
    double getAngle() const;

    /**
     * Modifie l'angle de la droite.
     * @param le nouvel angle en radians de la droite.
     */
    void setAngle(double rad);

    friend bool operator==(const Line& l1, const Line& l2);

private:
    static Point * verticalLineIntersection(const Line& l1, const Line l2);
};

#endif // LINE_H
