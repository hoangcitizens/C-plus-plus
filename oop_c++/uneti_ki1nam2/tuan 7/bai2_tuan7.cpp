#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
using namespace std;

class Sanpham
{
private:
	char msp[15];
	char tsp[20];
	int year;
public:
	Sanpham()
	{
		strcpy_s(msp, "");
		strcpy_s(tsp, "");
		year = 0;
	}
	Sanpham(char* m, char* t, int y)
	{
		strcpy_s(msp, m);
		strcpy_s(tsp, t);
		year = y;
	}
	~Sanpham() {}
	void Set()
	{
		cin.ignore();
		cout << "Nhap ma san pham: "; cin.getline(msp, 15);
		cout << "Nhap ten san pham: "; cin.getline(tsp, 20);
		cout << "Nhap nam san xuat: "; cin >> year;
		while (year < 1990 || year > 2022)
		{
			cout << "Nhap nam san xuat 1990 < nam <= 2022: ";
			cin >> year;
		}
	}
	void Display()
	{
		cout << "\t";
		cout << left << setw(15) << msp;
		cout << left << setw(20) << tsp;
		cout << left << setw(10) << year;
	}
};
class Tivi : public Sanpham
{
private:
	float d, r;
public:
	Tivi():Sanpham()
	{
		d = 0;
		r = 0;
	}
	Tivi(char* m, char* t, int y, float dai, float rong) : Sanpham(m, t, y)
	{
		d = dai;
		r = rong;
	}
	friend istream& operator >> (istream& is, Tivi& tv)
	{
		tv.Set();
		cout << "Nhap chieu dai Tivi: "; cin >> tv.d;
		cout << "Nhap chieu rong Tivi: "; cin >> tv.r;
		cout << endl;
		return is;
	}
	float dientich()
	{
		return d * r;
	}
	friend ostream& operator << (ostream& os, Tivi& tv)
	{
		tv.Display();
		cout << left << setw(12) << tv.d;
		cout << left << setw(12) << tv.r;
		cout << left << setw(10) << tv.dientich();
		cout << endl;
		return os;
	}
};

void tieude()
{
	cout << "\t";
	cout << left << setw(15) << "Ma san pham";
	cout << left << setw(20) << "Ten san pham";
	cout << left << setw(10) << "Nam sx";
	cout << left << setw(12) << "Chieu dai";
	cout << left << setw(12) << "Chieu rong";
	cout << left << setw(10) << "Dien tich";
	cout << endl;
}
void input(Tivi a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin san pham thu " << i + 1 << endl; 
		cin >> a[i];
	}
}
void output(Tivi a[], int n)
{
	tieude();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
void sapxep(Tivi a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].dientich() > a[j].dientich())
				swap(a[i], a[j]);
		}
	}
	cout << "\t________________THONG TIN SAN PHAM TIVI TANG DAN THEO DIEN TICH________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Nhap so luong san pham: ";
	cin >> n;
	Tivi* t = new Tivi[n];
	input(t, n);
	cout << "\t_______________________DANH SACH THONG TIN SAN PHAM TIVI_______________________" << endl;
	output(t, n);
	sapxep(t, n);
	return 0;
}