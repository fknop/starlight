#include "level.h"

#include <string>
#include "Geometry.h"

using namespace std;

Level::Level(int w, int h) : width {w}, height {h},
    walls { {{0, 0}, {0, h}}, {{0, h}, {w, h}},
{{w, h}, {w, 0}}, {{w, 0}, {0, 0}}
            }
{
    if (w <= 0 || h <= 0)
        throw "La taille et la longueur "
            "du plateau doivent etre strictement positives";

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

    Point * intersection = getClosestIntersection(ray);

    if (intersection == nullptr)
    {
        cout << "computeRays() intersection null" << endl;
    }
    else
        cout << "intersection " << *intersection << endl;
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

Point * Level::getClosestIntersectionWithWalls(double & closestDistance, const Line& l)
{
    Point * closestPoint = nullptr;
    double distance;

    for (auto &i : walls)
    {
        Point * p = Geometry::getIntersection(l, LineSegment(i.getStart(), i.getEnd()));

        if (p != nullptr && !(*p == l.getPoint()))
        {
            std::cout << "Intersection avec la ligne : " << *p << std::endl;

            distance = p->distance(l.getPoint());

            if (distance <= closestDistance)
            {
                closestDistance = distance;
                delete closestPoint;
                closestPoint = new Point(*p);
            }
        }

        delete p;
    }

    return closestPoint;
}


Point * Level::getClosestIntersectionWithMirrors(double & closestDistance, const Line& l)
{
    Point * closestPoint = nullptr;
    double distance;

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
            distance = p->distance(l.getPoint());

            if (distance <= closestDistance)
            {
                closestDistance = distance;
                delete closestPoint;
                closestPoint = new Point(*p);
            }
        }

        delete p;
    }

    return closestPoint;
}

Point * Level::getClosestIntersectionWithCrystals(double & closestDistance, const Line& l)
{
    Point * closestPoint = nullptr;
    double distance;

    for (auto &i : crystals)
    {
        Point center = i.getCenter();
        int r = i.getRadius();
        int leftX = center.getX() - r;
        int upperY = center.getY() + r;
        int bottomY = center.getY() - r;
        int rightX = center.getX() + r;

        Point upperLeft(leftX, upperY);
        Point upperRight(rightX, upperY);
        Point bottomLeft(leftX, bottomY);
        Point bottomRight(rightX, bottomY);

        std::vector<LineSegment> segments;
        segments.push_back(LineSegment(upperLeft, upperRight));
        segments.push_back(LineSegment(upperLeft, bottomLeft));
        segments.push_back(LineSegment(upperRight, bottomRight));
        segments.push_back(LineSegment(bottomLeft, bottomRight));

        for (auto &j : segments)
        {
            Point * p = Geometry::getIntersection(l, j);

            if (p != nullptr)
            {
                distance = p->distance(l.getPoint());

                if (distance <= closestDistance)
                {
                    closestDistance = distance;
                    delete closestPoint;
                    closestPoint = new Point(*p);
                }
            }

            delete p;
        }
    }

    return closestPoint;
}

Point * Level::getClosestIntersectionWithNukes(double & closestDistance, const Line& l)
{
    Point * closestPoint = nullptr;
    double distance;

    for (auto &i : nukes)
    {
        Point center = i.getLocation();
        int r = i.getRadius();
        int leftX = center.getX() - r;
        int upperY = center.getY() + r;
        int bottomY = center.getY() - r;
        int rightX = center.getX() + r;

        Point upperLeft(leftX, upperY);
        Point upperRight(rightX, upperY);
        Point bottomLeft(leftX, bottomY);
        Point bottomRight(rightX, bottomY);

        std::vector<LineSegment> segments;
        segments.push_back(LineSegment(upperLeft, upperRight));
        segments.push_back(LineSegment(upperLeft, bottomLeft));
        segments.push_back(LineSegment(upperRight, bottomRight));
        segments.push_back(LineSegment(bottomLeft, bottomRight));

        for (auto &j : segments)
        {
            Point * p = Geometry::getIntersection(l, j);

            if (p != nullptr)
            {
                distance = p->distance(l.getPoint());

                if (distance <= closestDistance)
                {
                    closestDistance = distance;
                    delete closestPoint;
                    closestPoint = new Point(*p);
                }
            }

            delete p;
        }
    }

    return closestPoint;
}

