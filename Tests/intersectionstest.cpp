


#include "test.h"
#ifdef RUNTEST

#include "catch.hpp"
#include "model/ellipse.h"
#include "model/rectangle.h"
#include "model/line.h"
#include "model/linesegment.h"

TEST_CASE("Intersections droites, segments")
{
    Line l(Point(0,0), Point(5,5));
    Line vl(Point(4,0), Point(4, 10));


    SECTION("Intersection droite / droite verticale")
    {
        Point * p = nullptr;
        bool b = l.intersects(vl, &p);
        REQUIRE(b == true);
        REQUIRE(*p == Point(4,4));
    }
    SECTION("Intersection droite / segment")
    {

    }
}

TEST_CASE("Intersections ellipses, droites, segments")
{
    SECTION("Intersection ellipse, droite")
    {

    }

    SECTION("Intersection ellipse, segment")
    {

    }
}

TEST_CASE("Intersections rectangle, droite, segment")
{
    SECTION("Intersection rectangle, droite")
    {

    }

    SECTION("Intersection rectangle, segment")
    {

    }
}


#endif


