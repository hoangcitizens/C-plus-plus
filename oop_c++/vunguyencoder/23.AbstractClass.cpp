/*
	abstract class : lop truu tuong ( class khong the khoi tao duoc )
	pure virtual : thuan ao
*/

#include<iostream>
#include<string>
using namespace std;

class Vehicle2 // class co function pure virtual thi no la abstract
{
public:
	Vehicle2()
	{
		cout << "Created a vehicle !" << endl;
	}
	string getModeName()
	{
		return modeName;
	}
	void setModeName(string modeName)
	{
		this->modeName = modeName;
	}
	// khong the khoi tao object ma can co cac class dan xuat ke thua no va dinh nghia lai virtual function do thi moi khoi tao duoc

	virtual void run() = 0; // pure virtual function
private:
	string modeName;
};

class Car : public Vehicle2
{
public:
	Car()
	{
		cout << "Created a Car !" << endl;
		ownerName = "Unknown";
	}
	void run() override
	{
		cout << "A car of " << ownerName << " is running !" << endl;
	}
private:
	string ownerName;
};

class Truck : public Vehicle2
{
public:
	Truck()
	{
		expirationYear = 0;
	}
	void run() override
	{
		cout << "A truck is running !" << endl;
	}
private:
	int expirationYear;
};

class Motobike : public Vehicle2 // khong override lai pure virtual function len thanh abstract class
{
public:
	
private:

};
class Scooter : public Motobike
{
	void run() override
	{
		cout << "A scooter is running !" << endl;
	}
};

int main()
{
	// se khong co object cua abstract class nhung se co object of child class
	// Vehicle* vehicle = new Vehicle(); loi vi co chua pure virtual function (ham khong co noi dung)
	Vehicle2* car = new Car(); 
	/*
		=> Class khong co object khi la abstract class. Nhung co cac object cua cac derived class
		   Luc nay vai tro cua base class de nhom cac obj cua derived class thanh 1 tap hop
		   (chi dung base class de lam con tro de quan ly cac obj derived)
	*/
	Vehicle2* truck = new Truck();
	// neu derived class nao ma khong override lai pure virtual function cua base class thi no cung se thanh abstract class
	// Vehicle* motorbile = new Motobike(); // loi vi luc nay no la abstract class
	Vehicle2* scootor = new Scooter();
	Vehicle2* vehicle_list[3]; // nhom cac object cua child class lai thanh 1 tap hop
	vehicle_list[0] = car;
	vehicle_list[1] = truck;
	vehicle_list[2] = scootor;
	for (int i = 0; i < 3; i++)
	{
		vehicle_list[i]->run();
	}
	return 0;
}