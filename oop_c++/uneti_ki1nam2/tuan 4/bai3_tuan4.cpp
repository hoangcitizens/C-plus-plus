#include<iostream>
using namespace std;
#define max 20

int n;
class MaTran
{
private:
	int mt[max][max];
public:
	MaTran();
	void inputmt();
	void outputmt();
	friend MaTran tich(MaTran a);
};

MaTran::MaTran()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mt[i][j] = 0;
		}
	}
}
void MaTran::inputmt()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << "Nhap a[" << i << "][" << j << "] = ";
			cin >> mt[i][j];
		}
	}
}
void MaTran::outputmt()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << mt[i][j] << "  ";
		}
		cout << endl;
	}
}
MaTran tich(MaTran a)
{
	MaTran c;
	float vt[max];
	cout << "(*) Nhap vector" << endl;
	for (int j = 1; j <= n; j++)
	{
		cout << "Nhap toa do vector chieu thu " << j << ": ";
		cin >> vt[j];
	}
	cout << "=> Vector " << n << " chieu la: (";
	for (int j = 1; j <= n; j++)
	{
		cout << vt[j] << ", ";
	}
	cout << ")" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			c.mt[i][j] += a.mt[i][j] * vt[j];
		}
	}
	return c;
}
int main()
{
	cout << "Nhap cap ma tran va chieu vector: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Nhap chieu vector la so duong: ";
		cin >> n;
	}
	MaTran a, c;
	cout << "(*) Nhap ma tran" << endl;
	a.inputmt(); 
	cout << "=> Ma tran vuong cap " << n << " la: " << endl;
	a.outputmt();
	c = tich(a);
	cout << "\n => Tich cua ma tran voi vector la: " << endl;
	c.outputmt();
	return 0;
}