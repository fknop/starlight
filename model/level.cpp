#include "level.h"

#include <string>
#include "Geometry.h"

using namespace std;

Level::Level(double w, double h) : width {w}, height {h},
    walls { {{.0, .0}, {.0, h}}, {{.0, h}, {w, h}},
            {{w, h}, {w, .0}}, {{w, .0}, {.0, .0}} }
{
    if (w <= 0 || h <= 0)
        throw std::string("La taille et la longueur "
            "du plateau doivent etre strictement positives");

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

//template <class T>
void Level::computeRays()
{

    Point pSource = this->s.getPosition();
    double radians = this->s.getAngle();
    Line ray(pSource, radians);

}

//template <class T>
bool Level::computeRay(const Line & line, int wl)
{
    bool continueRay;

//    std::pair<Point*, T> intersection = getClosestIntersection(line);

}

//template <class T>
//std::pair<Point*, T> Level::getClosestIntersection(const Line& line)
//{

//}

void Level::notify(Observable * obs)
{
    for (Observer * o : observers)
        o->notify(obs);
}

