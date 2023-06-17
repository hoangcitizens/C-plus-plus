/*
	virtual funciton: ham ao
	Dung trong truong hop con tro co kieu la base class tro den object cua derived class
	Moi doi tuong co sac thai rieng, vua muon quan lys chung cac doi tuong nay ma van the hien net rieng
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
	// keyword virtual de obj base class goi duoc ham o derived class (the hien sac thai rieng cua obj)
	virtual void run() // dinh nghia ham ao 
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
	void run() override // doc code de hon
	{
		cout << "A truck is running !" << endl;
	}
private:
	int expirationYear;
};

class Motobike : public Vehicle2
{
public:
	void run() // neu khong override lai no se goi cua parrent
	{
		cout << "A motorbike is running !" << endl;
	}
private:
	
};

int main()
{
	// ep ve cung 1 kieu co so nhung van giu nguyen hinh thai goc cua no do dung ham virtual
	Vehicle2* car = new Car(); // khoi tao doi tuong car dung con tro cua lop co so de luu no
	Vehicle2* truck = new Truck(); 
	Vehicle2* motorbile = new Motobike();
	// => Ep kieu ve base class thi no se tao ra 1 lien ket ngam giua method cua derived class voi virtual method cua base class
	/* 
		y nghia cua up-casting => dua tat ca cac object cung kieu vao thanh 1 mang
		dua tat cac cac object cap phat dong vao 1 mang vao 1 mang dang con tro
	*/
	Vehicle2 *vehicle_list[3]; // ep ve cung 1 kieu de su dung nhung method chung cua object 1 cach de dang
	vehicle_list[0] = car;
	vehicle_list[1] = truck;
	vehicle_list[2] = motorbile;
	for (int i = 0; i < 3; i++)
	{
		vehicle_list[i]->run();
	}
	return 0;
}