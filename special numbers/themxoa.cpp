#include<iostream>
using namespace std;

void import(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
void display(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}
	cout << endl;
}
// them phan tu vao dau mang
void insertFirst(int a[], int& n, int x)
{
	n++;
	for (int i = n - 1; i >= 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
}
// them phan tu vao cuoi mang
void insertLast(int a[], int& n, int x)
{
	a[n] = x;
	n++;
}
// them phan tu vao vi tri thu k
void insertPosK(int a[], int& n, int x, int k)
{
	n++;
	for (int i = n - 1; i > k - 1; i--)
	{
		a[i] = a[i - 1];
	}
	a[k - 1] = x;
}
// xoa phan tu dau mang
void deleteFirst(int a[], int& n)
{
	for (int i = 1; i < n; i++)
	{
		cout << a[i] << ", ";
	}
}
// xoa phan tu cuoi mang
void deleteLast(int a[], int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		cout << a[i] << ", ";
	}
}
// xoa phan tu vi tri thu k
void deletePosk(int a[], int& n, int k)
{
	for (int i = k - 1; i < n - 1; i++)
	{
		a[i] = a[i + 1]; // <=> a[i -1] = a[i]
	}
	n--;
}
// xoa phan tu theo yeu cau
void deleteX(int a[], int& n, int x) 
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1]; // <=> a[j - 1] = a[j]
			}
			n--;
		}
	}
}
int main()
{
	int a[100], n;  cout << "Nhap so luong phan tu cua mang: "; cin >> n;
	import(a, n); cout << "=> Cac phan tu trong mang: "; display(a, n);
	//insertFirst(a, n, 3); cout << "(+) Mang sau khi them phan tu gia tri 3 vao dau mang: "; display(a, n);
	//insertLast(a, n, 4); cout << "(+) Mang sau khi them phan tu gia tri 4 vao cuoi mang: "; display(a, n);
	//insertPosK(a, n, 5, 3); cout << "(+) Mang sau khi them phan tu gia tri 5 vao vi tri thu 3 trong mang: "; display(a, n);
	//cout << "(-) Mang sau khi xoa phan tu dau: "; deleteFirst(a, n);
	//cout << "(-) Mang sau khi xoa phan tu cuoi: "; deleteLast(a, n);
	//deletePosk(a, n, 2); cout << "(-) Mang sau khi xoa phan tu vi tri thu 2 trong mang: "; display(a, n);
	//deleteX(a, n, 3); cout << "(-) Mang sau khi xoa phan tu gia tri 3 trong mang: "; display(a, n);
	return 0;
}