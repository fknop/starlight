


#include "test.h"
#ifdef RUNTEST

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
        REQUIRE(points.at(0) == Point(28.9443, 28.9443));
        REQUIRE(points.at(1) == Point(11.0557, 11.0557));

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


