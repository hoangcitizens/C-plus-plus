/*
	interface: ( phat trien dua tren abstract class)
	toan bo function trong class deu la pure virtual function thi thanh interface
*/

#include<iostream>
#include<string>
using namespace std;

class Vehicle2 
{
public:
	virtual string getModeName() = 0; // pure virtual function
	virtual void setModeName(string modeName) = 0;
	virtual void run() = 0; 
protected:
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
	string getModeName()
	{
		return modeName;
	}
	void setModeName(string modeName)
	{
		this->modeName = modeName;
	}
	void run() override
	{
		cout << "A car of " << ownerName << " is running !" << endl;
	}
private:
	string ownerName;
};

int main()
{
	Car* car = new Car();
	car->run();
	return 0;
}