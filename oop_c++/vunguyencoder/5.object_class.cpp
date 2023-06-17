#include<iostream>
#include<string>
using namespace std;

class Woman
{
public:
	// cac thuoc tinh che do cong khai
	string fullname;
	float weight;
	// cac phuong thuc
	void makeUp()
	{

	}
	void introduce()
	{
		age = 34;
		cout << "I am Woman" << endl;
		cout << "I am " << age << " year old" << endl;
	}
private: // khong the truy cap o ben ngoai nhung voi thanh phan ben trong class thi van truy cap duoc voi nhau
	int age; // thuoc tinh trong rieng tu
};

int main()
{
	//Woman ngoc_trinh; // khai bao class cap phat tinh (cap vung nho trong bo nho Stack <dung luong nho ~ 1MB> nhung toc do nhanh)
	Woman* hariwon = new Woman; // cap phat dong (cap vung nho trong bo nho Heap <linh dong theo bo nho RAM> toc do cham hon)
	// => mot doi tuong thuoc kieu Woman co ten hariwon duoc tao ra
	hariwon->fullname = "Hariwon"; // truy cap bien de gan
	cout << "There is a woman named " << hariwon->fullname << "\n"; // truy cap bien de in ra
	hariwon->introduce(); // truy cap ham thanh vien
	return 0;
}