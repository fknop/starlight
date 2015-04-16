#include "tests/test.h"

#ifdef RUNTEST
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "model/point.h"
#include "utils/umath.h"

TEST_CASE("Test créations de points")
{
    Point p(3,4);

    SECTION("Test constructeur")
    {
        REQUIRE(p.x() == 3);
        REQUIRE(p.y() == 4);
    }

    SECTION("Test constructeur de recopie")
    {
        Point p2(p);
        REQUIRE(p2.x() == 3);
        REQUIRE(p2.y() == 4);
    }

    SECTION("Test opérateur d'assignation")
    {
        Point p3 = p;
        REQUIRE(p3.x() == 3);
        REQUIRE(p3.y() == 4);
    }
}

TEST_CASE("Opérateurs")
{
    Point p1(4,5);
    Point p2(4,5);
    Point p3(6,7);
    SECTION("Opérateur d'égalité")
    {
        REQUIRE(p2 == p1);
        REQUIRE(!(p2 == p3));
        REQUIRE(p2 == Point(4,5));
    }

    SECTION("Opérateur d'infériorité")
    {
        REQUIRE(p1 < p3);
    }


}

TEST_CASE("Distance")
{
    Point p1(0,0);
    Point p2(4,0);
    Point p3(1,1);
    SECTION("Test distance_1")
    {
        REQUIRE(p1.distance(p2) == 4);
    }
}

#endif
