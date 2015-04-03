#include "test.h"
#ifdef RUNTEST

#include <cmath>

#include "catch.hpp"
#include "model/ellipse.h"
#include "model/rectangle.h"
#include "model/line.h"
#include "model/linesegment.h"
#include "model/constants.h"

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
        delete p;
    }

    SECTION("Non-intersection de deux droites verticales")
    {
        Point * p = nullptr;
        Line vl2(Point(0,0), Point(0,10));
        bool b = vl.intersects(vl2, &p);
        REQUIRE(b == false);
        REQUIRE(p == nullptr);
        delete p;
    }

    SECTION("Intersection droite / droite")
    {
       Point* p = nullptr;
       Line l2(Point(5,0), M_PI_4);
       bool b = l.intersects(l2, &p);
       REQUIRE(b == true);
       REQUIRE(*p == Point(2.5, 2.5));
       delete p;
    }
}

TEST_CASE("Intersections ellipses, droites, segments")
{

    Ellipse ellipse(Point(20,20), 20, 10);
    std::vector<Point> points;
    SECTION("Intersection ellipse, droite")
    {
        Line l(Point(20, 0), M_PI_2);
        int nb = ellipse.intersects(l, points);
        REQUIRE(nb == 2);
        REQUIRE(points.at(0) == Point(20, 30));
        REQUIRE(points.at(1) == Point(20, 10));
    }

    SECTION("Intersection ellipse, droite n°2")
    {
        Line l(Point(0,0), -M_PI_4);
        int nb = ellipse.intersects(l, points);
        REQUIRE (nb == 2);
        /*
         * Round pour éviter de préciser une valeur exacte avec
         * trop de décimale
         */
        REQUIRE(std::round(points.at(0).x()) == 29.0);
        REQUIRE(std::round(points.at(0).y()) == 29.0);
        REQUIRE(std::round(points.at(1).x()) == 11.0);
        REQUIRE(std::round(points.at(1).y()) == 11.0);
    }


    SECTION("Intersection ellipse, segment")
    {
        LineSegment l(Point(0,0), Point(20,20));
        int nb = ellipse.intersects(l, points);
        REQUIRE(nb == 1);
        REQUIRE(std::round(points.at(0).x()) == 11.0);
        REQUIRE(std::round(points.at(0).y()) == 11.0);
    }
}

TEST_CASE("Intersections rectangle, droite, segment")
{
    /* x : 10 -> 5.
     * y : 10 -> 14
     */
    Rectangle rec(Point(10,10), 5, 4);
    std::vector<Point> points;
    SECTION("Intersection rectangle, droite")
    {
        Line l(Point(0,0), -M_PI_4);
        int nb = rec.intersects(l, points);
        REQUIRE(nb == 2);
        REQUIRE(points.at(0) == Point(10,10));
        REQUIRE(points.at(1) == Point(14,14));
    }

    SECTION("Intersection rectangle, segment")
    {
        LineSegment ls(Point(0,0), Point(13,13));
        int nb = rec.intersects(ls, points);
        REQUIRE(nb == 1);
        REQUIRE(points.at(0) == Point(10,10));
    }
}


#endif


