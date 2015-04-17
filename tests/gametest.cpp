#include "test.h"
#ifdef RUNTEST

#include "catch.hpp"
#include "model/level.h"
#include "utils/constants.h"


TEST_CASE("Tests du bon fonctionnement des éléments du jeu")
{
    Level* level = new Level(400,400);
    Source s(Point(0,200), 15, 0, 600);
    Dest d(Point(300, 200), 15);

    SECTION("Test si la destination s'allume")
    {
        level->set_source(s);
        level->set_dest(d);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->dest().lighted_up() == true);
        REQUIRE(level->rays().size() == 1);
        REQUIRE(level->rays().at(0).end() == Point(300,200));
    }

    SECTION("Test si une nuke s'allume")
    {
        Nuke* nuke = new Nuke(Point(200,200), 30);
        level->set_source(s);
        level->set_dest(d);
        level->add_nuke(*nuke);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->nukes().at(0).lighted_up() == true);
        REQUIRE(level->dest().lighted_up() == false);
    }

    SECTION("Test reflection mirroir vertical")
    {
        Mirror* mirror = new Mirror(Point(200,200), 0, 100, PI_2);
        level->set_source(s);
        level->set_dest(d);
        level->add_mirror(*mirror);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().size() == 2);
        REQUIRE(level->rays().at(0).end() == Point(200,200));
        REQUIRE(level->rays().at(1).end() == Point(15,200));
    }

    SECTION("Test reflection mirroir horizontal")
    {
        Mirror* mirror = new Mirror(Point(200,200), 0, 100, M_PI);
        level->set_source(s);
        level->set_dest(d);
        level->add_mirror(*mirror);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().size() == 2);
        REQUIRE(level->rays().at(0).end() == Point(100,200));
        REQUIRE(level->rays().at(1).end() == Point(15,200));
    }

    SECTION("Test reflection mirroir")
    {
        Mirror* mirror = new Mirror(Point(200,200), 50, 100, PI_4);
        level->set_source(s);
        level->set_dest(d);
        level->add_mirror(*mirror);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().size() == 2);
        REQUIRE(level->rays().at(0).end() == Point(200,200));
        REQUIRE(level->rays().at(1).end() == Point(200,0));
    }

    SECTION("Test reflection mirroir")
    {
        Mirror* mirror = new Mirror(Point(200,200), 50, 100, -PI_4);
        level->set_source(s);
        level->set_dest(d);
        level->add_mirror(*mirror);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().size() == 2);
        REQUIRE(level->rays().at(0).end() == Point(200,200));
        REQUIRE(level->rays().at(1).end() == Point(200,400));
    }

    SECTION("Test Cristal")
    {
        Crystal * crystal = new Crystal(Point(100,200), 50, 100);
        level->set_source(s);
        level->set_dest(d);
        level->add_crystal(*crystal);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().at(1).wavelength() == 700);
    }

    SECTION("Test Cristal_2")
    {
        Crystal * crystal = new Crystal(Point(100,200), 50, 300);
        level->set_source(s);
        level->set_dest(d);
        level->add_crystal(*crystal);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().at(1).wavelength() == 830);
    }

    SECTION("Test lentille")
    {
        Lens * lens = new Lens(Point(200, 180), 40, 40, 700, 750);
        level->set_source(s);
        level->set_dest(d);
        level->add_lens(*lens);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().size() == 1);
        REQUIRE(level->rays().at(0).end() == Point(200, 200));
    }

    SECTION("Test lentille_2")
    {
        Lens * lens = new Lens(Point(200, 180), 40, 40, 500, 750);
        level->set_source(s);
        level->set_dest(d);
        level->add_lens(*lens);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().size() == 2);
        REQUIRE(level->rays().at(0).end() == Point(200, 200));
        REQUIRE(level->rays().at(1).end() == Point(300, 200));
        REQUIRE(level->dest().lighted_up() == true);
    }

    SECTION("Test lentille et cristal")
    {
        Crystal * crystal = new Crystal(Point(100,200), 50, 100);
        Lens * lens = new Lens(Point(200, 180), 40, 40, 700, 750);
        level->set_source(s);
        level->set_dest(d);
        level->add_lens(*lens);
        level->add_crystal(*crystal);
        Source * s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->rays().size() == 3);
        REQUIRE(level->rays().at(0).end() == Point(50,200));
        REQUIRE(level->rays().at(1).start() == Point(150, 200));
        REQUIRE(level->rays().at(1).end() == Point(200,200));
        REQUIRE(level->rays().at(2).start() == Point(240, 200));
        REQUIRE(level->rays().at(2).end() == Point(300,200));
        REQUIRE(level->dest().lighted_up() == true);
    }
}



#endif
