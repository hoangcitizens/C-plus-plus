#include<iostream>
using namespace std;

int main()
{
	int a[5];
	int *p = a;
	cout << "-----Nhap 5 so nguyen-----"<<endl;
	for (int i=0; i<5; i++)
	{
		cout << "Nhap phan tu thu "<<i+1<<": ";
		cin >> *(p+i);
	}
	cout << "Cac so vua nhap la: "<<endl;
	for (int i=0; i<5; i++)
		cout << a[i] << "\t";
	return 0;
}

