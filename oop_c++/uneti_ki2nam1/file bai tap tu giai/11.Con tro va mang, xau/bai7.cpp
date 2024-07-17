#include<iostream>
#include<math.h>
using namespace std;

bool kiemTraSoNguyenTo(int *n)
{
	if (*n<2)
		return false;
	else
	{
		for (int i=2; i<=sqrt(*n); i++)
		{
			if (*n % i == 0)
				return false;
		}
		return true;
	}
}

int main()
{
	int n, count = 0;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	int a[n], *ptr[n];
	for(int i=0; i<n; i++)
	{
		cout << "Nhap a["<<i<<"] = ";
		cin >> *(a+i);
	}
	cout << "Mang vua nhap la: ";
    for (int i = 0; i < n; i++)
	{
        cout << *(a+i) << "   ";		
    }
    cout << endl;
    //mang ptr tro vao mang a
    for (int i=0; i < n; i++)
    	ptr[i] = &a[i];
    //dem so nguyen to trong mang
    cout << "Cac so nguyen to trong mang la: ";
	for (int i = 0; i < n; i++)
	{
        if (kiemTraSoNguyenTo(ptr[i]) == true)
        {	
			count++;  
			cout << *ptr[i] << "   ";
		}   
    }
    cout << "\nSo cac so nguyen to trong mang la: " << count <<endl;
	return 0;
}

