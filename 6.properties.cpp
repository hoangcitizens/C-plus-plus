/*
   properties: thuoc tinh
   data type : kieu du lieu
   variable name: ten bien
   declaration: khai bao
   initialization: khoi tao
*/ 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct BodySize
{	
	vector<int> size3ring;
	float weight;
};

class Woman
{
public:
	string fullname;
	BodySize bodySize; // cau truc trong lop
	void makeUp()
	{

	}
	void introduce()
	{
		age = 34;
		cout << "I am Woman" << endl;
		cout << "I am " << age << " year old" << endl;
	}
private:
	int age;
};

int main()
{
	Woman* hariwon = new Woman; // khai bao cac bien thong qua object => cac bien thanh vien trong object duoc khai bao theo
	// hariwon->age; => loi do bien age chua duoc khoi tao gia tri
	hariwon->fullname = "Hariwon";
	return 0;
}