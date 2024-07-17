#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s1[50], s2[50];
	cout << "Nhap xau 1 : ";
	cin.getline(s1,50);
	cout << "Nhap xau 2 : ";
	cin.getline(s2,50);
	if (strcmp(s1,s2) == 0)
		cout << "Hai xau giong nhau !"<<endl;
	else
		if (strcmp(s1,s2) > 0)
			cout << "Xau 1 lon hon xau 2 !"<<endl;
		else
			cout << "Xau 2 lon hon xau 1 !"<<endl;
	return 0;
}

