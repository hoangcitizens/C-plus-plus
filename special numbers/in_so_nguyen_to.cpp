#include<iostream>
#include<math.h>
using namespace std;
/*So nguyen to la so chia het cho 1 va chinh no*/
bool kiem_tra_so_nguyen_to(int n)
{
	if (n < 2)
		return false;
	else
	{
	/* Xet i den can n vi luon ton tai mot uoc khac 1 trong 
	khoang (1;sqrt(n)] thi se luon co 1 uoc khac n trong khoang [sqrt(n);n) */
		for (int i=2 ; i <= sqrt(n); i++) 				
		{
			if (n % i == 0)
				return false; // Chi can mot uoc khac 1 la tra ve false luon
		}
		return true;
	}
}
void in_so_nguyen_to(int n)
{
	for (int i=0; i < n; i++)
	{
		if (kiem_tra_so_nguyen_to(i))
			cout << i << "   ";
	}
}
int main()
{
	int n;
	cout << "Nhap n = ";
	cin >> n;
	cout << "So nguyen to trong khoang (0," << n << ") la: ";
	in_so_nguyen_to(n);
	return 0;
}

