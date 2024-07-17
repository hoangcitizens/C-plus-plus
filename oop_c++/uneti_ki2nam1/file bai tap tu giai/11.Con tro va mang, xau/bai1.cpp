#include<iostream>
#define MAX 3
using namespace std;

int main()
{
	int a[MAX] = {10,100,200};
	int *contro[MAX];
	for (int i=0; i<MAX; i++)
		contro[i] = &a[i];
	for (int i=0; i<MAX; i++)
	{
		cout << "Gia tri cua a["<<i<<"] = ";
		cout << *contro[i] << endl;
	}
	return 0;
}

