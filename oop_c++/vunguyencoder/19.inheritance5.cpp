/*

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
	Vehicle2(string modeName)
	{
		this->modeName = modeName;
		cout << "Created a vehicle with name "<< modeName << endl;
	}
	void setModeName(string modeName)
	{
		this->modeName = modeName;
	}
	string getModeName()
	{
		return modeName;
	}
protected:
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
	/* khi khoi tao child class co ke thua cua parrent class thi no se khoi tao cua parrent class truoc
	   sau do co thuoc tinh private nao cua child thi se them vao
	*/
	Taxi() : Vehicle2()
	{

	}
	Taxi(string modeName) : Vehicle2(modeName)  // gia tri chuyen cho tham so cua ham khoi tao cha chinh la cua ham khoi tao con
	// chi dinh toi ham khoi tao o parrent class de dinh nghia lai
	{
		cout << "Created a taxi !" << endl;
	}
	void start()
	{
		cout << "Started. Ready to run" << endl;
		run();
	}
private:
	int kmCounter;
};

class Truck : private Vehicle2 
{
public:

private:

};

int main()
{
	Taxi* taxi = new Taxi("Kia Morning"); // ham khoi tao thong qua toan tu new
	Taxi* taxi2 = new Taxi("Vinfast Fadil");
	return 0;
}