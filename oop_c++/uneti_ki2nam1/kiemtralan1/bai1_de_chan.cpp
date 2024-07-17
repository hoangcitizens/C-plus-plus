/* Nguyen Huu Hoang - msv:21103100320 - de chan
Bai 1 */
#include<iostream>
#include<math.h>
using namespace std;

int soBanBe(int n)
{
	int S = 0;
	for (int i=2; i<=int(sqrt(n)) ; i++)
	{
		if (n%i ==0)
		{
			if (i * i == n)
				S += 1;
			else
				S += (i + int(n/i));
		}
	}
	return S+1;
}

int main()
{
	unsigned int a, b;
	cout << "Nhap vao so nguyen duong thu nhat : ";
	cin >> a;
	cout << "Nhap vao so nguyen duong thu hai : ";
	cin >> b;
	if (a == soBanBe(b) && b == soBanBe(a))
		cout << "Hai so "<<a<<" va "<<b<<" la so ban be !"<<endl;
	else
		cout << "Hai so "<<a<<" va "<<b<<" khong la so ban be !"<<endl;
	return 0;
}
