#include<iostream>
using namespace std;

int main()
{
	float a, b, *aPrt, *bPrt;
	cout << "Nhap a = ";
	cin >> a;
	cout << "Nhap b = ";
	cin >>b;
	aPrt = &a;
	bPrt = &b;
	if (*aPrt == 0)
	{
		if (*bPrt == 0)
			cout << "Phuong trinh vo so nghiem !" << endl;
		else
			cout << "Phuong trinh vo nghiem !" << endl;
	}
	else
	{
		cout << "Phuong trinh co dang "<<*aPrt<<"x + "<<*bPrt<<" = 0";
		cout << "\nNghiem cua phuong trinh la x = "<<float(-(*bPrt)/(*aPrt))<<endl;
	}
	return 0;
}

