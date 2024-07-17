/* Nguyen Huu Hoang - msv:21103100320 - de chan
   Bai 2 */
#include<iostream>
#include<math.h>
using namespace std;

bool soChinhPhuong(int n)
{
	if (n<1)
		return false;
	int i = sqrt(n);
	if (i*i == n)
		return true;
	return false;
}
bool soPitago(int n)
{
	int count = 0;
	for(int i=1; i<n; i++)
	{
		for(int j=1; j<n; j++)
		{
			if((i*i) + (j*j) == n) 
				count++;
		}
	}
	if(count == 0)
		return false;
	else 
		return true;
}

int main(){
	unsigned int n;
	cout << "Nhap vao so nguyen duong n = ";
	cin >> n;
	if (soChinhPhuong(n) == true)
		cout << n << " la so chinh phuong !"<<endl;
	else
		cout << n << " khong la so chinh phuong !"<<endl;
	if (soPitago(n) == true)
		cout << n << " la so Pitago !"<<endl;
	else
		cout << n << " khong la so Pitago !"<<endl;
	return 0;
}

