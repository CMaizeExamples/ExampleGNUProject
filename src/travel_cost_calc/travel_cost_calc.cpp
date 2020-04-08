#include <iostream>
#include <string>
#include <iomanip>
#include <travel_cost_utils/travel_cost_utils.hpp>

using namespace std;

int main()
{
    // Calculate fuel cost
    double numMiles = 1000.0;
    double milesPerGallon = 30.0;
    double costPerGallon = 3.00;
    double fuelCost = TravelCostUtils::FuelCost(numMiles, milesPerGallon, costPerGallon);

    // Calculate lodging cost
    double costPerNight = 75;
    double numNights = 3;
    double lodgingCost = TravelCostUtils::LodgingCost(costPerNight, numNights);

    // Calculate misc costs
    list<double> miscCostsList = { 35.0, 29.99, 50.0, 99.49 };
    double miscCosts = TravelCostUtils::MiscCost(miscCostsList);

    // Create an output string stream
    ostringstream ss;

    // Set precision to 2 digits
    ss << fixed;
    ss << setprecision(2);

    // Add our messages to the string stream
    ss << "Total Fuel Cost: " << fuelCost << endl;
    ss << "Total Lodging Cost: " << lodgingCost << endl;
    ss << "Total Miscellaneous Costs: " << miscCosts << endl;

    // Print  the string stream
    cout << ss.str();
    return 0;
}
