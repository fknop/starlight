#include "test.h"

#ifdef RUNTEST

#include "catch.hpp"
#include "model/line.h"
#include "model/point.h"

#include "utils/constants.h"
#include "utils/umath.h"


TEST_CASE("Test constructeur")
{

    SECTION("Constructeur avec points")
    {
        Line l(Point(0,0), Point(4,4));

        REQUIRE(umath::equals(l.slope(), 1));
        REQUIRE(umath::equals(l.alpha(), -PI_4));
        REQUIRE(umath::equals(l.get_x(1), 1));
        REQUIRE(umath::equals(l.get_y(1), 1));
        REQUIRE(l.horizontal() == false);
        REQUIRE(l.vertical() == false);
    }

    SECTION("Constructeur point et angle")
    {
        Line l(Point(0,0), -PI_4);

        REQUIRE(umath::equals(l.slope(), 1));
        REQUIRE(umath::equals(l.alpha(), -PI_4));
        REQUIRE(umath::equals(l.get_x(1), 1));
        REQUIRE(umath::equals(l.get_y(1), 1));
        REQUIRE(l.horizontal() == false);
        REQUIRE(l.vertical() == false);
    }

    SECTION("Constructeur a b c")
    {
        Line l(-1, 1, 0);
        REQUIRE(umath::equals(l.slope(), 1));
        REQUIRE(umath::equals(l.alpha(), -PI_4));
        REQUIRE(umath::equals(l.get_x(1), 1));
        REQUIRE(umath::equals(l.get_y(1), 1));
        REQUIRE(l.horizontal() == false);
        REQUIRE(l.vertical() == false);
    }
}

TEST_CASE("Droite verticale")
{
    Line l(Point(4,0), Point(4, 5));
    REQUIRE(umath::equals_inf(l.slope()));
    REQUIRE(umath::equals(l.alpha(), -PI_2));
    REQUIRE(umath::equals(l.get_x(0), 4));
    REQUIRE(umath::equals_inf(l.get_y(0)));
    REQUIRE(l.horizontal() == false);
    REQUIRE(l.vertical() == true);
}

TEST_CASE("Droite horizontale")
{
    Line l(Point(0,0), Point(5,0));
    REQUIRE(umath::equals(l.slope(), 0));
    REQUIRE(umath::equals(l.alpha(), 0));
    REQUIRE(umath::equals_inf(l.get_x(0)));
    REQUIRE(umath::equals(l.get_y(0), 0));
    REQUIRE(l.horizontal() == true);
    REQUIRE(l.vertical() == false);
}

TEST_CASE("Droites perpendiculaires et parallèles")
{
    Line l(Point(0,0), Point(5,0));
    Line l2(Point(4,0), Point(4, 5));
    REQUIRE(l.perpendicular(l2) == true);
    REQUIRE(l.parallel(l2) == false);

    Line l3(Point(0,3), Point(4,3));
    REQUIRE(l.parallel(l3) == true);
    REQUIRE(l.perpendicular(l3) == false);
}

#endif
