#include "crystal.h"
#include "dest.h"
#include "element.h"
#include "lens.h"
#include "mirror.h"
#include "nuke.h"
#include "wall.h"


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
