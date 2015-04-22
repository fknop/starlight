#include "test.h"

#ifdef RUNTEST

#include <algorithm>
#include <vector>
#include "model/point.h"
#include "tests/catch.hpp"

TEST_CASE("Sort des points selon la distance avec une lambda")
{

    Point origin(0,0);
    Point p(16,16);
    std::vector<Point> points
    {
                Point(4,4),
                Point(5,5),
                Point(2,2),
                Point(10,10),
                Point(15,15),
                Point(3,3),
                Point(6,6),
                Point(7,7),
                Point(1,1),
                Point(3,3),
                Point(9,9)
    };

    SECTION ("Distance avec l'origine")
    {
        std::sort(points.begin(), points.end(),
            [origin](const Point& p1, const Point& p2) -> bool
        {
            double da = p1.distance(origin);
            double db = p2.distance(origin);
            return da < db;
        });


        REQUIRE(points.at(0) == Point(1,1));
        REQUIRE(points.at(1) == Point(2,2));
        REQUIRE(points.at(2) == Point(3,3));
        REQUIRE(points.at(3) == Point(3,3));
        REQUIRE(points.at(4) == Point(4,4));
        REQUIRE(points.at(5) == Point(5,5));
        REQUIRE(points.at(6) == Point(6,6));
        REQUIRE(points.at(7) == Point(7,7));
        REQUIRE(points.at(8) == Point(9,9));
        REQUIRE(points.at(9) == Point(10,10));
        REQUIRE(points.at(10) == Point(15,15));
    }

    SECTION("Distance avec Point(16,16)")
    {
        std::sort(points.begin(), points.end(),
            [p](const Point& p1, const Point& p2) -> bool
        {
            double da = p1.distance(p);
            double db = p2.distance(p);
            return da < db;
        });


        REQUIRE(points.at(0) == Point(15,15));
        REQUIRE(points.at(1) == Point(10,10));
        REQUIRE(points.at(2) == Point(9,9));
        REQUIRE(points.at(3) == Point(7,7));
        REQUIRE(points.at(4) == Point(6,6));
        REQUIRE(points.at(5) == Point(5,5));
        REQUIRE(points.at(6) == Point(4,4));
        REQUIRE(points.at(7) == Point(3,3));
        REQUIRE(points.at(8) == Point(3,3));
        REQUIRE(points.at(9) == Point(2,2));
        REQUIRE(points.at(10) == Point(1,1));
    }

}


#endif
