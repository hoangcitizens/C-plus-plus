#include<iostream>
using namespace std;

void input(int a[], int n)
{
	for (int i=1; i<=n; i++)
	{
		cout << "a["<<i<<"] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for	(int i=1; i<=n; i++)
		cout << a[i] << "  ";
}

int main()
{
	int k, n, a[50];
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	do{
		cout << "Nhap k = ";
		cin >> k;
		if (k>n)
			cout << "Nhap lai k <= "<<n<<endl;
	} while (k>n);
	for (int i=k; i<n; i++)
		a[i] = a[i+1];
	n--;
	cout << "Mang sau khi xoa phan tu thu "<<k<<" la : ";
	output(a,n);
	cout << endl;
	return 0;
}

