#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;

class Benhnhan
{
private:
	char mhs[10]; // ma ho so
	char ht[20]; // ho ten
	int d, m, y; // ngay thang nam sinh
	char cd[20]; // chuan doan
public:
	Benhnhan()
	{
		strcpy_s(mhs, "");
		strcpy_s(ht, "");
		d = 0, m = 0, y = 0;
		strcpy_s(cd, "");
	}
	Benhnhan(char* mhs, char* ht, int d, int m, int y, char* cd)
	{
		strcpy_s(this->mhs, mhs);
		strcpy_s(this->ht, ht);
		this->d = d, this->m = m, this->y = y;
		strcpy_s(this->cd, cd);
	}
	~Benhnhan() {}
	virtual void nhap()
	{
		cout << "Nhap ma ho so: "; cin.getline(mhs, 10);
		cout << "Ho va ten benh nhan: "; cin.getline(ht, 20);
		cout << "Nhap ngay sinh cua benh nhan" << endl;
		cout << "Ngay: "; cin >> d;
		while (d < 1 || d > 31)
		{
			cout << "Vui long nhap 0 < ngay <= 31 !";
			cout << " => Ngay: "; cin >> d;
		}
		cout << "Thang: "; cin >> m;
		while (m < 1 || m > 12)
		{
			cout << "Vui long nhap 0 < thang <= 12 !";
			cout << " => Ngay: "; cin >> m;
		}
		cout << "Nam: "; cin >> y;
		while (y < 1900 || y > 2022)
		{
			cout << "Vui long nhap 1900 < nam <= 2022 !";
			cout << " => Nam: "; cin >> y;
		}
		cin.ignore();
		cout << "Chuan doan benh: "; cin.getline(cd, 20);
	}
	virtual void xuat()
	{
		cout << "\t";
		cout << left << setw(10) << mhs;
		cout << left << setw(20) << ht;
		cout << left << setw(2) << d << "/";
		cout << left << setw(2) << m << "/";
		cout << left << setw(9) << y;
		cout << left << setw(20) << cd;
	}
	int day()
	{
		return d;
	}
	int month()
	{
		return m;
	}
	int year()
	{
		return y;
	}
};
class Benhnhannoitru : public Benhnhan
{
private:
	int nnv; // ngay nhap vien
	int nrv; // ngay ra vien
	char tk[20]; // ten khoa
	int sg; //so giuong
public:
	Benhnhannoitru() : Benhnhan()
	{
		nnv = 0;
		nrv = 0;
		strcpy_s(tk, "");
		sg = 0;
	}
	Benhnhannoitru(char* mhs, char* ht, int d, int m, int y, char* cd, int nnv, int nrv, int sg) : Benhnhan(mhs, ht, d, m, y, cd)
	{
		this->nnv = nnv;
		this->nrv = nrv;
		strcpy_s(this->tk, tk);
		this->sg = sg;
	}
	~Benhnhannoitru() {}
	void nhap()
	{
		Benhnhan::nhap();
		cout << "Nhap vao ngay nhap vien: "; cin >> nnv;
		while (nnv < 1 || nnv > 31)
		{
			cout << "Vui long nhap 0 < ngay <= 31 !";
			cout << " => Ngay nhap vien: "; cin >> nnv;
		}
		cout << "Nhap ngay ra vien: "; cin >> nrv;
		while (nrv < 1 || nrv > 31)
		{
			cout << "Vui long nhap 0 < ngay <= 31 !";
			cout << " => Ngay ra vien: "; cin >> nrv;
		}
		cin.ignore();
		cout << "Nhap ten khoa: "; cin.getline(tk, 20);
		cout << "So giuong benh: "; cin >> sg;
	}
	void xuat()
	{
		Benhnhan::xuat();
		cout << left << setw(20) << nnv;
		cout << left << setw(20) << nrv;
		cout << left << setw(20) << tk;
		cout << left << setw(20) << sg;
		cout << endl;
	}
};
class Benhnhanngoaitru : public Benhnhan
{
protected:
	int ngc; // ngay chuyen
	char nc[20]; // noi chuyen
public:
	Benhnhanngoaitru() : Benhnhan()
	{
		ngc = 0;
		strcpy_s(nc, "");
	}
	Benhnhanngoaitru(char* mhs, char* ht, int d, int m, int y, char* cd, int ngc, char* nc) : Benhnhan(mhs, ht, d, m, y, cd)
	{
		this->ngc = ngc;
		strcpy_s(this->nc, nc);
	}
	~Benhnhanngoaitru() {};
	void nhap()
	{
		Benhnhan::nhap();
		cout << "Nhap ngay chuyen vien: "; cin >> ngc;
		cin.ignore();
		cout << "Nhap noi chuyen vien: "; cin.getline(nc, 20);
	}
	void xuat()
	{
		Benhnhan::xuat();
		cout << left << setw(20) << ngc;
		cout << left << setw(20) << nc;
		cout << endl;
	}
};

