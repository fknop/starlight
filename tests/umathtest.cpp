#include "test.h"
#ifdef RUNTEST

#include "catch.hpp"

#include "model/point.h"
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

TEST_CASE("Test conversions pente/radians/degrés")
{
    REQUIRE(umath::slope_to_rad(1) == -PI_4);
    REQUIRE(umath::equals(umath::rad_to_slope(-PI_4), 1));
    REQUIRE(umath::rad_to_deg(PI) == 180);
    REQUIRE(umath::rad_to_deg(PI_2) == 90);
    REQUIRE(umath::rad_to_deg(-PI_2) == -90);
    REQUIRE(umath::deg_to_rad(180) == PI);
    REQUIRE(umath::deg_to_rad(270) == 3 *PI_2);
    REQUIRE(umath::deg_to_rad(45) == PI_4);
    REQUIRE(umath::equals(umath::points_to_rad(Point(0,0), Point(1,1)), -PI_4));
}

#endif
