#include<iostream>
#include<math.h>
using namespace std;
/*So ban be la so co tong cac uoc cua so nay (khong ke chinh no) bang chinh so
kia va nguoc lai. VD: 220 va 284*/

int so_ban_be(int n)
{
	int S = 0;
	/* Xet i den can n vi luon ton tai mot uoc khac 1 trong 
	khoang (1;sqrt(n)] thi se luon co 1 uoc khac n trong khoang [sqrt(n);n) */
	for (int i=2; i <= int(sqrt(n)); i++)
	{
		if (n % i == 0)
		{
		//	if (i * i == n)	
		//		S += 1;
		//	else
				S += (i + int(n/i));
		}
	}
	return S + 1;
}
void in_so_ban_be(int a, int b)
{
	if (a == so_ban_be(b) && b == so_ban_be(a))
		cout << "Hai so " << a << " va " << b << " la so ban be !" << endl;
	else
		cout << "Hai so " << a << " va " << b << " khong la so ban be !" << endl;
} 
int main()
{
	int n, m;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Nhap m = ";
	cin >> m;
	in_so_ban_be(n,m);
	return 0;
}

