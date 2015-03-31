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

Element::Type Element::getType()
{
    if (isMirror())
        return Element::Type::MIRROR;

    if (isCrystal())
        return Element::Type::CRYSTAL;

    if (isLens())
        return Element::Type::LENS;

    if (isDest())
        return Element::Type::DEST;

    if (isNuke())
        return Element::Type::NUKE;

    if (isWall())
        return Element::Type::WALL;
}

bool Element::isMirror()
{
    return (dynamic_cast<Mirror*> (this) != nullptr);
}

bool Element::isCrystal()
{
    return (dynamic_cast<Crystal*> (this) != nullptr);
}

bool Element::isLens()
{
    return (dynamic_cast<Lens*> (this) != nullptr);
}

bool Element::isDest()
{
    return (dynamic_cast<Dest*> (this) != nullptr);
}

bool Element::isNuke()
{
    return (dynamic_cast<Nuke*> (this) != nullptr);
}

bool Element::isWall()
{
    return (dynamic_cast<Wall*> (this) != nullptr);
}
