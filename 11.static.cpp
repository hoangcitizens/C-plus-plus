/*
	static : tinh (co dinh)
	=> tao ra bien co anh huong den toan bo chuong trinh nhung cac bien do gan lien voi class nao do 
	   nhung ban chat do la bien global
*/

// bien static : giong bien global nhung no duoc gan lien voi class
// ham static: duoc goi khi khong can khoi tao object nao

#include<iostream>
#include<string>
using namespace std;
 
class Woman
{
public:
	static int numberOfWoman;
	static void what() 
	/* ham static khong goi duoc cac bien thanh vien cua object
	              nhung goi duoc khi bien do cung la static */
	{
		cout << "Woman is to be loved\n";
		cout << "There are " << numberOfWoman << " woman in program now\n"; // khong can chi dinh thuoc class vi cung la static voi ham
	}
	string fullname;
	int age;
	Woman()
	{
		fullname = "Unknown";
		age = 0;
	}
	Woman(string fullname, int age)
	{
		this->fullname = fullname;
		this->age = age;
		numberOfWoman++;
	}
	~Woman() {}
	void introduce()
	{
		cout << "Hi ! My name is " << fullname << ".\n";
		cout << "How I am " << age << " year old.\n";
	}
private:
	float weigh;
};

// bien static phai duoc khoi tao theo cach global (ngoai ham main)
int Woman::numberOfWoman = 0;

int main()
{
	Woman* hariwon = new Woman("Hariwon", 35);
	Woman* ngoctrinh = new Woman("Ngoc Trinh", 29);
	cout << Woman::numberOfWoman << "\n"; // goi bien static phai duoc chi dinh o class cu the
	Woman::what(); // goi ham static thuoc class Woman
	return 0;
}