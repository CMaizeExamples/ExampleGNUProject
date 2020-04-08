#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <travel_cost_utils/travel_cost_utils.hpp>

using namespace TravelCostUtils;

TEST_CASE( "TravelCostUtils computes correct results", "[TravelCostUtils]" ) {

    // test FuelCost
    double numMiles = 1000.0;
    double milesPerGallon = 30.0;
    double costPerGallon = 3.00;
    REQUIRE( FuelCost(numMiles, milesPerGallon, costPerGallon) == Approx(100.0) );

    // test LodgingCost
    double costPerNight = 12.34;
    double numNights = 3.00;
    REQUIRE( LodgingCost(costPerNight, numNights) == Approx(37.02) );

    // test MiscCost
    std::list<double> miscCostsList = { 1.0, 2.0, 3.3, 4.44 };
    REQUIRE( MiscCost(miscCostsList) == Approx(10.74) );
}
