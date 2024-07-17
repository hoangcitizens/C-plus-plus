#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	float thuc;
	float ao;	
} sophuc;
sophuc cong(sophuc p, sophuc q)
{
	sophuc kq;
	kq.thuc = p.thuc + q.thuc ;
	kq.ao = p.ao + q.ao ;
	return kq;
}
sophuc tru(sophuc p, sophuc q)
{
	sophuc kq;
	kq.thuc = p.thuc - q.thuc ;
	kq.ao = p.ao - q.ao ;
	return kq;
}
void In(sophuc a)
{
	cout << a.thuc << "i + " << a.ao;
	cout << " => A (" << a.thuc << "," << a.ao << ")" << endl ;
}

int main()
{
	sophuc x, y;
	cout << "*) Nhap so phuc x" << endl;
	cout << "Phan ao a = "; cin >> x.thuc;
	cout << "Phan thuc b = "; cin >> x.ao;
	cout << "=> So phuc x = " << x.thuc << " + " << x.ao << "i" << endl;
	cout << "*) Nhap so phuc y" << endl;
	cout << "Phan ao a = "; cin >> y.thuc;
	cout << "Phan thuc b = "; cin >> y.ao; 
	cout << "=> So phuc y = " << y.thuc << " + " << y.ao << "i" << endl;
	cout << "X + y = "; In(cong(x,y));
	cout << "x - y = "; In(tru(x,y));
	return 0;
}

