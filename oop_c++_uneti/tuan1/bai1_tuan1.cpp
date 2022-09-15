#include<iostream>
using namespace std;

typedef struct
{
	float thuc;
	float ao;
} so_phuc;

so_phuc tinh_tong(so_phuc m, so_phuc n)
{
	so_phuc kq;
	kq.thuc = m.thuc + n.thuc;
	kq.ao = m.ao + n.ao;
	return kq;
}
so_phuc tinh_hieu(so_phuc m, so_phuc n)
{
	so_phuc kq;
	kq.thuc = m.thuc - n.thuc;
	kq.ao = m.ao - n.ao;
	return kq;
}
void in_kq(so_phuc k)
{
	cout << k.thuc << " + " << k.ao << "i" << endl;
}

int main()
{
	so_phuc x, y;
	cout << "(*) Nhap so phuc x: " << endl;
	cout << "Nhap phan thuc a: "; cin >> x.thuc;
	cout << "Nhap phan ao b: "; cin >> x.ao;
	cout << "=> So phuc x la : " << x.thuc << " + " << x.ao << "i" << endl;
	cout << "(*) Nhap so phuc y: " << endl;
	cout << "Nhap phan thuc a: "; cin >> y.thuc;
	cout << "Nhap phan ao b: "; cin >> y.ao;
	cout << "=> So phuc y la : " << y.thuc << " + " << y.ao << "i" << endl;
	cout << "Tong 2 so phuc x + y = "; in_kq(tinh_tong(x,y));
	cout << "Hieu 2 so phuc x - y = "; in_kq(tinh_hieu(x,y));
	return 0;
}

