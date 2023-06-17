#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;

class Sach
{
protected:
	char ms[10]; // ma sach
	float dg; // don gia
	int sl; // so luong
	char nxb[20]; // nha xuat ban
public:
	Sach()
	{
		strcpy_s(ms, "");
		dg = 0;
		sl = 0;
		strcpy_s(nxb, "");
	}
	Sach(char* ms, float dg, int sl, char* nxb)
	{
		strcpy_s(this->ms,ms);
		this->dg = dg;
		this->sl = sl;
		strcpy_s(this->nxb,nxb);
	}
	~Sach() {}
	virtual void nhap()
	{
		fflush(stdin);
		cout << "Nhap ma sach: "; cin.getline(ms, 10);
		cout << "Nhap don gia: "; cin >> dg;
		cout << "So luong: "; cin >> sl;
		cin.ignore();
		cout << "Nha xuat ban: "; cin.getline(nxb, 20);
	}
	virtual void xuat()
	{
		cout << "\t"
			 << left << setw(10) << ms
			 << left << setw(10) << dg
			 << left << setw(10) << sl
			 << left << setw(20) << nxb;
	}
	float getdg()
	{
		return dg;
	}
	char *getnxb()
	{
		return nxb;
	}
	virtual float thanhtien() = 0;
};
class Sachgiaokhoa : public Sach
{
private:
	char tts[20]; // tinh trang sach
public:
	Sachgiaokhoa() : Sach()
	{
		strcpy_s(tts, "");
	}
	Sachgiaokhoa(char* tts, char* ms, float dg, int sl, char* nxb) : Sach(ms, dg, sl, nxb)
	{
		strcpy_s(this->tts, tts);
	}
	~Sachgiaokhoa() {}
	void nhap()
	{
		Sach::nhap();
		fflush(stdin);
		cout << "Nhap tinh trang sach ('moi' hoac 'cu'): "; cin.getline(tts, 20);
		while (strcmp(tts, "moi") != 0 && strcmp(tts, "cu") != 0)
		{
			cout << "Nhap lai tinh trang sach ('moi' hoac 'cu'): ";  cin.getline(tts, 20);
		}
	}
	float thanhtien()
	{
		if (strcmp(tts, "cu") == 0)
			return sl * dg * 0.5;
		if (strcmp(tts, "moi") == 0)
			return sl * dg;
	}
	void xuat()
	{
		Sach::xuat();
		cout << left << setw(20) << tts
			 << left << setw(10) << thanhtien()
			 << endl;
	}
};
class Sachthamkhao : public Sach
{
private:
	int thue; // tien thue
public:
	Sachthamkhao() : Sach()
	{
		thue = 0;
	}
	Sachthamkhao(int thue, char* ms, float dg, int sl, char* nxb) : Sach(ms, dg, sl, nxb)
	{
		this->thue = thue;
	}
	~Sachthamkhao() {}
	void nhap()
	{
		Sach::nhap();
		cout << "Nhap tien thue: "; cin >> thue;
	}
	float thanhtien()
	{
		return sl * dg + thue;
	}
	void xuat()
	{
		Sach::xuat();
		cout << left << setw(10) << thue
			 << left << setw(10) << thanhtien()
			 << endl;
	}
};

