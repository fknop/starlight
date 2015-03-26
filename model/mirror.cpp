#include "mirror.h"
#include <iostream>

Mirror::Mirror(const Point & p, int len, int x, double a)
    : Mirror {p, len, x, a, {0, 0}, {0, 0}, 0, 0}
{

}

Mirror::Mirror(const Point & p, int x, int len, double a, Point pm,
               Point pM, double am, double aM)
    : pivot {p}, length(len), xpad(x), xMin {pm.getX()}, xMax {pM.getX()},
      yMin {pm.getY()}, yMax {pM.getY()}, alpha {a}, alphaMin {am},
      alphaMax {aM}
{
    if (length <= 0 || xpad <= 0)
    {
        //throw "La longueur et le décalage doivent etre strictement positifs";
    }
    // TODO : valider length, xpad, (alphaMin et alphaMax),
    //                (alpha et [alphaMin, alphaMax]), (xMin et xMax),
    //                (x et [xMin, xMax]), (yMin et yMax),
    //                (y et [yMin, yMax])
}

const Point & Mirror::getPivot() const
{
    return pivot;
}

int Mirror::getLength() const
{
    return length;
}

int Mirror::getXPad() const
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
    if (r) pivot = p;
    return r;
}

bool Mirror::setAngle(double a)
{
    bool r {checkAngleRange(a)};
    if (r) alpha = a;
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
    {
        return true;
    }
    else if (xMin == 0 && xMax == 0)
    {
        return p.getY() >= yMin && p.getY() <= yMax;
    }
    else if (yMin == 0 && yMax == 0)
    {
        return p.getX() >= xMin && p.getX() <= xMax;
    }
    else
    {
        return p.getX() >= xMin && p.getX() <= xMax
                && p.getY() >= yMin && p.getY() <= yMax;
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
