#include<iostream>
#include<string>
#include<vector>
#include "Vehicle.h"
using namespace std;

class VehicleManager
{
public:
	void addVehicle(Vehicle* vehicle)
	{
		vehicles.push_back(vehicle);
	}
	void start()
	{
		for (Vehicle* vehicle : vehicles)
		{
			vehicle->run();
		}
	}
	static VehicleManager* getManger()
	{
		if (manager == NULL)
			manager = new VehicleManager();
		return manager;
	}
private:
	vector<Vehicle*> vehicles;
	static VehicleManager* manager;
	VehicleManager() {}
};

VehicleManager* VehicleManager::manager = NULL;

class VehicleApp // facade
{
public:
	VehicleApp() : version("1.0") {}
	void init() // khoi tao du lieu cho chuong trinh
	{
		Vehicle* taxi = new Vehicle("Kia Morning");
		Vehicle* pickup = new Vehicle("Ford Ranger");
		VehicleManager::getManger()->addVehicle(taxi);
		VehicleManager::getManger()->addVehicle(pickup);
	}
	void start()
	{
		// start any object
		VehicleManager::getManger()->start();
	}
private:
	string version;
};

int main()
{
	VehicleApp app;
	app.init();
	app.start();
	return 0;
}