void tieude1()
{
	cout << "\t"
		 << left << setw(10) << "Ma sach"
		 << left << setw(10) << "Don gia"
		 << left << setw(10) << "So luong"
		 << left << setw(20) << "Nha xuat ban"
		 << left << setw(20) << "Tinh trang sach"
		 << left << setw(10) << "Thanh tien"
		 << endl;
}
void tieude2()
{
	cout << "\t"
		 << left << setw(10) << "Ma sach"
		 << left << setw(10) << "Don gia"
		 << left << setw(10) << "So luong"
		 << left << setw(20) << "Nha xuat ban"
		 << left << setw(10) << "Thue"
		 << left << setw(10) << "Thanh tien"
		 << endl;
}
void input1(Sachgiaokhoa a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap thong tin sach giao khoa thu " << i + 1 << endl;
		a[i].nhap();
		cout << endl;
	}
}
void output1(Sachgiaokhoa a[], int n)
{
	cout << "\t______________________DANH SACH THONG TIN SACH GIAO KHOA________________________" << endl;
	tieude1();
	for (int i = 0; i < n; i++)
	{
		a[i].xuat();
	}
	cout << endl;
}
void input2(Sachthamkhao b[], int m)
{
	for (int j = 0; j < m; j++)
	{
		cin.ignore();
		cout << "(*) Nhap thong tin sach tham khao thu " << j + 1 << endl;
		b[j].nhap();
		cout << endl;
	}
}
void output2(Sachthamkhao b[], int m)
{
	cout << "\t__________________DANH SACH THONG TIN SACH THAM KHAO__________________" << endl;
	tieude2();
	for (int j = 0; j < m; j++)
	{
		b[j].xuat();
	}
	cout << endl;
}
void tinhTongThanhTien(Sachgiaokhoa a[], Sachthamkhao b[], int n, int m)
{
	float S1 = 0, S2 = 0;
	for (int i = 0; i < n; i++)
	{
		S1 += a[i].thanhtien();
	}
	cout << "\t=> Tong thanh tien cua " << n << " quyen sach giao khoa la : " << S1 << endl;
	for (int j = 0; j < m; j++)
	{
		S2 += b[j].thanhtien();
	}
	cout << "\t=> Tong thanh tien cua " << m << " quyen sach tham khao la : " << S2 << endl;
}
void tinhTbcstk(Sachthamkhao b[], int m)
{
	float S = 0;
	for (int j = 0; j < m; j++)
	{
		S += b[j].getdg();
	}
	cout << "\t=> Trung binh cong don gia cac sach tham khao la: " << (float)S / m << endl;
}
void timSach(Sachgiaokhoa *a, Sachthamkhao *b, int n, int m)
{
	char x[20];
	cin.ignore();
	cout << "\tNhap ten nha xuat ban can tim: "; cin.getline(x,20);
	cout << endl;
	int count1 = 0, count2 = 0;
	cout << "\t_______DANH SACH THONG TIN SACH GIAO KHOA CUA NHA XUAT BAN " << x << "__________" << endl;
	tieude1();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].getnxb(),x) == 0)
		{
			a[i].xuat();
			count1++;
		}
	}
	if (count1 == 0)
		cout << "\t=> Khong co sach giao khoa nao cua nha xuat ban " << x << endl;
	cout << "\t___DANH SACH THONG TIN SACH THAM KHAO CUA NHA XUAT BAN " << x << "____" << endl;
	tieude2();
	for (int j = 0; j < m; j++)
	{
		if (strcmp(b[j].getnxb(), x) == 0)
		{
			b[j].xuat();
			count2++;
		}
	}
	if (count2 == 0)
		cout << "\t=> Khong co sach tham khao nao cua nha xuat ban " << x << endl;
}

int main()
{
	int n, m, luaChon1;
	cout << "Nhap so luong sach giao khoa: "; cin >> n;
	Sachgiaokhoa* s1 = new Sachgiaokhoa[n];
	cout << "Nhap so luong sach tham khao: "; cin >> m;
	Sachthamkhao* s2 = new Sachthamkhao[m];
	do
	{
		cout << "\t__________________________________MENU___________________________________" << endl
			 << "\t|1. Nhap va xuat danh sach thong tin cach loai sach                     |" << endl
			 << "\t|2. Tinh tong thanh tien cac loai sach                                  |" << endl
			 << "\t|3. Tinh trung binh cong don gia cac sach tham khao                     |" << endl
			 << "\t|4. Xuat ra cac sach giao khoa cua nha xuat ban X                       |" << endl
			 << "\t|0. Thoat                                                               |" << endl
			 << "\t|_______________________________________________________________________|" << endl;
		cout << "<!> Nhap lua chon cua ban: "; cin >> luaChon1; cout << endl;
		switch (luaChon1)
		{
			case 0:
			{
				cout << "Thoat . Chuong trinh ket thuc !!!" << endl; break;
			}
			case 1:
			{
				int luaChon2;
				do
				{
					cout << "\t_____________________LUA CHON 1________________________" << endl
						 << "\t|1.Nhap va xuat danh sach sach giao khoa              |" << endl
						 << "\t|2.Nhap va xuat danh sach sach tham khao              |" << endl
						 << "\t|0.Thoat !                                            |" << endl
						 << "\t|_____________________________________________________|" << endl;
					cout << "\tNhap vao lua chon cua ban: "; cin >> luaChon2; cout << endl;
					switch (luaChon2)
					{
						case 1:
						{
							input1(s1, n);
							output1(s1, n);
							break;
						}
						case 2:
						{
							input2(s2, m);
							output2(s2, m);
							break;
						}
						case 0:
						{
							cout << "\t(!) Thoat lua chon thu 1" << endl;
							break;
						}
						default:
							cout << "\t=> Nhap lai lua chon !!!" << endl;
							break;
					}
				} while (luaChon2 != 0);
				break;
			}
			case 2:
			{
				tinhTongThanhTien(s1, s2, n, m);
				break;
			}
			case 3:
			{
				tinhTbcstk(s2, m);
				break;
			}
			case 4:
			{
				timSach(s1, s2, n, m);
				break;
			}

		default:
			cout << "\tKhong co lua chon nay vui long nhap lai !!!" << endl;
			break;
		}
	} while (luaChon1 != 0);
	return 0;
}