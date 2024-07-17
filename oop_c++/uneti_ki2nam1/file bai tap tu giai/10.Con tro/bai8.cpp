#include<iostream>
using namespace std;

int main()
{
	int p;
	int *pPtr;
	cout << "Nhap so phan tu : ";
	cin >> p;
	pPtr = new int; // cap phat bo nho
	if (pPtr != NULL)
	{
		for (int i=0; i<p; i++)
			*(pPtr+i) = i;
		for (int i=p; i>0; i--)
			cout << *(pPtr+(i-1)) << "\t";
		delete pPtr;
		return 0;
	}
	else
	{
		cout << "\nKhong du bo nho de cap nhat"<<endl;
		return 1;
	}
}

