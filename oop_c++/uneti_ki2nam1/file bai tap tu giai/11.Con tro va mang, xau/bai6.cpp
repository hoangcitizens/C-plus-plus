#include<iostream>
using namespace std;

int main()
{
	int n, *p, count = 0;
	p = &n;
	cout << "Nhap so luong phan tu: ";
	cin >> *p;
	int a[*p];
	for(int i=0; i < *p; i++)
	{
		cout << "Nhap a["<<i<<"] = ";
		cin >> *(a+i);
	}
	cout << "Cac so vua nhap la: ";
    for (int i = 0; i < *p; i++)	
        cout << *(a+i) << "   ";	
	int *soChan = a;
	cout << "\nCac so chan trong mang la: ";
	for (int i = 0; i < *p; i++)
	{
        if (*(soChan + i) % 2 == 0)
        {	
			count++;
			cout << *(soChan + i) << "   ";
        }
    }
    cout << "\nSo so chan trong mang la: " << count << endl;
	return 0;
}

