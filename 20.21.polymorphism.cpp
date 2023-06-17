/*
	polymorphism : tinh da hinh ( the hien nhieu hinh dang sac thai trong cung 1 su vat hien tuong )
	type casting : ep kieu du lieu
	Up-casting : ep tu dan xuat ve co so
	Down-casting : ep tu co so ve dan xuat
*/

#include<iostream>
#include<string>
using namespace std;

class Vehicle2
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
	void run()
	{
		cout << "A vehicle is running !" << endl;
	}
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
	void run()
	{
		cout << "A car of " << ownerName << "is running !" << endl;
	}
private:
	string ownerName;
};

class Truck
{

};
int main()
{
/*
	Vehicle* vehicle = new Vehicle(); // object car cung la 1 object nhung co the chuyen ve nhieu hinh thai
	//((Vehicle*)car)->run(); // ep kieu ve Vehicle (up-casting)
	((Car*)vehicle)->run(); // down-casting ep kieu sang Car thi se khong tu dong khoi tao them thuoc tinh
*/
	Car* car = new Car();
	Vehicle2* vehicle = car;// <=> (Vehilce*)car // up-casting
	/* 
		tao 1 con tro vehicle gan cho class Car ep kieu Vehicle
		up-casting ep kieu thong qua phep gan 
	*/
	((Car*)vehicle)->run(); // down-casting
	// chuyen doi kieu du lieu khong lam thay doi du lieu goc o object ban dau
	return 0;
}