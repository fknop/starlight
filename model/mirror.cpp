#include "mirror.h"
#include <iostream>

Mirror::Mirror(const Point & p, double len, double x, double a)
    : Mirror {p, len, x, a, {.0, .0}, {.0, .0}, .0, .0}
{

}

Mirror::Mirror(const Point & p, double x, double len, double a, Point pm,
               Point pM, double am, double aM)
    : pivot {p}, length(len), xpad(x), xMin {pm.getX()}, xMax {pM.getX()},
      yMin {pm.getY()}, yMax {pM.getY()}, alpha {a}, alphaMin {am},
      alphaMax {aM}
{
    if (length <= 0 || xpad < 0)
        throw "La longueur et le décalage doivent etre positifs";

   if (!checkPivotRange(p))
       throw "Le pivot n'est pas dans les bornes autorisées";

    if (!checkAngleRange(alpha))
        throw "L'inclinaison du mirroir est invalide. "
        "Elle n'est pas comprise entre les bornes.";
}

const Point & Mirror::getPivot() const
{
    return pivot;
}

double Mirror::getLength() const
{
    return length;
}

double Mirror::getXPad() const
{
    return xpad;
}

double Mirror::getAngle() const
{
    return alpha;
}

double Mirror::getMinAngle() const
{
    return alphaMin;
}

double Mirror::getMaxAngle() const
{
    return alphaMax;
}

Point Mirror::getMinPivot() const
{
    return Point {xMin, yMin};
}

Point Mirror::getMaxPivot() const
{
    return Point {xMax, yMax};
}

bool Mirror::setPivot(const Point & p)
{
    bool r {checkPivotRange(p)};
    if (r)
        pivot = p;
    return r;
}

bool Mirror::setAngle(double a)
{
    bool r {checkAngleRange(a)};
    if (r)
        alpha = a;
    return r;
}

bool Mirror::checkAngleRange(double a) const
{
    return (alphaMin == 0 && alphaMax == 0) ||
            (a >= alphaMin && a <= alphaMax);
}

bool Mirror::checkPivotRange(const Point & p) const
{
    if (xMin == 0 && xMax == 0 && yMin == 0 && yMax == 0)
        return true;

    else if (xMin == 0 && xMax == 0)
        return p.getY() >= yMin && p.getY() <= yMax;

    else if (yMin == 0 && yMax == 0)
        return p.getX() >= xMin && p.getX() <= xMax;

    else
        return p.getX() >= xMin && p.getX() <= xMax
                && p.getY() >= yMin && p.getY() <= yMax;

}

void Mirror::rotate(double angle)
{
    if (!setAngle(alpha + angle))
    {
        if (alpha + angle > alphaMax)
            setAngle(alphaMax);
        else
            setAngle(alphaMin);
    }
}

void Mirror::translate(double x, double y)
{

    double newX = pivot.getX() + x;
    double newY = pivot.getY() + y;
    if (!setPivot(Point(newX, newY)))
    {
        if (newX < xMin)
            newX = xMin;
        else if (newX > xMax)
            newY = xMax;

        if (newY < yMin)
            newY = yMin;
        else if (newY > yMax)
            newY = yMax;

        setPivot(Point(newX, newY));

    }


}

std::ostream & operator<<(std::ostream & out, const Mirror & m)
{
    out << "Mirror --- Pivot : " << m.pivot << " , Length : " << m.length
        << " , x-pad : " << m.xpad << ", Angle : " << m.alpha <<
           " , Angle range : [" << m.alphaMin << "," << m.alphaMax << "]" <<
           "Pivot range : [(" << m.xMin << "," << m.yMin << "),(" << m.xMax <<
           "," << m.yMax << ")]";
    return out;
}
