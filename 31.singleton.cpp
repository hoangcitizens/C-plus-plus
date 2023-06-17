// singleton : don nhat, mot minh
/*
	B1: Dinh nghia lai ham khoi tao (nham gioi han lai kha nang cap phat dong cho doi tuong) 
	B2: Tạo static method de truy cap the hien duy nhat
	    Method kiem tra xem the hien duoc tao hay chua; neu chua thi tao moi co roi thi tra ve the hien do
	B3: Su dung the hien duy nhat
	- Chu y: Bien static phai khoi tao gia tri NULL
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

class VehicleManager // lop singleton quan ly cac vehicle
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
	// lay ra object
	static VehicleManager* getManger()
	{
		if (manager == NULL)
			manager = new VehicleManager();
		return manager;
	}
private:
	vector<Vehicle2*> vehicles;
	static VehicleManager* manager; // luu object
	VehicleManager() {}
};

VehicleManager* VehicleManager::manager = NULL; // khoi tao gia tri cho bien static

int main()
{
	Vehicle2* taxi = new Vehicle2("Kia Morning");
	Vehicle2* pickup = new Vehicle2("Ford Ranger");
	VehicleManager::getManger()->addVehicle(taxi); 
	VehicleManager::getManger()->addVehicle(pickup);
	VehicleManager::getManger()->start();
	return 0;
}