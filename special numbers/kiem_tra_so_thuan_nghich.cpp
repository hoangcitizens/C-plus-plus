#include<iostream>
#include<math.h>
using namespace std;

/*So thuan nghich la so doc tu trai sang phai hay tu phai sang trai la mot
 so giong nhau. VD: 13455431*/
bool so_thuan_nghich(int n)
{
	int tmp = n; // tmp: bien tam thoi
	int nDao = 0; // dat gia tri dao cua so n la 0
	while (tmp > 0)
	{ 
		nDao = nDao * 10 + tmp % 10; // chia lay phan du cua so n (chu so cuoi mot so)
		tmp /= 10; // bo chu so cuoi cung di
	}
	if (nDao == n)
		return true;
	return false;
}

int main()
{
	int n;
	cout << "Nhap so n: ";
	cin >> n;
	if (so_thuan_nghich(n))
		cout << n << " la so thuan nghich!" << endl;
	else
		cout << n << " khong phai so thuan nghich!" << endl;
	return 0;
}

