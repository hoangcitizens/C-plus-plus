/*
	facade: mat tien (dung de chi dan cho nguoi dung)
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Vehicle2
{
public:
	Vehicle2(string name) : modeName(name)
	{}
	virtual void run() { cout << modeName << " is running." << endl; }
protected:
	const string modeName;
	string ownerName;
	string license;
};

class VehicleManager
{
public:
	void addVehicle(Vehicle2* vehicle)
	{
		vehicles.push_back(vehicle);
	}
	void start()
	{
		for (Vehicle2* vehicle : vehicles)
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
	vector<Vehicle2*> vehicles;
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
		Vehicle2* taxi = new Vehicle2("Kia Morning");
		Vehicle2* pickup = new Vehicle2("Ford Ranger");
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