Point * Level::getClosestIntersectionWithLenses(double & closestDistance, const Line& l)
{
    Point * closestPoint = nullptr;
    double distance;

    for (auto &i : lenses)
    {
        Point pos = i.getPosition();
        int width = i.getWidth();
        int height = i.getHeight();

        Point upperLeft(pos);
        Point upperRight(pos.getX() + width, pos.getY());
        Point bottomLeft(pos.getX(), pos.getY() + height);
        Point bottomRight(pos.getX() + width, pos.getY() + height);

        std::vector<LineSegment> segments;
        segments.push_back(LineSegment(upperLeft, upperRight));
        segments.push_back(LineSegment(upperLeft, bottomLeft));
        segments.push_back(LineSegment(upperRight, bottomRight));
        segments.push_back(LineSegment(bottomLeft, bottomRight));

        for (auto &j : segments)
        {
            Point * p = Geometry::getIntersection(l, j);

            if (p != nullptr)
            {
                distance = p->distance(l.getPoint());

                if (distance <= closestDistance)
                {
                    closestDistance = distance;
                    delete closestPoint;
                    closestPoint = new Point(*p);
                }
            }

            delete p;
        }
    }

    return closestPoint;
}


Point * Level::findClosestPoint(double & oldClosestDistance, double & newClosestDistance, Point * closestPoint, Point * p)
{
    if (newClosestDistance < oldClosestDistance)
    {
        oldClosestDistance = newClosestDistance;
        return new Point(*p);
    }
    else
    {
        newClosestDistance = oldClosestDistance;
        return closestPoint;
    }
}


/* provisoire */
Point * Level::getClosestIntersection(const Line& l)
{
    double closestDistance = Point(0,0).distance(Point(this->width, this->height)); // distance maximum possible
    double newClosestDistance = closestDistance;
    Point * closestPoint = nullptr;


    Point * wallIntersect = getClosestIntersectionWithWalls(newClosestDistance, l);

    closestPoint = findClosestPoint(closestDistance, newClosestDistance, closestPoint, wallIntersect);

    delete wallIntersect;


    Point * mirrorIntersect = getClosestIntersectionWithMirrors(newClosestDistance, l);

    closestPoint = findClosestPoint(closestDistance, newClosestDistance, closestPoint, mirrorIntersect);

    delete mirrorIntersect;


    Point * crystalIntersect = getClosestIntersectionWithCrystals(newClosestDistance, l);

    closestPoint = findClosestPoint(closestDistance, newClosestDistance, closestPoint, crystalIntersect);

    delete crystalIntersect;


    Point * nukeIntersect = getClosestIntersectionWithNukes(newClosestDistance, l);

    closestPoint = findClosestPoint(closestDistance, newClosestDistance, closestPoint, nukeIntersect);

    delete nukeIntersect;


    Point * lensIntersect = getClosestIntersectionWithLenses(newClosestDistance, l);

    closestPoint = findClosestPoint(closestDistance, newClosestDistance, closestPoint, lensIntersect);

    delete lensIntersect;


    return closestPoint;
}

void Level::addMirror(const Mirror & m)
{
    mirrors.push_back(m);
}

void Level::addNuke(const Nuke & n)
{
    nukes.push_back(n);
}

void Level::addWall(const Wall & w)
{
    walls.push_back(w);
}

void Level::addCrystal(const Crystal & c)
{
    crystals.push_back(c);
}

void Level::addLens(const Lens & l)
{
    lenses.push_back(l);
}

void Level::addRay(const Ray & r)
{
    rays.push_back(r);
}

