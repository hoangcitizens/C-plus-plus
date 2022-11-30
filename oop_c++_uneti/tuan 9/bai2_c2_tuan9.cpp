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
		strcpy_s(this->ms, ms);
		this->dg = dg;
		this->sl = sl;
		strcpy_s(this->nxb, nxb);
	}
	~Sach() {}
	virtual void nhap()
	{
		cin.ignore();
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
	char* getnxb()
	{
		return nxb;
	}
	virtual float thanhtien() = 0;
	virtual int phanLoai() = 0;
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
		else if (strcmp(tts, "moi") == 0)
			return sl * dg;
	}
	void xuat()
	{
		Sach::xuat();
		cout << left << setw(20) << tts
			 << left << setw(10) << thanhtien()
			 << endl;
	}
	int phanLoai()
	{
		return 1;
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
	int phanLoai()
	{
		return 2;
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

void menu(Sach* s[20])
{
	int n, luaChon1, luaChon2;
	do
	{
		cout << "\t__________________________________MENU___________________________________" << endl
			 << "\t|1. Nhap va xuat danh sach thong tin cach loai sach                     |" << endl
			 << "\t|2. Tinh tong thanh tien cac loai sach                                  |" << endl
			 << "\t|3. Tinh trung binh cong don gia cac sach tham khao                     |" << endl
			 << "\t|4. Xuat ra cac sach giao khoa cua nha xuat ban X                       |" << endl
			 << "\t|5. Thoat !                                                             |" << endl
			 << "\t|_______________________________________________________________________|" << endl;
		cout << "\t<+> Nhap lua chon cua ban: "; cin >> luaChon1; cout << endl;
		switch (luaChon1)
		{
			case 1:
			{
				cout << "Nhap so luong sach: "; cin >> n;
				for (int i = 0; i < n; i++)
				{
					cout << "\t(*) Nhap thong tin loai sach thu " << i + 1 << endl;
					do
					{
						cout << "\t___________________________________" << endl
							 << "\t|1. Sach giao khoa                 |" << endl
							 << "\t|2. Sach tham khao                 |" << endl
							 << "\t|__________________________________|" << endl;
						cout << "<+> Nhap lua chon cua ban: "; cin >> luaChon2;
						if (luaChon2 != 1 && luaChon2 != 2)
							cout << "(!) Khong co lua chon nay vui long chon lai !!!" << endl;	
					} while (luaChon2 != 1 && luaChon2 != 2);
					if (luaChon2 == 1)
						s[i] = new Sachgiaokhoa();			
					else if (luaChon2 == 2)
						s[i] = new Sachthamkhao();				
					s[i]->nhap();
					cout << endl;		
				}
				cout << "\t______________________DANH SACH THONG TIN SACH GIAO KHOA________________________" << endl;
				tieude1();
				for (int i = 0; i < n; i++)
				{
					if (s[i]->phanLoai() == 1)				
						s[i]->xuat();
				}
				cout << endl;
				cout << "\t__________________DANH SACH THONG TIN SACH THAM KHAO__________________" << endl;
				tieude2();
				for (int i = 0; i < n; i++)
				{
					if (s[i]->phanLoai() == 2)
						s[i]->xuat();
				}
				cout << endl;
				break;
			}
			case 2:
			{
				float S1 = 0, S2 = 0, count1 = 0, count2 = 0;
				for (int i = 0; i < n; i++)
				{
					if (s[i]->phanLoai() == 1)
					{
						count1++;
						S1 += s[i]->thanhtien();
					}
					else if (s[i]->phanLoai() == 2)
					{
						count2++;
						S2 += s[i]->thanhtien();
					}
				}
				cout << "\t=> Tong thanh tien cua " << count1 << " quyen sach giao khoa la : " << S1 << endl;
				cout << "\t=> Tong thanh tien cua " << count2 << " quyen sach tham khao la : " << S2 << endl;
				cout << endl;
				break;
			}
			case 3:
			{
				float S = 0, count = 0;
				for (int i = 0; i < n; i++)
				{
					if (s[i]->phanLoai() == 2)
					{
						count++;
						S += s[i]->getdg();
					}
				}
				cout << "\t=> Trung binh cong don gia cac sach tham khao la: " << (float)S / count << endl;
				cout << endl;
				break;
			}
			case 4:
			{
				char x[20];
				cin.ignore();
				cout << "\t(+)Nhap ten nha xuat ban can tim: "; cin.getline(x, 20);
				cout << endl;
				int count3 = 0, count4 = 0;
				cout << "\t__________DANH SACH THONG TIN SACH GIAO KHOA CUA NHA XUAT BAN " << x << "__________" << endl;
				tieude1();
				for (int i = 0; i < n; i++)
				{
					if (s[i]->phanLoai() == 1)
					{
						if (strcmp(s[i]->getnxb(), x) == 0)
						{
							s[i]->xuat();
							count3++;
						}
					}	
				}
				if (count3 == 0)
					cout << "\t=> Khong co sach giao khoa nao cua nha xuat ban " << x << endl;
				cout << endl;
				cout << "\t_____DANH SACH THONG TIN SACH THAM KHAO CUA NHA XUAT BAN " << x << "_____" << endl;
				tieude2();
				for (int i = 0; i < n; i++)
				{
					if (s[i]->phanLoai() == 2)
					{
						if (strcmp(s[i]->getnxb(), x) == 0)
						{
							s[i]->xuat();
							count4++;
						}
					}
				}
				if (count4 == 0)
					cout << "\t=> Khong co sach tham khao nao cua nha xuat ban " << x << endl;
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "\t(-) Thoat ! Chuong trinh ket thuc !!!" << endl;
				break;
			}
		default:
			cout << "\t(!) Khong co lua chon nay ! Vui long lua chon lai !!!" << endl;
			break;
		}
	} while (luaChon1 != 5);
}

int main()
{
	Sach* s[20];
	menu(s);
	return 0;
}