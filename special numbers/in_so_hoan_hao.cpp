#include<iostream>
#include<math.h>
using namespace std;
/*So hoan hao la so nguyen duong co tong cac uoc nguyen duong cua no bang chinh so do*/
bool kiem_tra_so_hoan_hao(int n)
{
	int S = 0; // S tong cac uoc cua so n
	for (int i=1; i <= n/2; i++)
	{
		if (n % i == 0) // Neu so n chia het cho i thi so i do la uoc cua n
			S += i;     // cong don cac uoc
	}
	if (S == n) // lap toi khi tong cac uoc bang chinh so n
		return true;
	return false;
}
void in_so_hoan_hao(int n)
{
	for (int i=1; i < n; i++)
	{
		if (kiem_tra_so_hoan_hao(i))
			cout << i << "   ";
	}
}
int main()
{
	int n;
	cout << "Nhap n = ";
	cin >> n;
	cout << "So hoan hao trong khoang (0," << n << ") la: ";
	in_so_hoan_hao(n);
	return 0;
}