void tieude1()
{
	cout << "\t";
	cout << left << setw(10) << "Ma ho so";
	cout << left << setw(20) << "Ho ten benh nhan";
	cout << left << setw(15) << "Nam sinh";
	cout << left << setw(20) << "Chuan doan benh";
	cout << left << setw(20) << "Ngay nhap vien";
	cout << left << setw(20) << "Ngay ra vien";
	cout << left << setw(20) << "Ten khoa";
	cout << left << setw(20) << "So giuong";
	cout << endl;
}
void tieude2()
{
	cout << "\t";
	cout << left << setw(10) << "Ma ho so";
	cout << left << setw(20) << "Ho ten benh nhan";
	cout << left << setw(15) << "Nam sinh";
	cout << left << setw(20) << "Chuan doan benh";
	cout << left << setw(20) << "Ngay chuyen";
	cout << left << setw(20) << "Noi chuyen";
	cout << endl;
}
void input1(Benhnhannoitru a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin benh nhan thu " << i + 1 << endl;
		cin.ignore();
		a[i].nhap();
		cout << endl;
	}
}
void output1(Benhnhannoitru a[], int n)
{
	cout << "\t__________________________________________________DANH SACH THONG TIN BENH NHAN NOI TRU___________________________________________________" << endl;
	tieude1();
	for (int i = 0; i < n; i++)
	{
		a[i].xuat();
	}
	cout << endl;
}
void input2(Benhnhanngoaitru b[], int m)
{
	for (int i = 0; i < m; i++)
	{
		cin.ignore();
		cout << "(*) Nhap thong tin benh nhan thu " << i + 1 << endl;
		b[i].nhap();
		cout << endl;
	}
}
void output2(Benhnhanngoaitru b[], int m)
{
	cout << "\t______________________________DANH SACH THONG TIN BENH NHAN NGOAI TRU_____________________________" << endl;
	tieude2();
	for (int i = 0; i < m; i++)
	{
		b[i].xuat();
	}
	cout << endl;
}
void timNgaySinh(Benhnhannoitru a[], Benhnhanngoaitru b[], int n, int m)
{
	int xd, xm, xy;
	cout << "Nhap ngay/thang/nam can so sanh" << endl;
	cout << "Ngay: "; cin >> xd;
	while (xd < 1 || xd > 31)
	{
		cout << "Vui long nhap 0 < ngay <= 31 !";
		cout << " => Ngay: "; cin >> xd;
	}
	cout << "Thang: "; cin >> xm;
	while (xm < 1 || xm > 12)
	{
		cout << "Vui long nhap 0 < thang <= 12 !";
		cout << " => Ngay: "; cin >> xm;
	}
	cout << "Nam: "; cin >> xy;
	while (xy < 1900 || xy > 2022)
	{
		cout << "Vui long nhap 1900 < nam <= 2022 !";
		cout << " => Nam: "; cin >> xy;
	}
	int count1 = 0, count2 = 0;
	cout << "\t_________________________________DANH SACH BENH NHAN NOI TRU CO NGAY SINH LON HON NGAY " << xd << "/" << xm << "/" << xy << "_____________________________________" << endl;
	tieude1();
	for (int i = 0; i < n; i++)
	{
		if (a[i].year() > xy || a[i].year() == xy && a[i].month() > xm || a[i].year() == xy && a[i].month() == xm && a[i].day() > xd)
		{
			a[i].xuat();
			count1++;
		}
	}
	cout << "\t=> Co " << count1 << " benh nhan noi tru co ngay sinh lon hon ngay " << xd << "/" << xm << "/" << xy << endl << endl;
	cout << "\t______________DANH SACH BENH NHAN NGOAI TRU CO NGAY SINH LON HON NGAY " << xd << "/" << xm << "/" << xy << "________________" << endl;
	tieude2();
	for (int j = 0; j < m; j++)
	{
		if (b[j].year() > xy || b[j].year() == xy && b[j].month() > xm || b[j].year() == xy && b[j].month() == xm && b[j].day() > xd)
		{
			b[j].xuat();
			count2++;
		}
	}
	cout << "\t=> Co " << count2 << " benh nhan ngoai tru co ngay sinh lon hon ngay " << xd << "/" << xm << "/" << xy << endl << endl;
}

int main()
{
	Benhnhan bn;
	int n, m, luaChon;
	cout << "Nhap so benh nha noi tru: "; cin >> n;
	cout << "Nhap so benh nhan ngoai tru: "; cin >> m;
	Benhnhannoitru* bn1 = new Benhnhannoitru[n];
	Benhnhanngoaitru* bn2 = new Benhnhanngoaitru[m];
	do {
		cout << "\t________________________________MENU_____________________________________" << endl
			<< "\t|1. Nhap va in ra danh sach benh nhan noi tru                           |" << endl
			<< "\t|2. Nhap va in ra danh sach benh nhan ngoai tru                         |" << endl
			<< "\t|3. Tinh so ho so theo tung loai co ngay sinh lon hon nhap tu ban phim  |" << endl
			<< "\t|0. Thoat                                                               |" << endl
			<< "\t|_______________________________________________________________________|" << endl;
		cout << "<!> Nhap vao luong chon cua ban: "; cin >> luaChon; cout << endl;
		switch (luaChon)
		{
		case 0:
		{
			cout << "\tThoat. Ket thuc chuong trinh !" << endl; break;
		}
		case 1:
		{
			input1(bn1, n);
			output1(bn1, n);
			break;
		}
		case 2:
		{
			input2(bn2, n);
			output2(bn2, m);
			break;
		}
		case 3:
		{
			timNgaySinh(bn1, bn2, n, m);
			break;
		}
		default:
			cout << "\t=> Khong co lua chon nay ! Vui long lua chon lai !!!" << endl;
			break;
		}
	} while (luaChon != 0);
	return 0;
}