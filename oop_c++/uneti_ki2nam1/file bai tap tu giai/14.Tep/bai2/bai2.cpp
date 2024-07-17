#include<iostream>
#include<fstream>
using namespace std;

void doctep(char tentep[], int &m, int &n)
{
	fstream f1(tentep,ios::in);
	if (!f1)
	{
		cout << "Khong the mo duoc tep" << f1 << endl;
		exit(1);
	}
	f1 >> m >> n;
	f1.close();
}

int UCLN(int m, int n)
{
	while (m != n)
		if (m > n)
			m = m - n;
		else
			n = n - m;
	return m;
}

void ghitep(char tentep[], int &m, int &n)
{
	fstream f2(tentep,ios::out);
	if(!f2)
	{
		cout << "Khong the tao duoc tep" << f2 << endl;
		exit(1);
	}
	f2 << "\n" << "UCLN ("<<m<<","<<n<<") = " << UCLN(m,n);  
}

int main()
{
	char f1[30], f2[30];
	int  n, m;
	cout << "\nNhap ten tep doc du lieu: ";	cin.getline(f1,30);
	doctep(f1,m,n);
	cout << "\nNhap ten tep ghi du lieu: ";	cin.getline(f2,30);
	ghitep(f2,m,n);
	return 0;
}

