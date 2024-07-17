#include<iostream>
#include<math.h>
using namespace std;

bool kiemTraTamGiac(int a, int b, int c) 
{
	if (abs(b - c) < a && a < b + c)
		return true;
	else
		return false;
}

int main()
{
	unsigned int a, b, c;
	cout << "Nhap vao so thu nhat : ";
	cin >> a;
	cout << "Nhap vao so thu hai : ";
	cin >> b;
	cout << "Nhap vao so thu ba : ";
	cin >> c;
	if (kiemTraTamGiac(a, b, c) == 1)
		cout << "Ba so " << a << " ," << b << " ," << c << " tao thanh 3 canh cua tam giac !" << endl;
	else
		cout << "Ba so " << a << " ," << b << " ," << c << " khong tao thanh 3 canh cua tam giac !" << endl;
	return 0;
}
