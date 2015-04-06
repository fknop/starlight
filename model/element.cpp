#include "crystal.h"
#include "dest.h"
#include "element.h"
#include "lens.h"
#include "mirror.h"
#include "nuke.h"
#include "wall.h"


Element::Element(Element::Type type)
{
    this->type_ = type;
}

Element::~Element(){}


