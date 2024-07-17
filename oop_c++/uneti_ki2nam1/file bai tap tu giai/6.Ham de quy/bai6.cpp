#include <iostream>
using namespace std;

void chuyenDia(int n, char x, char y, char z)
{ 
	if (n > 0) 
	{
		chuyenDia(n - 1, x, z, y);
		cout << x <<" -> "<< z <<endl;;
		chuyenDia(n - 1, y, x, z);
	}
}

int main()
{
	int n;
	cout<<"Nhap so dia la: ";
	cin>>n;
	cout<<"Viec chuyen dia nhu sau"<<endl;
	chuyenDia(n , 'A', 'B', 'C');
return 0;
}
