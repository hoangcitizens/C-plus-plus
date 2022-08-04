#include<iostream>
#include<math.h>
using namespace std;

/*So pitago la so mot so chinh phuong va bang tong cua hai so chinh phuong khac*/
bool so_chinh_phuong(int n)
{
	if (n < 1)
		return false;
	int i = sqrt(n);
	if (i * i == n)
		return true;
	return false;
}
bool so_pitago(int n)
{
	int count = 0;
	for (int i=1; i < n; i++)
	{
		for (int j=1; j < n; j++)
		{
			if ((i*i) + (j*j) == n) 
				count++;
		}
	}
	if (count == 0)
		return false;
	return true;
}

int main()
{
	unsigned int n;
	cout << "Nhap vao so nguyen duong n = ";
	cin >> n;
	if (so_pitago(n) == true)
		cout << n << " la so Pitago !" << endl;
	else
		cout << n << " khong la so Pitago !" << endl;
	return 0;
}

