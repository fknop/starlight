#include "level.h"

#include <string>
#include "Geometry.h"

using namespace std;

Level::Level(int w, int h) : width {w}, height {h},
walls { {{0, 0}, {0, h}}, {{0, h}, {w, h}},
    {{w, h}, {w, 0}}, {{w, 0}, {0, 0}}
}
{
    //  Taille minimale ?
    if (w <= 0 || h <= 0)
    {
        //Gérer l'erreur
    }
}

const Source & Level::getSource() const
{
    return s;
}

void Level::setSource(const Source & value)
{
    s = value;
}

const Dest & Level::getDestination() const
{
    return d;
}

void Level::setDestination(const Dest & value)
{
    d = value;
}

const vector<Wall> & Level::getWalls() const
{
    return walls;
}

const vector<Mirror> & Level::getMirrors() const
{
    return mirrors;
}

const vector<Crystal> & Level::getCrystals() const
{
    return crystals;
}

const vector<Lens> & Level::getLenses() const
{
    return lenses;
}

const vector<Ray> & Level::getRays() const
{
    return rays;
}

void Level::setRays(const vector<Ray> & value)
{
    rays = value;
}

void Level::computeRays()
{

    Point pSource = this->s.getPosition();
    double rad = this->s.getAngle();
    Line ray(pSource, rad);

    Point * intersection = getIntersections(ray);

    if (intersection == nullptr)
    {
        std::cout << "null";
    }
    else
    std::cout << *intersection;
    /*int gx = pivotX -  (xpad * cos(angle));
    int gy = pivotY - (xpad * sin(angle));

    int dx = pivotX + ((len-xpad) * cos(angle));
    int dy = pivotY + ((len-xpad) * sin(angle));*/
    delete intersection;

}



void Level::setWalls(const std::vector<Wall> & value)
{
    walls = value;
}

void Level::setCrystals(const std::vector<Crystal>& value)
{
    crystals = value;
}

void Level::setNukes(const std::vector<Nuke>& value)
{
    nukes = value;
}

void Level::setLenses(const std::vector<Lens>& value)
{
    lenses = value;
}

void Level::setMirrors(const std::vector<Mirror>& value)
{
    mirrors = value;
}

const vector<Nuke> & Level::getNukes() const
{
    return nukes;
}

int Level::getHeight()
{
    return height;
}

int Level::getWidth()
{
    return width;
}

/* provisoire */
Point * Level::getIntersections(const Line& l)
{

    /*
    Geometry::getIntersection(const Line& l, const LineSegment& ls)
     *
     *
     */

    /*  Source s {{0, 0}, -1, 5, 600};
        Dest d {{0, 0}, 5};

        std::vector<Wall> walls;
        std::vector<Mirror> mirrors;
        std::vector<Crystal> crystals;
        std::vector<Lens> lenses;
        std::vector<Ray> rays;
        std::vector<Nuke> nukes;*/
    double closestDistance = 0;
    double distance;
    char type;
    Point * closestPoint = nullptr;

    for (auto &i : walls)
    {
        std::cout << i.getStart() << " " << i.getEnd() << std::endl;
        Point * p = Geometry::getIntersection(l, LineSegment(i.getStart(), i.getEnd()));
        if (p != nullptr && !(*p == l.getPoint()))
        {
            std::cout << "Intersection avec la ligne : " << *p << std::endl;

            distance = Geometry::getDistance(*p, l.getPoint());
            if (distance <= closestDistance)
            {
                closestDistance = distance;
                delete closestPoint;
                closestPoint = new Point(*p);
            }

        }
        delete p;
    }

    for (auto &i : mirrors)
    {
        double angle = i.getAngle();
        int xpad = i.getXPad();
        int pivotX = i.getPivot().getX();
        int pivotY = i.getPivot().getY();
        int len = i.getLength();
        int gx = pivotX -  (xpad * cos(angle));
        int gy = pivotY - (xpad * sin(angle));
        int dx = pivotX + ((len-xpad) * cos(angle));
        int dy = pivotY + ((len-xpad) * sin(angle));

        Point * p = Geometry::getIntersection(l, LineSegment(Point(gx, gy), Point(dx, dy)));
        if (p != nullptr)
        {
            distance = Geometry::getDistance(*p, l.getPoint());
            if (distance <= closestDistance)
            {
                closestDistance = distance;
                delete closestPoint;
                closestPoint = new Point(*p);
            }
        }

        delete p;
    }

    for (auto &i : crystals)
    {

    }

    for (auto &i : nukes)
    {

    }

    for (auto &i : lenses)
    {

    }


    return closestPoint;
}

