#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char *s1, *s2;
	s1 = new char();
	s2 = new char();
	cout << "Nhap xau thu nhat : ";
	cin.getline(s1,50);
	cout << "Nhap xau thu hai : ";
	cin.getline(s2,50);
	if (strcmp(s1,s2) == 0)
		cout << "Hai xau giong nhau" << endl;
	else
	{
		if (strcmp(s1,s2) == 1)
			cout << "Xau s1 lon hon xau s2" << endl;
		else
			cout << "Xau s1 nho hon xau s2" << endl;
	}
	return 0;
}

