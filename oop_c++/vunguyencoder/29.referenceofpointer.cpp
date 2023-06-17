#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

struct RegisterInfo
{
	RegisterInfo(){}
	// const dung de copy du lieu ma khong duoc thay doi du lieu goc chuyen vao
	RegisterInfo(const RegisterInfo& otherInfo)
	{
		cout << "Clone a register info." << endl;
	}
	string license;// so dang ki
	string owerName; // ten chu xe
};

class Vehicle2
{
public:
	// pass by value hieu nang khong cao do phai copy du lieu
	// pass by referance copy dia chi lam tang toc do chuong trinh
	Vehicle2(const string& name,const RegisterInfo& info) // RegisterInfo& info = infoVu;
		: modeName(name),
		owerName(info.owerName),
		license(info.license)
	{}
	virtual void run() { cout << "A vehicle is running...!" << endl; }
protected:
	const string modeName;
	string owerName;
	string license;
};

class Taxi
{

};

int main()
{
	RegisterInfo infoVu;
	infoVu.owerName = "Vu";
	infoVu.license = "29P1-12345";
	Vehicle2* taxi = new Vehicle2("Kia Morning", infoVu);
	taxi->run();
	return 0;
}