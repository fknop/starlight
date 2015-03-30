#include "element.h"
#include "mirror.h"
#include "crystal.h"
#include "lens.h"
#include "nuke.h"
#include "wall.h"
#include "dest.h"
#include <typeinfo>

Element::Element()
{

}

Element::~Element()
{

}


bool Element::isMirror()
{
    try
    {
        dynamic_cast<Mirror&> (*this);
        return true;
    }
    catch(std::bad_cast e)
    {
        return false;
    }
}

bool Element::isCrystal()
{

}

bool Element::isLens()
{

}

bool Element::isDest()
{

}

bool Element::isNuke()
{

}

bool Element::isWall()
{

}
