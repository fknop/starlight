#include "level.h"

#include <string>

using namespace std;

Level::Level(int w, int h) : width {w}, height {h},
walls { {{0, 0}, {0, h}}, {{0, h}, {w, h}},
    {{w, h}, {w, 0}}, {{w, 0}, {0, 0}}
}
{
    // TODO : valider width et height
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
    throw string {"todo !"};
}
