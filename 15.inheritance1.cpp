/*
	inheritance : tinh ke thua < class thua huong tinh chat , properties, method cua cac class khac > 
	parrent class (base class / super class) : clas goc / class cha (class co so)
	child class (derived class / sub class): class ke thua / class con (class dan xuat)
*/

#include<iostream>
#include<string>
using namespace std;

class Vehicle2 // class cha lop phuong tien giao thong
{
public:
	void setModeName(string modeName)
	{
		this->modeName = modeName;
	}
	string getModeName()
	{
		return modeName;
	}
	void setVersion(int version)
	{
		this->version = version;
	}
	int getVersion()
	{
		return version;
	}
private:
	string modeName; // ten mau xe
	int version; // phien ban
};

class Taxi : public Vehicle2 // class Taxi ke thua all properties and method
{

};

class Truck : public Vehicle2
{

};

int main()
{
	Taxi* taxi = new Taxi;
	taxi->setModeName("Kia Morning");
	cout << taxi->getModeName() << endl;
	return 0;
}