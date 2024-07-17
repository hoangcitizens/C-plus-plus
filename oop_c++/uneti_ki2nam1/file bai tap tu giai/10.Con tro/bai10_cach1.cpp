#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	float a, b, c, *aPrt, *bPrt, *cPrt;
	aPrt = &a;
	bPrt = &b;
	cPrt = &c;
	cout << "Nhap a = "; cin>>a;
	while(a == 0)
	{
		cout << "Nhap lai a phai khac 0 ! Nhap a = ";
		cin >> a;
	}
	cout << "Nhap b = "; cin>>b;
	cout << "Nhap c = "; cin>>c;
	cout << "Phuong trinh co dang "<<*aPrt<<"x^2 + "<<*bPrt<<"x + "<<*cPrt<<" = 0"<<endl;
	float delta = (*bPrt)*(*bPrt) - 4*(*aPrt)*(*cPrt);
	if(delta < 0)
		cout << "Phuong trinh vo nghiem !" << endl;
	else if (delta == 0)
	{
		float x = (-(*bPrt) / (2*(*aPrt)));
		cout << "Phuong trinh co nghiem kep x = "<<x<<endl;
	}
	else
	{
		float x1 = (-(*bPrt) + sqrt(delta)) / (2*(*aPrt));
		float x2 = (-(*bPrt) - sqrt(delta)) / (2*(*aPrt));
		cout<<"Phuon trinh co 2 nghiem x1 = "<<x1<<" va x2 = "<<x2<<endl;
	}
	return 0;
}


