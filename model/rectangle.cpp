#include <algorithm>

#include "umath.h"
#include "rectangle.h"
#include "algorithm"

Rectangle::Rectangle(const Point& upper_left, double width, double height)
    : upper_left_ {upper_left}, width_{width}, height_{height}
{
    if (width <= 0 || height <= 0)
        throw std::string("Dimensions invalides");
}
