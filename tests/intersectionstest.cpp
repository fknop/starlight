#include "tests/test.h"
#ifdef RUNTEST

#include <cmath>


#include "model/ellipse.h"
#include "model/rectangle.h"
#include "model/line.h"
#include "model/linesegment.h"
#include "utils/constants.h"
#include "utils/umath.h"
#include "tests/catch.hpp"

TEST_CASE("Intersections droites, segments")
{
    Line l(Point(0,0), Point(5,5));
    Line vl(Point(4,0), Point(4, 10));
    Point p;
    LineSegment result;
    bool do_intersect;
    bool is_point;


    SECTION("Intersection droite / droite verticale")
    {
        do_intersect = umath::intersects(l, vl, p, is_point);
        REQUIRE(do_intersect == true);
        REQUIRE(is_point == true);
        REQUIRE(p == Point(4,4));
    }

    SECTION("Non-intersection de deux droites verticales")
    {
        Line vl2(Point(0,0), Point(0,10));
        do_intersect = umath::intersects(vl, vl2, p, is_point);
        REQUIRE(do_intersect == false);
        REQUIRE(is_point == false);
    }

    SECTION("Intersection droite / droite")
    {
       Line l2(Point(5,0), PI_4);
       do_intersect = umath::intersects(l, l2, p, is_point);
       REQUIRE(do_intersect == true);
       REQUIRE(is_point == true);
       REQUIRE(p == Point(2.5, 2.5));
    }

    SECTION("Droites parallèles")
    {
        Line ll(Point(1,0), -PI_4);
        do_intersect = umath::intersects(l, ll, p, is_point);
        REQUIRE(do_intersect == false);
        REQUIRE(is_point == false);
    }

    SECTION("Intersection droite/segment")
    {
        LineSegment ls(Point(4,4), Point(8,8));
        do_intersect = umath::intersects(l, ls, p, result, is_point);
        REQUIRE(do_intersect == true);
        REQUIRE(is_point == false);
        REQUIRE(result == ls);
    }

    SECTION("Intersection droite/segment_2")
    {
        LineSegment ls(Point(4,0), Point(3,1));
        do_intersect = umath::intersects(l, ls, p, result, is_point);
        REQUIRE(do_intersect == false);
        REQUIRE(is_point == false);
    }



}

TEST_CASE("Intersections segments / segments")
{

    Point p;
    LineSegment result;
    bool is_point;
    bool do_intersect;

    SECTION("Intersection segment/segment")
    {
        LineSegment ls1(Point(0,0), Point(4,4));
        LineSegment ls2(Point(0,0), Point(4,4));
        do_intersect = umath::intersects(ls1, ls2, p, result, is_point);
        REQUIRE(do_intersect == true);
        REQUIRE(is_point == false);
        REQUIRE(result == ls1);
        REQUIRE(result == ls2);
    }

    SECTION("Intersection segment/segment_2")
    {
        LineSegment ls1(Point(0,0), Point(4,4));
        LineSegment ls2(Point(1,1), Point(4,4));
        do_intersect = umath::intersects(ls1, ls2, p, result, is_point);
        REQUIRE(do_intersect == true);
        REQUIRE(is_point == false);
        REQUIRE(result == ls2);
    }

    SECTION("Intersection segment/segment_3")
    {
        LineSegment ls1(Point(0,0), Point(4,4));
        LineSegment ls2(Point(1,1), Point(5,5));
        do_intersect = umath::intersects(ls1, ls2, p, result, is_point);
        REQUIRE(do_intersect == true);
        REQUIRE(is_point == false);
        REQUIRE(result == LineSegment(Point(1,1), Point(4,4)));
    }

    SECTION("Intersection segment/segment_4")
    {
        LineSegment ls1(Point(0,0), Point(4,4));
        LineSegment ls2(Point(5,5), Point(4,4));
        do_intersect = umath::intersects(ls1, ls2, p, result, is_point);
        REQUIRE(do_intersect == true);
        REQUIRE(is_point == true);
        REQUIRE(p == Point(4,4));
    }

    SECTION("Intersection segment/segment_5")
    {
        LineSegment ls1(Point(1,1), Point(4,4));
        LineSegment ls2(Point(-5,-5), Point(2,2));
        do_intersect = umath::intersects(ls1, ls2, p, result, is_point);
        REQUIRE(do_intersect == true);
        REQUIRE(is_point == false);
        REQUIRE(result == LineSegment(Point(1,1), Point(2,2)));
    }

    SECTION("Intersection segment/segment_6")
    {
        LineSegment ls1(Point(4,4), Point(8,8));
        LineSegment ls2(Point(0,0), Point(3,3));
        do_intersect = umath::intersects(ls1, ls2, p, result, is_point);
        REQUIRE(do_intersect == false);
    }

    SECTION("Intersection segment/segment_7")
    {
        LineSegment ls1(Point(0,5), Point(4,5));
        LineSegment ls2(Point(0,6), Point(4,6));
        do_intersect = umath::intersects(ls1, ls2, p, result, is_point);
        REQUIRE(do_intersect == false);
    }

}

