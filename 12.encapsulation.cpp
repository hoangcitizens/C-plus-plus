/*
	encapsulation : tinh dong goi (thuoc tinh du lieu duoc dong goi ben trong, cac properties khong truy cap duoc tu ben ngoai)

*/


#include<iostream>
#include<string>
using namespace std;

// dung struct cho doi tuong co du lieu nho don gian va khong di kem voi phuong thuc
struct BodySize
{
	float weigh;
	int size3ring[3];
};

class Woman
{
public:
	Woman(string fullname, int age, float weigh)
	{
		this->fullname = fullname;
		this->age = age;
		this->bodySize.weigh = weigh;
		this->bodySize.size3ring[0] = 0;
		this->bodySize.size3ring[1] = 0;
		this->bodySize.size3ring[2] = 0;
	}
	void introduce()
	{
		cout << "Hi ! My name is " << fullname << ".\n";
		cout << "How I am " << age << " year old.\n";
	}
	void setAge(int age) // ham truy cap va thao tac voi du lieu cua thuoc tinh
	{
		this->age = age;
	}
	int getAge() // ham lay du lieu cua thuoc tinh
	{
		return age;
	}
private:
	BodySize bodySize;
	float weigh;
	string fullname;
	int age;
};

int main()
{
	Woman* hariwon = new Woman("Hariwon", 35, 50);
	hariwon->setAge(36);
	cout << hariwon->getAge() << endl;
	return 0;
}