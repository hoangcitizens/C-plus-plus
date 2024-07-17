#include<iostream>
#include<math.h>
using namespace std;

int giaiPhuongTrinhBac2(float a, float b, float c, float *x, float *x1, float *x2)
{
	float delta = b*b-4*a*c;
	if(delta < 0)
		return 0;
	else if (delta == 0)
	{
		*x = (-b)/(2*a);
		return 1;
	}
	else
	{
		*x1 = (-b+sqrt(delta)) / (2*a);
		*x2 = (-b-sqrt(delta)) / (2*a);
		return 2;
	}
}

int main()
{
	float a,b,c;
	cout << "Nhap a = ";
	cin >> a;
	while(a == 0)
	{
		cout << "Nhap lai a phai khac 0 ! Nhap a = ";
		cin >> a;
	}
	cout << "Nhap b = ";
	cin >> b;
	cout << "Nhap c = ";
	cin >> c;
	float x, x1, x2;
	int k = giaiPhuongTrinhBac2(a,b,c,&x,&x1,&x2);
	if(k == 0)
		cout<<"Phuong trinh vo nghiem !";
	else if (k == 1)
		cout << "Phuong trinh co nghiem kep x = "<<x<<endl;
	else
		cout << "Phuong trinh co 2 nghiem x1 = "<<x1<<" va x2 = "<<x2<<endl;
	return 0;
}

