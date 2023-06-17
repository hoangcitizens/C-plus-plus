#include<iostream>

using namespace std;

class HCN
{
public:
	void nhap();
	void in();
	float tinhC();
	float tinhS();
private:
	float d, r;
};

void HCN::nhap()
{
	cout << "Nhap chieu dai HCN: "; cin >> d;
	cout << "Nhap chieu rong HCN: "; cin >> r;
}
void HCN::in()
{
	cout << "Chieu dai: " << d << endl;
	cout << "Chieu rong: " << r << endl;
}
float HCN::tinhC()
{
	return (d + r) * 2;
}
float HCN::tinhS()
{
	return d * r;
}

int main()
{
	HCN h;
	h.nhap();
	h.in();
	cout << "Chu vi hinh chu nhat la: " << h.tinhC() << endl;
	cout << "Dien tich HCN la: " << h.tinhS() << endl;
	
 	return 0;
}
