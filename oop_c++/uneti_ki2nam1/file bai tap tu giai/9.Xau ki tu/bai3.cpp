#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int n, count=0;
	char s[50];
	cout << "Nhap xau : ";
	cin.getline(s,50);
	n = strlen(s);
	for (int i=0; i<=n; i++)
	{
		if(toupper(s[i]) == 'A' || toupper(s[i]) == 'B')
			count++;
	}
	cout << "So luong ky tu a va b trong xau la : "<<count<<endl;
	return 0;
}

