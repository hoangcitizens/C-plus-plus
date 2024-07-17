#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[50];
	int n, d=1;
	cout << "Nhap xau : ";
	cin.getline(s,50);
	n = strlen(s);
	cout << "Xau da nhap la: "<<s;
	for (int i=0; i<n; i++)
	{
		if (s[i] == ' ')
			d++;
    }
	cout << "\nSo tu trong xau la : "<<d<<endl;
	return 0;
}

