#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[50], ten[20];
	int n, i, j = 0;
	cout<<"Nhap xau ho ten: ";
	cin.getline(s,50);
	n = strlen(s); 
	i = n-1;
	while (s[i] != ' ')
	{ 
		ten[j] = s[i];
		i--;
		j++;
	}
	for(int k=j-1; k>=0; k--)
		cout<<"Ten tach ra la : " << ten[k] <<endl;
	return 0;
}

