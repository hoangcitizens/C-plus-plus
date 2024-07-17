#include<iostream>
using namespace std;

long tich(unsigned int x)
{
	if (x==1)
		return 1;
	else
		return (2*x-1)*tich(x-1);
}

int main()
{
	unsigned int n;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Ket qua : "<<tich(n)<<endl;
	return 0;
}

