#include "test.h"

#ifdef RUNTEST

#include <algorithm>
#include <vector>
#include "model/point.h"
#include "catch.hpp"

TEST_CASE("Sort des points selon la distance avec une lambda")
{

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

    std::sort(points.begin(), points.end(),
        [](const Point& p1, const Point& p2) -> bool
    {
        double da = p1.distance(Point(0,0));
        double db = p2.distance(Point(0,0));
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


#endif
