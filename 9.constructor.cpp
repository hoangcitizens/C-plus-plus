/*
	constructor : ham khoi tao
	implicit : ngam dinh
	explicit : tuong minh
	imfinity value : gia tri bat dinh
*/
// => Muc dich constructor giup khoi tao gia tri ban dau cho bien thanh vien ben trong object

#include<iostream>
#include<string>
using namespace std;

class Woman
{
public:
	string fullname;
	int age;
	Woman() 
	// ham khoi tao khong tham so (ngam dinh) duoc viet tuong minh
	/* viet tuong minh ham khoi tao giup ta can thiep duoc vao qua trinh khoi tao object
	   cung cap gia tri ban dau cho object tranh gia tri bat dinh cho bien */
	// ten ham cung ten class va khong duoc viet kieu tra ve
	{
		fullname = "Unknown";
		age = 0; // tao gia tri mac dinh cho object
	}
	Woman(string fullname, int age)
	// ham khoi tao tham so de vua khoi bien thanh vien cung nhu gan gia tri dung object do
	{
		this->fullname = fullname; // this de phan biet giua tham so va thuoc tinh khi ten tham so trung voi ten thuoc tinh
		this->age = age;
	}
	void introduce()
	{
		cout << "Hi ! My name is " << fullname << ".\n";
		cout << "How I am " << age << " year old.\n";
	}
private:
	float weigh;
};

int main()
{
	Woman* hariwon = new Woman; // ham khoi tao khong tham so duoc tu dong goi khi khoi tao ra doi tuong 
	hariwon->fullname = "Hariwon";
	hariwon->age = 35;
	hariwon->introduce();

	Woman* ngoctrinh = new Woman("Ngoc Trinh", 29); // ham khoi tao tham so duoc goi
	ngoctrinh->introduce();
	return 0;
}