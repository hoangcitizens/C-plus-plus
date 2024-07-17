#include<iostream>
using namespace std;

void input(int a[], int &n)
{
	cout << "Nhap n = ";
	cin >> n;
	for (int i=0; i<n; i++)
	{
		a[i] = i+1;
	}
}
void tron(int a[], int b[], int c[], int na, int nb)
{
	int i = 0, j = 0, k = 0;
	while(i < na || j < nb)
	{
		if (i < na && j < nb)
		{
			if (a[i] < b[j])
			{
				c[k] = a[i];
				k++;
				i++;
			}
			else
			{
				c[k] = b[j];
				k++;
				j++;
			}
		}
		else
		{
			if (i < na && j >= nb)
			{
				c[k] = a[i];
				k++;
				i++;
			}
			else
				if (j < nb && j >= na)
				{
					c[k] = b[j];
					j++;
					k++;	
				} 
		}
	}
}
void output(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << "  ";
}


int main()
{
	int na, nb, nc, a[50], b[50], c[100];
	cout << "\nNhap so phan tu cua mang 1 : ";
	input(a,na);
	cout << "Cac phan tu cua mang 1: ";
	output(a,na);
	cout << "\nNhap so phan tu cua mang 2 : ";
	input(a,nb);
	cout << "Cac phan tu cua mang 2: ";
	output(a,nb);
	tron(a,b,c,na,nb);
	nc = na + nb;
	cout << "\nMang sau khi tron la : ";
	output(c,nc);
	return 0;
}

