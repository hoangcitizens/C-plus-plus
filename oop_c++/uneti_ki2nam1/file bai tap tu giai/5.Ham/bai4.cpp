#include<iostream>
#include<math.h>
using namespace std;

void kiemTra(int , int, int);

int main()
{
	unsigned int a, b, c;
	cout << "Nhap vao canh a = ";
	cin >> a;
	cout << "Nhap vao canh b = ";
	cin >> b;
	cout << "Nhap vao canh c = ";
	cin >> c;
	kiemTra(a,b,c);
}
void kiemTra(int a, int b, int c)
{
	if (abs(b-c)<a && a<(b+c))
	{
		cout << "Ba so "<<a<<", "<<b<<", "<<c<<" tao thanh ba canh cua tam giac !" << endl;
		if (a==b && c==a)
			cout << "Ba canh tao thanh tam giac deu !" << endl;
		else 
			if (a==b || b==c || c==a)
				cout << "Ba canh tao thanh tam giac can !" << endl;
		else
			if (a*a+b*b==c*c || b*b+c*c==a*a || a*a+c*c==b*b)
				cout << "Ba canh tao thanh tam giac vuong !" << endl;
		else
			cout << "Ba canh tao thanh tam giac thuong !" << endl;
	}
	else
		cout << "Ba so "<<a<<", "<<b<<", "<<c<<" khong tao thanh ba canh cua tam giac !";
}


