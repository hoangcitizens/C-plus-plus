#include<iostream>
#include<math.h>
using namespace std;

bool kiemTra(int n)
{	
	if (n<1)
		return false;
	for(int i=1; i<=n; i++)
	{
		if(i * i == n )
		return true;	
	}
	return false;
}
int main()
{
	unsigned int n;
	cout << "Nhap vao so nguyen duong n = ";
	cin >> n;
	cout << "Cac so chinh phuong trong pham vi tu 1 den "<<n<<" la : ";
	for(int i=0; i<=n; i++)
	{
		if (kiemTra(i)==true)
			cout << i << "  ";
	}
	cout << endl;
	return 0;
}

