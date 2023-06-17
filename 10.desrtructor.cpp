/*
	destructor : ham huy
*/

#include<iostream>
#include<string>
using namespace std;

class Message
{

};

class Woman
{
public:
	string fullname; // cac bien se tu dong huy khi delete vung nho cap phat dong
	int age;
	Message* msg;
	Woman()
	{
		fullname = "Unknown";
		age = 0;
	}
	Woman(string fullname, int age)
	{
		this->fullname = fullname;
		this->age = age;
	}
	~Woman() 
	// ham huy duoc goi khi thu hoi vung nho cua object
	{
		delete msg;
		/* neu thuoc tinh trong object la mot con tro tro toi vung nho dong
	       thi phai delete no trong ham delete cua object ngoai cung */
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
	Woman* hariwon = new Woman("Hariwon", 35);
	hariwon->introduce();
	Woman ngoctrinh; // cap phat tinh tu dong thu hoi khi thoat khoi pham vi ham hien tai cua no
	ngoctrinh.introduce();
	delete hariwon; // thu hoi vung nho cua object (ham huy duoc goi)
	return 0;
}