#ifndef TRAVEL_COST_UTILS_HPP
#define TRAVEL_COST_UTILS_HPP

#include <list>

namespace TravelCostUtils
{
    double FuelCost(double numMiles, double milesPerGallon, double costPerGallon);
    double LodgingCost(double costPerNight, double numNights);
    double MiscCost(std::list<double> costs);
}

#endif
