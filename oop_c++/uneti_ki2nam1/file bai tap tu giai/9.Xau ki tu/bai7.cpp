#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[50], kt;
	int n;
	bool k = false;
	cout << "Nhap xau ky tu : ";
	cin.getline(s,50);
	cout << "Nhap ki tu can tim : ";
	cin >> kt;
	n = strlen(s);
	for(int i=0; i<=n; i++)
	{
		if(s[i]==kt)
			k = true;
	}
	if(k == true)
		cout << "Ky ty "<<kt<<" co trong xau !"<<endl;
	else
		cout << "Ky ty "<<kt<<" khong co trong xau !"<<endl;

	return 0;
}

