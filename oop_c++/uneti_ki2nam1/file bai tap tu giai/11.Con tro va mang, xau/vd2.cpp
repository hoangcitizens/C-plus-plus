#include<iostream>
#define hang 3
#define cot 3
using namespace std;

int main()
{
	int mt[hang][cot] = {{7,8,9},{10,13,15},{2,7,8}};
	cout << "Ma tran ban dau la: "<<endl;
	for (int i=0; i<hang; i++)
	{
		for (int j=0; j<cot; j++)
			cout << mt[i][j] << "\t";
		cout << endl;
	}
	cout << "Ma tran sau khi tang la: "<<endl;
	for (int i=0; i<hang; i++)
	{
		for (int j=0; j<cot; j++)
		{
			*(*(mt+i)+j) = *(*(mt+i)+j) + 10;
			cout << *(*(mt+i)+j) << "\t";
		}
		cout << endl;
	}
	return 0;
}

