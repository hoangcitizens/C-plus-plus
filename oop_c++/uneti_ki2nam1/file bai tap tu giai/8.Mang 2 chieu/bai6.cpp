#include<iostream>
#define max 50
using namespace std;

void input(int a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << "Nhap a["<<i<<"]["<<j<<"] = ";
			cin >> a[i][j];
		}
	}
}
void output(int a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}
}
bool kiemTra(int a[max][max], int n, int m)
{
	int count = 0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++){
			if (a[i][j] % 2 != 0)
				count++;
		}
	}
	if(count == n*m)
		return true;
	return false;
}

int main()
{
	int n, m, a[max][max];
	cout << "Nhap so hang : ";
	cin >> m;
	cout << "Nhap so cot : ";
	cin >> n;
	input(a,n,m);
	cout << "Mang da nhap la: "<<endl;
	output(a,n,m);
	if(kiemTra(a,n,m) == true)
		cout << "Mang co toan so le !"<<endl;
	else
		cout << "Mang khong co toan so le !"<<endl;
	return 0;
}