TEST_CASE("Intersections ellipses, droites, segments")
{
    Ellipse ellipse(Point(20,20), 20, 10);
    std::vector<Point> points;

    SECTION("Intersection ellipse, droite")
    {
        Line l(Point(20, 0), PI_2);
        int nb = umath::intersects(ellipse, l, points);
        REQUIRE(nb == 2);
        REQUIRE(points.at(0) == Point(20, 30));
        REQUIRE(points.at(1) == Point(20, 10));
    }

    SECTION("Intersection ellipse, droite n°2")
    {
        Line l(Point(0,0), -PI_4);
        int nb = umath::intersects(ellipse, l, points);
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

    SECTION("Non-intersection ellipse - droite")
    {
        Line l(Point(50,0), -PI_2);
        int nb = umath::intersects(ellipse, l, points);
        REQUIRE(nb == 0);
    }

    SECTION("Tangente droite-ellipse")
    {
        Line l(Point(40,0), -PI_2);
        int nb = umath::intersects(ellipse, l, points);
        REQUIRE(nb == 1);
        REQUIRE(points.at(0) == Point(40, 20));
    }

    SECTION("Intersection ellipse, segment")
    {
        LineSegment l(Point(0,0), Point(20,20));
        int nb = umath::intersects(ellipse, l, points);
        REQUIRE(nb == 1);
        REQUIRE(std::round(points.at(0).x()) == 11.0);
        REQUIRE(std::round(points.at(0).y()) == 11.0);
    }
}

TEST_CASE("Intersections rectangle, droite, segment")
{

    Rectangle rec(Point(10,10), 5, 4);
    std::vector<Point> points;
    Rectangle rectangle(Point(20,0), 5., 5.);

    SECTION("Intersection rectangle, droite")
    {
        Line l(Point(0,0), -PI_4);
        int nb = umath::intersects(rec, l, points);
        REQUIRE(nb == 2);
        REQUIRE(points.at(0) == Point(10,10));
        REQUIRE(points.at(1) == Point(14,14));
    }

    SECTION("Intersection rectange droite avec un coin en intersection")
    {
        Rectangle r(Point(4,0), 4, 4);
        Line l(Point(0,0), -PI_4);
        umath::intersects(r, l, points);
        REQUIRE(points.at(0) == Point(4,4));
    }


    SECTION("Intersection rectangle, droite avec meme point origine")
    {

        Line l(Point(20,0), -PI_4);
        int nb = umath::intersects(rectangle, l, points);
        REQUIRE (nb == 2);
        REQUIRE(points.at(0) == Point(20, 0));
        REQUIRE(points.at(1) == Point(25, 5));
    }

    SECTION("Intersection rectangle, droite verticale")
    {
        Line l(Point(20, 0), PI_2);
        int nb = umath::intersects(rectangle, l, points);
        REQUIRE(nb == 2);
        REQUIRE(points.at(0) == Point(20, 0));
        REQUIRE(points.at(1) == Point(20, 5));

    }

    SECTION("Non-intersection rectangle-droite")
    {
        Line l(Point(0,10), -PI_4);
        int nb = umath::intersects(rectangle, l, points);
        REQUIRE(nb == 0);
    }

    SECTION("Intersection rectangle, segment")
    {
        LineSegment ls(Point(0,0), Point(13,13));
        int nb = umath::intersects(rec, ls, points);
        REQUIRE(nb == 1);
        REQUIRE(points.at(0) == Point(10,10));
    }
}

TEST_CASE("Vérification si un point est du bon coté selon l'angle de la droite")
{
    SECTION("Droite verticale")
    {
        Line l(Point(4,4), PI_2);
        Point p(4,5);
        bool b = umath::is_on_trajectory(l, Point(4,4), p);
        REQUIRE(b == false);
        Point p2(4,2);
        b = umath::is_on_trajectory(l, Point(4,4), p2);
        REQUIRE(b == true);
        // même point = faux
        Point p3(4,4);
        b = umath::is_on_trajectory(l, Point(4,4), p3);
        REQUIRE(b == false);
    }

    SECTION("Droite non verticale")
    {
        Line l(Point(10,10), -PI_4);
        Point p(3,3);
        bool b = umath::is_on_trajectory(l, Point(10,10), p);
        REQUIRE(b == false);
        Point p2(15,15);
        b = umath::is_on_trajectory(l,Point(10,10), p2);
        REQUIRE(b == true);
        Point p3(10,10);
        b = umath::is_on_trajectory(l, Point(10,10),  p3);
        REQUIRE(b == false);
    }
}

#endif


