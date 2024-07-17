#include<iostream>
using namespace std;

int kiemTra(int n)
{
	int dao=0;
	while (n>0)
	{
		dao = dao * 10 + n % 10;
		n = n / 10;
	}
	return dao;
}

int main()
{
	unsigned int n;
	cout << "Nhap vao so nguyen duong n = ";
	cin >> n;
	if (kiemTra(n)==n)
		cout << " "<<n<<" la so doi xung";
	else
		cout << " " <<n<<" khong la so doi xung";
	return 0;
}

