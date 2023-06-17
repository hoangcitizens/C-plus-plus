#include<iostream>
#include<math.h>
using namespace std;

// tim phan tu lon nhat tren mang
template <class T>
void findMax(T a[], int n)
{
	T max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	cout << "\n(*) Phan tu lon nhat trong mang la : " << max << endl;
}
// tinh tong cac phan tu
template <class T>
void sum(T a[], int n)
{
	T S = 0;
	for (int i = 0; i < n; i++)
	{
		S = S + a[i];
	}
	cout << "(*) Tong cua " << n << " so la: " << S << endl;
}
// doi cho 2 phan tu
template <class T>
void swap(T *a, T *b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}
// sap xep mang theo chieu tang dan
template <class T>
void arrange(T a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
// tim phan tu gia tri x
template <class T>
void find(T a[], int n, T x)
{
	int c = 0, k = 0;
	for (int i = 0; i < n; i++)
	{
		if (x == a[i])
		{
			c++;
			k = i + 1;
		}
	}
	if (c == 0)
		cout << "\t=> Khong tim thay so vua nhap !!!" << endl;
	else
		cout << "\t=> Tim thay so vua nhap la so thu " << k + 1<< " !!!" << endl;
}
// them phan tu vi tri thu k
template <class T>
void insertPosK(T a[], int& n, T x)
{
	int k; cout << "\t=> Nhap vi tri phan tu muon them: "; cin >> k;
	n++;
	for (int i = n - 1; i > k - 1; i--)
	{
		a[i] = a[i - 1];
	}
	a[k - 1] = x;
}
// xoa phan tu vi tri thu k
template <class T>
void deletePosk(T a[], int& n)
{
	int k; cout << "(*) Nhap vi tri phan tu muon xoa: "; cin >> k;
	for (int i = k - 1; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

class PhanSo
{
public:
	PhanSo(int, int);
	~PhanSo();
	PhanSo rutGon(PhanSo);
	friend istream& operator >> (istream& is, PhanSo& p);
	friend ostream& operator << (ostream& os, PhanSo& p);
	PhanSo operator +(PhanSo);
	PhanSo operator -(PhanSo);
	PhanSo operator *(PhanSo);
	PhanSo operator /(PhanSo);
	bool operator < (PhanSo&);
	friend bool operator >(PhanSo&, PhanSo&);
	friend bool operator ==(PhanSo&, PhanSo&);
private:
	int t, m;
};

PhanSo::PhanSo(int t = 0, int m = 1)
{
	this->t = t;
	this->m = m;
}
PhanSo::~PhanSo() {}
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
PhanSo PhanSo::rutGon(PhanSo p)
{
	if (p.t != 0)
	{
		int u = UCLN(p.t, p.m); 
		p.t /= u;             
		p.m /= u;            
	}
	return p;
}
istream& operator >> (istream& is, PhanSo& p)
{
	cout << "Nhap tu so: "; is >> p.t;
	cout << "Nhap mau so: "; is >> p.m;
	while (p.m == 0)
	{
		cout << "Vui long nhap mau khac 0: ";
		is >> p.m;
	}
	return is;
}
ostream& operator << (ostream& os, PhanSo& p)
{
	if (p.m < 0)
	{
		p.t *= -1; 
		p.m *= -1; 
		os << p.t << "/" << p.m;
	}
	else if (p.t % p.m == 0) 
		os << p.t / p.m;
	else
		os << p.t << "/" << p.m;
	return os;
}
PhanSo PhanSo::operator+(PhanSo b)
{
	PhanSo a;
	a.t = this->t * b.m + b.t * this->m;
	a.m = this->m * b.m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::operator-(PhanSo b)
{
	PhanSo a;
	a.t = this->t * b.m - b.t * this->m;
	a.m = this->m * b.m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::operator*(PhanSo b)
{
	PhanSo a;
	a.t = this->t * b.t;
	a.m = this->m * b.m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::operator/(PhanSo b)
{
	PhanSo a;
	a.t = this->t * b.m;
	a.m = this->m * b.t;
	a = rutGon(a);
	return a;
}
bool PhanSo::operator < (PhanSo &p)
{
	return ((this->t * 1.0 / this->m) < (p.t * 1.0 / p.m));
}
bool operator > (PhanSo &a, PhanSo &b)
{
	return (a.t * 1.0 / a.m > b.t * 1.0 / b.m);
}
bool operator ==(PhanSo &a, PhanSo &b)
{
	return (a.t * 1.0 / a.m == b.t * 1.0 / b.m);
}
void input(PhanSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap phan so thu " << i + 1 << endl;
		cin >> a[i];
		cout << endl;
	}
}
void output(PhanSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}

int main()
{
	int n; cout << "Nhap so luong phan so: "; cin >> n;
	PhanSo* p = new PhanSo[n];
	input(p, n);
	cout << "=> Cac phan so vua nhap la: ";
	output(p, n);
	findMax(p, n);
	sum(p, n);
	arrange(p, n); cout << "(*) Mang sap xep theo chieu tang dan: "; output(p, n);
	PhanSo x1; cout << "\n(*) Nhap phan so x1" << endl; cin >> x1; find(p, n, x1);
	deletePosk(p, n); cout << "\t=> Mang sau khi xoa: "; output(p, n);
	PhanSo x2; cout << "\n(*) Nhap phan so x2" << endl; cin >> x2; insertPosK(p, n, x2);
	cout << "\t=> Mang sau khi them: "; output(p, n);
	return 0;
}