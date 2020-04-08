#include "travel_cost_utils/travel_cost_utils.hpp"
#include <list>

using namespace std;

namespace TravelCostUtils
{
    double FuelCost(double numMiles, double milesPerGallon, double costPerGallon)
    {
        return numMiles / milesPerGallon * costPerGallon;
    }

    double LodgingCost(double costPerNight, double numNights)
    {
        return costPerNight * numNights;
    }

    double MiscCost(std::list<double> costs)
    {
        // Sum up misc costs
        double sum = 0.0;
        for (double cost : costs) {
            sum += cost;
        }

        return sum;
    }
}
