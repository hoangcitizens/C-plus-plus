#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[50], t[50];
	cout << "Nhap xau s : ";
	cin.getline(s,50);
	cout << "Nhap xau t : ";
	cin.getline(t,50);
	if (strstr(s,t) == NULL)
		cout<<"Khong ton tai xau t trong xau s !"<<endl;
	else
		cout<<"Ton tai xau t trong xau s !"<<endl;
	return 0;
}

