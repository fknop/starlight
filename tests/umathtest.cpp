#include "test.h"
#ifdef RUNTEST

#include "catch.hpp"
#include "utils/constants.h"
#include "utils/umath.h"


TEST_CASE("Test égalité d'angle")
{
    SECTION("Test égalité d'angle sur l'intervalle 0-2PI")
    {
        REQUIRE(umath::angle_equals(PI, -PI) == true);
        REQUIRE(umath::angle_equals(-PI_4, PI_4 *3) == false);
        REQUIRE(umath::angle_equals(-PI_2, PI_2 *3) == true);
        REQUIRE(umath::angle_equals(0, 2*PI) == true);
        REQUIRE(umath::angle_equals(PI_4, -PI_4) == false);
    }

    SECTION("Test égalité d'angle sur l'intervalle 0-PI")
    {
        REQUIRE(umath::angle_equals_pi(PI, -PI) == true);
        REQUIRE(umath::angle_equals_pi(-PI_4, PI_4 *3) == true);
        REQUIRE(umath::angle_equals_pi(-PI_2, PI_2 * 3) == true);
        REQUIRE(umath::angle_equals_pi(-PI_2, PI_2) == true);
        REQUIRE(umath::angle_equals_pi(0, 2*PI) == true);
        REQUIRE(umath::angle_equals_pi(PI_4, -PI_4) == false);

    }
}

#endif
