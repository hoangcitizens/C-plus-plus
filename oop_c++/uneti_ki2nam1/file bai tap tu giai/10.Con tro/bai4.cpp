#include<iostream>
using namespace std;

void change(float *x, float *y)
{
	float tg = *x;
	*x = *y;
	*y = tg;
}

int main()
{
	float a, b;
	cout << "Nhap so thu nhat : ";
	cin >> a;
	cout << "Nhap so thu hai : ";
	cin >> b;
	change(&a,&b);
	cout << "Gia tri sau hoan doi la : "<<endl;
	cout << "a = "<<a<<" va b = "<<b<<endl;
	return 0;
}

