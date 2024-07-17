#include<iostream>
using namespace std;

int main()
{
	int b, n, *p;		//b chua so nguoi, n vi tri nguoi can tim, p con tro tro so nguoi
	p = &b;
	string a[50];	//chua xau ten
	string *q = a;	//q con tro tro xau ten
	cout << "Nhap so nguoi can thuc hien: ";
	cin >> *p;
	for(int i=0; i < *p; i++)
	{
		cout << "Ten nguoi thu " << i+1 << " la: ";
		cin >> *(q+i);
	}
	cout << "Nhap vi tri can tim: ";
	cin >> n;
	cout << "Ten nguoi o vi tri " << n << " la: ";
	for(int i=0; i < *p ; i++)
	{
		if(n == i+1)
			cout << *(q+i);
	}
	cout << endl;	
	return 0;
}

