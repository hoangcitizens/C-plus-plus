#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[50];
	int n;
	cout << "Nhap xau : ";
	cin.getline(s,50);
	n = strlen(s);
	cout << "\tXau da nhap la : "<<s<<endl;
	cout << "\tXau dao nguoc la : ";
	for(int i=n-1; i>=0; i--)
		cout << s[i];
	cout << endl;
	return 0;
}

