/*
	copyconstructor : 
	default copy constructor : ham khoi tao sao chep mac dinh
	deep copy: copy sau den ca cac thuoc tinh cap phat dong
	shallow copy: copy don thuan giua gia tri cua cac thuoc tinh
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Person  
{
public:
	Person(string name) : fullname(name) {}
	void setFullname(string name) { fullname = name; }
	string getFullname() { return fullname; }
private:
	string fullname;

};

class Vehicle2
{
public:
	Vehicle2(string name) : modeName(name) 
	{
	//	cout << "Create a vehicle " << name << endl;
	}
	// ham copyconstructor mac dinh duoc viet tuong minh
	Vehicle2(Vehicle2& otherVehicle)
	{
		//  cout << "Clone a vehicle " << otherVehicle.getModename() << endl;
		modeName = otherVehicle.getModename();
		// owner = otherVehicle.getOwner()->getFullname(); day la copy con tro nhung no chi copy dia chi => dia chi owner tu otherVehicle se copy lai cho owner cua Vehicle
		// vung nho dia chi tro den khong thay doi ( tao pointer moi bang pointer cu thi chung deu tro den cung 1 vung nho)
		// => du lieu lien quan den owner khong doi
		owner = new Person(otherVehicle.getOwner()->getFullname()); // tao ra 1 person khac
	}
	void setOwner(Person* person){ owner = person; }
	Person* getOwner() { return owner; } // tra ra 1 con tro (gia tri cua no la dia chi)

	string getModename(){ return modeName; }
	virtual void run()
	{
		cout << modeName << " is running !" << endl;
	}
protected:
	string modeName;
	Person* owner; // con tro vi no khong la phan tu trong vehicle ma la ben ngoai va lien quan den vehicle
};

int main()
{
	Person* person = new Person("Anh Vu");
	Vehicle2* vehicle1 = new Vehicle2("Kia Morning");	
	vehicle1->setOwner(person);
	Vehicle2* vehicle2 = new Vehicle2(*vehicle1); // tham so cua vehicle2 la gia tri cua Vehicle1
	//vehicle1->run();
	//vehicle2->run();
	vehicle2->getOwner()->setFullname("Nguyen Huu Hoang");
	cout << vehicle2->getOwner()->getFullname() << endl;
	cout << vehicle1->getOwner()->getFullname() << endl;
	return 0;
}