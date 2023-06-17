/*
	Initialization List : danh sach khoi tao
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person{};

class Vehicle2
{
public:
	// danh sach khoi tao
	Vehicle2(string name, int year, Person &person) : modeName(name), manufactureYear(year), owner(person), frameSize{2,1.6,1.2}{}
	virtual void run()
	{
		cout << modeName << " is running !" << endl;
	}
protected:
	const string modeName; // bien const khong the gan lai gia tri va phai khoi tao luon
	int manufactureYear;
	Person& owner; // neu khong co & thi person se thuoc vehicle ma vehicle khong so huu 1 con nguoi duoc ma chi lien quan den person
				   // phai dung & hoac * , & la kieu du lieu dac biet vi khong the thay doi duoc tham chieu den kieu du lieu khac
	float frameSize[3]; // muon gan gia tri cho mang phai gan tung gia tri
};

class Taxi : public Vehicle2
{
public:
	Taxi(string name, int year, Person& person) : Vehicle2(name, year, owner)
	{
	}
	void run() override
	{
		cout << "A car is running !" << endl;
	}
};

int main()
{
	Person hoang;
	Taxi* taxi = new Taxi("Kia Morning", 2023, hoang); // tao object taxi lien quan den person
	return 0;
}