#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
using namespace std;

class Dichvu
{
protected:
	int dg; // don gia (don vi tram)
public:
	Dichvu()
	{
		dg = 0;
	}
	Dichvu(int dg)
	{
		this->dg = dg;
	}
	~Dichvu() {}
	virtual void nhap()
	{
		cout << "Nhap don gia cua san pham: "; cin >> dg;
	}
	virtual void xuat()
	{
		cout << left << setw(10) << dg;
	}
	virtual float thanhTien() = 0;
	virtual int phanLoai() = 0;
};
class Dichvugiatla : public Dichvu
{
private:
	char tqa[20]; // ten quan ao
	float kg; // khoi luong quan ao
	int tdv;
public:
	Dichvugiatla()
	{
		strcpy_s(tqa, "");
		kg = 0;
		tdv = 0;
	}
	Dichvugiatla(int dg, char* tqa, float kg, int tdv) : Dichvu(dg)
	{
		strcpy_s(this->tqa, tqa);
		this->kg = kg;
		this->tdv = tdv;
	}
	~Dichvugiatla() {}
	void nhap()
	{
		Dichvu::nhap();
		cin.ignore();
		cout << "Nhap ten quan ao: "; cin.getline(tqa, 20);
		if (strcmp(tqa, "vest") == 0 || strcmp(tqa, "ao lua") == 0)
		{
			cout << "Nhap tien dich vu: "; cin >> tdv;
		}
		cout << "Nhap khoi luong quan ao: "; cin >> kg;
	}
	float thanhTien()
	{
		if (kg <= 5)
		{
			if (strcmp(tqa, "vest") == 0 || strcmp(tqa, "ao lua") == 0)
				return kg * dg * tdv;
			else
				return kg * dg;
		}
		else
		{
			if (strcmp(tqa, "vest") == 0 || strcmp(tqa, "ao lua") == 0)
				return (kg * dg * tdv) * 0.95;
			else
				return (kg * dg) * 0.95;
		}
	}
	void xuat()
	{
		Dichvu::xuat();
		cout << left << setw(20) << tqa
			 << left << setw(15) << kg
			 << left << setw(30) << thanhTien()
			 << endl;
	}
	int phanLoai()
	{
		return 1;
	}
};
class Dichvuthuexe : public Dichvu
{
private:
	int h; // so gio thue xe
public:
	Dichvuthuexe()
	{
		h = 0;
	}
	Dichvuthuexe(int dg, int h) : Dichvu(dg)
	{
		this->h = h;
	}
	~Dichvuthuexe() {}
	void nhap()
	{
		Dichvu::nhap();
		cout << "Nhap so gio thue xe: "; cin >> h;
	}
	float thanhTien()
	{
		if (h > 10)
			return h * dg * 0.9;
		else
			return h * dg;
	}
	void xuat()
	{
		Dichvu::xuat();
		cout << left << setw(20) << h
		 	 << left << setw(20) << thanhTien()
			 << endl;
	}
	int phanLoai()
	{
		return 2;
	}
};
void tieude1()
{
	cout << "\t";
	cout << left << setw(10) << "Ma hd"
		<< left << setw(10) << "Ma khach"
		<< left << setw(20) << "Ten khach hang"
		<< left << setw(10) << "Don gia"
		<< left << setw(20) << "Ten quan ao"
		<< left << setw(15) << "Khoi luong"
		<< left << setw(20) << "Tien giat la"
		<< endl;
}
void tieude2()
{
	cout << "\t";
	cout << left << setw(10) << "Ma hd"
		<< left << setw(10) << "Ma khach"
		<< left << setw(20) << "Ten khach hang"
		<< left << setw(10) << "Don gia"
		<< left << setw(20) << "Gio thue"
		<< left << setw(15) << "Tien thue xe"
		<< endl;
}
class Hoadon
{
private:
	char mhd[10]; // ma hoa don
	char mkh[10]; // ma khach hang
	char tkh[20]; // ten khach hang
	int n;
	Dichvu* d[50];
public:
	Hoadon()
	{
		strcpy_s(mhd, "");
		strcpy_s(mkh, "");
		strcpy_s(tkh, "");
	}
	Hoadon(char* mhd, char* mkh, char* tkh)
	{
		strcpy_s(this->mhd, mhd);
		strcpy_s(this->mkh, mkh);
		strcpy_s(this->tkh, tkh);
	}
	~Hoadon(){}
	void nhap()
	{
		int luaChon1, luaChon2;
		do
		{
			cout << "\t___________________________MENU____________________________" << endl
				 << "\t|1. Nhap va in hoa don                                     |" << endl
				 << "\t|2. Tinh tien dich vu va tong tien khach san nhan duoc     |" << endl
				 << "\t|3. Dich vu giat la co tien dich vu lon hon 10 trieu       |" << endl
				 << "\t|4. Thoat !                                                |" << endl
				 << "\t|__________________________________________________________|" << endl;
			cout << "<+> Nhap lua chon cua ban: "; cin >> luaChon1; cout << endl;
			switch (luaChon1)
			{
				case 1:
				{
					cout << "Nhap so luong dich vu: "; cin >> n;
					for (int i = 0; i < n; i++)
					{
						cout << "\t(*) Nhap thong tin dich vu thu " << i + 1 << endl;
						do
						{
							cout << "\t________________________________________" << endl
								<< "\t|1. Dich vu giat la                     |" << endl
								<< "\t|2. Dich vu thue xe                     |" << endl
								<< "\t|_______________________________________|" << endl;
							cout << "<+> Nhap lua chon cua ban: "; cin >> luaChon2;
							if (luaChon2 != 1 && luaChon2 != 2)
								cout << "\t(!) Vui long nhap lai lua chon cua ban !!!" << endl;
						} while (luaChon2 != 1 && luaChon2 != 2);
						if (luaChon2 == 1)
							d[i] = new Dichvugiatla();
						else if (luaChon2 == 2)
							d[i] = new Dichvuthuexe();
						d[i]->nhap();
						cin.ignore();
						cout << "Nhap ma hoa don: "; cin.getline(mhd, 10);
						cout << "Nhap ma khach hang: "; cin.getline(mkh, 10);
						cout << "Ten khach hang: "; cin.getline(tkh, 20);
						cout << endl;
					}
					cout << "\t_______________________________DANH SACH THONG TIN DICH VU GIAT LA_______________________________" << endl;
					tieude1();
					for (int i = 0; i < n; i++)
					{
						if (d[i]->phanLoai() == 1)
						{
							cout << "\t";
							cout << left << setw(10) << mhd
								 << left << setw(10) << mkh
								 << left << setw(20) << tkh;
							d[i]->xuat();
						}
					}
					cout << endl;
					cout << "\t_______________________DANH SACH THONG TIN DICH VU THUE XE________________________" << endl;
					tieude2();
					for (int i = 0; i < n; i++)
					{
						if (d[i]->phanLoai() == 2)
						{
							cout << "\t";
							cout << left << setw(10) << mhd
								 << left << setw(10) << mkh
								 << left << setw(20) << tkh;
							d[i]->xuat();
						}
					}
					cout << endl;
					break;
				}
				case 2:
				{
					float S1 = 0, S2 = 0; // S1: tien dich vu giat la ; S2 : tien dich vu thue xe
					for (int i = 0; i < n; i++)
					{
						if (d[i]->phanLoai() == 1)
							S1 += d[i]->thanhTien();
						else if (d[i]->phanLoai() == 2)
							S2 += d[i]->thanhTien();
					}
					cout << "\t=> Tong thanh tien cua dich vu giat la: " << S1 << endl;
					cout << "\t=> Tong thanh tien cua dich vu thue xe: " << S2 << endl;
					cout << "\t=> Tong tien khach san nhan duoc la: " << S1 + S2 << endl;
					cout << endl;
					break;
				}
				case 3:
				{
					int count = 0;
					cout << "\t__________________DACH SACH THONG TIN DICH VU GIAT LA CO TONG TIEN > 10 TRIEU____________________" << endl;
					tieude1();
					for (int i = 0; i < n; i++)
					{
						if (d[i]->phanLoai() == 1)
						{
							if (d[i]->thanhTien() > 10000)
							{
								count++;
								cout << "\t";
								cout << left << setw(10) << mhd
									 << left << setw(10) << mkh
									 << left << setw(20) << tkh;
								d[i]->xuat();
							}
						}
					}
					if (count == 0)
						cout << "\t=> Khong co dich vu giat la co tong tien lon hon 10 trieu !!!" << endl;
					cout << endl;
					break;
				}
				case 4:
				{
					cout << "(-) Thoat ! Chuong trinh ket thuc !!!" << endl;
					break;
				}
			default:
				cout << "(!) Khong co lua chon nay vui long nhap lai lua chon cua ban !!! " << endl;
				break;
			}
		} while (luaChon1 != 4);
	}
};
int main()
{
	Hoadon hd;
	hd.nhap();
	return 0;
}