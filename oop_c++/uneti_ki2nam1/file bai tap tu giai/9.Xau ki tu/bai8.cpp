#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[50];
	int i = 0;
	cout << "Nhap xau ho ten: ";
	cin.getline(s,50);
	cout << "Ho tach duoc la: ";
	while (s[i] != ' ')
	{
		cout << s[i];
		i++;
	}
	cout << endl;
	return 0;
}

