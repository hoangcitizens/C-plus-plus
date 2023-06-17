#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class Phanso
{
public:
	Phanso(int, int);
	~Phanso();
	Phanso rutGon(Phanso);
	friend istream& operator >> (istream&, Phanso&);
	friend ostream& operator << (ostream&, Phanso&);
	bool operator < (Phanso&);
	bool operator > (Phanso&);
private:
	int t, m;
};

Phanso::Phanso(int t = 0, int m = 1)
{
	this->t = t;
	this->m = m;
}
Phanso::~Phanso() {}
int UCLN(int a, int b)
{
	if (a < 0)
		a *= (-1);
	if (b < 0)
		b *= (-1);
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
Phanso Phanso::rutGon(Phanso p)
{
	if (p.t != 0)
	{
		int u = UCLN(p.t, p.m);
		p.t /= u;
		p.m /= u;
	}
	return p;
}
istream& operator >> (istream& is, Phanso& p)
{
	cout << "Nhap tu so: "; is >> p.t;
	cout << "Nhap mau so: "; is >> p.m;
	while (p.m == 0)
	{
		cout << "Nhap lai mau khac 0: "; is >> p.m;
	}
	return is;
}
ostream& operator << (ostream& os, Phanso& p)
{
	if (p.m < 0)
	{
		p.t *= (-1);
		p.m *= (-1);
		os << p.t << "/" << p.m;
	}
	else if (p.t % p.m == 0)
		os << (p.t / p.m);
	else
		os << p.t << "/" << p.m;
	return os;
}
bool Phanso::operator < (Phanso &p)
{
	return ((this->t * p.m) < (p.t * this->m));
}

bool Phanso::operator > (Phanso &p)
{
	return ((this->t * p.m) > (p.t * this->m));
}

template <class T>
void import(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Phan so thu " << i + 1 << endl;
		cin >> a[i];
		cout << endl;
	}
}
template <class T>
void display(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ; ";
	}
	cout << endl;
}
template <class T>
T findMin(T a[], int n)
{
	T min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

template <class T>
void SelectionSort(T a[], int n)
{
	int min; // luu chi so phan tu nho nhat
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min]) // sap xep tang dan
				min = j;
		}
		if (min != i)
			swap(a[i], a[min]);
	}
}
template <class T>
void BubbleSort(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1]) // sap xep tang dan
				swap(a[j], a[j + 1]);
		}
	}
}
template <class T>
void InsertionSort(T a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i], pos = i - 1; // x luu phan tu a[i]
		while ((pos >= 0) && (a[pos] > x)) // sap xep tang dan
		{
			a[pos + 1] = a[pos]; // doi cho cac phan tu dung sau x
			pos--;
		}
		a[pos + 1] = x; // chen x vao day moi
	}
}

int main()
{
	int n; cout << "Nhap so luong phan so: "; cin >> n;
	Phanso *p = new Phanso[n];
	import(p, n);
	cout << "Cac phan so vua nhap la: "; display(p, n);
	Phanso pmin = findMin(p, n);
	cout << "Phan so nho nhat la: " << pmin << endl;
	//SelectionSort(p, n); cout << "\nMang sap xep tang dan theo Selection Sort: "; display(p, n);
	//BubbleSort(p, n); cout << "\nMang sap xep tang dan theo Bubble Sort: "; display(p, n);
	//InsertionSort(p, n); cout << "\nMang sap xep tang dan theo Insert Sort: "; display(p, n);
	return 0;
}