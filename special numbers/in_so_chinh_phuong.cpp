#include<iostream>
#include<math.h>
using namespace std;

/*So chinh phuong la so nguyen co can bac hai cung la mot so nguyen. 
VD: so 4 co sqrt(4) = 2*/
bool kiem_tra_so_chinh_phuong(int n)
{
	if (n < 1)
		return false;
	int i = sqrt(n); // dat i la 1 so can bac 2
	if  (i * i == n) // binh phuong 1 so can bac 2 bang so ban dau thi la so chinh phuong
		return true;
	return false;
}
void in_so_chinh_phuong(int n)
{
	for (int i=0; i < n; i++)
	{
		if (kiem_tra_so_chinh_phuong(i))
			cout << i << "   ";
	}
}

int main()
{
	int n;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Cac so chinh phuong trong khoang (0," << n << ") la: ";
	in_so_chinh_phuong(n);
	return 0;
}

