/*
	overriding : ghi de (cho child class co the dinh nghia lai method o parrant class)
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
		Vehicle2::run(); // ke thua method cua parrant class
		cout << "It's a taxi !" << endl; // them thong tin moi cho child class
	}
private:

};

class Truck : public Vehicle2
{
public:

private:

};

int main()
{
	Taxi* taxi = new Taxi;
	taxi->run();
	return 0;
}