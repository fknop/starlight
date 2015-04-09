#include "test.h"
#ifdef RUNTEST

#include "catch.hpp"
#include "model/level.h"


TEST_CASE("Tests du bon fonctionnement des éléments du jeu")
{
    Level *level = new Level(400,400);
    Source s(Point(0,200), 15, 0, 600);
    Dest d(Point(300, 200), 15);

    SECTION("Test si la destination s'allume")
    {
        level->set_source(s);
        level->set_dest(d);
        Source* s = &const_cast<Source&>(level->source());
        s->set_on(true);
        REQUIRE(level->dest().lighted_up() == true);
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
}



#endif
