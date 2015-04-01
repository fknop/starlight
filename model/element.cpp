#include "element.h"
#include "mirror.h"
#include "crystal.h"
#include "lens.h"
#include "nuke.h"
#include "wall.h"
#include "dest.h"
#include <typeinfo>

Element::Element(Element::Type type)
{
    this->type = type;
}

Element::~Element()
{

}

Element::Type Element::getType()
{
    return this->type;
}
