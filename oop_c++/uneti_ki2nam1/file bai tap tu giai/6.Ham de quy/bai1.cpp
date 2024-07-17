#include<iostream>
using namespace std;

long tinh(unsigned int x)
{
	if (x==1)
		return 1;
	else
		return x*x + tinh(x-1);
}

int main()
{	
	unsigned int n;
	cout << "Nhap n = ";
	cin >> n;
	cout << "Tong la : "<<tinh(n)<<endl;
	return 0;
}

