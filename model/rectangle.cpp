#include <algorithm>

#include "geometry.h"
#include "rectangle.h"
#include "algorithm"

Rectangle::Rectangle(const Point & upperLeft, double width, double height)
    : upper_left_ {upperLeft}, width_{width}, height_{height}
{
    if (width <= 0 || height <= 0)
        throw std::string("Dimensions invalides");
}
