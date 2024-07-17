#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[50];
	cout << "Nhap vao mot xau chu thuong : ";
	cin.getline(s,50);
	cout << "Xau chuyen thanh chu hoa la : "<<strupr(s)<<endl;
	return 0;
}

