/*
	
*/

#include<iostream>
#include<string>
using namespace std;

class Vehicle2
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
	void run()
	{
		cout << "A vehicle is running !" << endl;
	}
private:
	string modeName;
};

class Taxi : public Vehicle2
{
public:
	void run()
	{
		Vehicle2::run();
		cout << "It's a taxi !" << endl;
	}
	void run(int km) // la ham set
	{
		kmCounter = km;
	}
	int calculateFee() // tinh tien phai tra
	{
		return kmCounter * 10000;
	}
private:
	int kmCounter; // tinh km
};

class Truck : public Vehicle2
{
public:

private:

};

int main()
{
	Taxi* taxi = new Taxi;
	taxi->run(5);
	cout << "Fee " << taxi->calculateFee() << " VND" << endl;
	return 0;
}