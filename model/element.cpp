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
    type_ = type;
}

Element::~Element()
{

}

Element::Type Element::type() const
{
    return type_;
}
