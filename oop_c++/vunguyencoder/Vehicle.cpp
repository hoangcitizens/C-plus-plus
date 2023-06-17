// file dinh nghia functions
#include "Vehicle.h"

Vehicle::Vehicle(string name) : modeName(name) {}
void Vehicle::run() { cout << modeName << " is running." << endl; }
