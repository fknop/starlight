#include "test.h"

#ifdef RUNTEST

#include "catch.hpp"
#include "model/line.h"
#include "model/point.h"

#include "utils/constants.h"


TEST_CASE("Test constructeur")
{

    SECTION("Constructeur avec points")
    {
        Line l(Point(0,0), Point(4,4));

        REQUIRE(l.slope() == 1);
        REQUIRE(l.alpha() == -PI_4);
        REQUIRE(l.get_x(1) == 1);
        REQUIRE(l.get_y(1) == 1);
    }
}


#endif
