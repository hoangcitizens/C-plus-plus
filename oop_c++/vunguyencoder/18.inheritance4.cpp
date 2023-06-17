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
protected: // child class co the truy cap truc tiep nhung ben ngoai thi khong
	void run()
	{
		cout << "A vehicle is running !" << endl;
	}
private: // child class khong the truy cap truc tiep
	string modeName;
};

class Taxi : public Vehicle2 // thuoc tinh chi dinh truy cap cua parrent nhu nao thi child nhu vay
{
public:
	void start()
	{
		cout << "Started. Ready to run" << endl;
		run();
	}
private:
	
};

class Truck : private Vehicle2 // private la muc truy cap cao nhat
// all cac phuong thuc va thuoc tinh ke thua duoc se thanh private
{
public:

private:

};

int main()
{
	Taxi* taxi = new Taxi;
	taxi->setModeName("Kia Morning");
	cout << taxi->getModeName() << endl;
	return 0;
}