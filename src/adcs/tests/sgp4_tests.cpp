#include <CppUTest/TestHarness.h>
#include <external/sgp4/sgp4.h>
#include <external/sgp4/sgp4_utils.h>
#include <math.h>
#include <src/adcs/state_estimators/location_estimator.h>
#include <src/util/physical_constants.h>

TEST_GROUP(Sgp4){};

TEST(Sgp4, TestSpg4) {
    /* TLE IN USE:
    1 00005U 58002B   00179.78495062  .00000023  00000-0  28098-4 0  4753
    2 00005  34.2682 348.7242 1859667 331.7664  19.3264 10.824191574 13667
    */

    double position[3];
    double velocity[3];
    elsetrec satrec;
    Tle tle = Tle_init_zero;
    tle.epoch = 00179.78495062;
    tle.mean_motion = 10.824191574;
    tle.eccentricity_1e7 = 1859667;
    tle.inclination = 34.2682;
    tle.raan = 348.7242;
    tle.argument_of_perigee = 331.7664;
    tle.mean_anomaly = 19.3264;
    tle.bstar_drag = 0.000028098;

    Sgp4::InitialisePropagator(tle, satrec);
    Sgp4::Propagate(satrec, 360, position, velocity);

    // TEST DATA:
    // TIME: 360.00000000  WE EXPECT: -7154.03120202   -3783.17682504
    // -3536.19412294  4.741887409 -4.151817765 -2.093935425
    // TIME: 0.00000000   WE EXPECT:   7022.46529266   -1400.08296755 0.03995155
    // 1.893841015  6.405893759  4.534807250

    DOUBLES_EQUAL(-7154.03120202, position[0], 0.01);
    DOUBLES_EQUAL(-3783.17682504, position[1], 0.01);
    DOUBLES_EQUAL(-3536.19412294, position[2], 0.01);
    DOUBLES_EQUAL(4.741887409, velocity[0], 0.01);
    DOUBLES_EQUAL(-4.151817765, velocity[1], 0.01);
    DOUBLES_EQUAL(-2.093935425, velocity[2], 0.01);
}
