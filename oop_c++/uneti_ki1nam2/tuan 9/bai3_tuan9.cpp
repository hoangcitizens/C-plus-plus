#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;

class Dichvu
{
protected:
	char mhd[10]; // ma hoa don
	char mkh[10]; // ma khach hang
	char tkh[20]; // ten khach hang
public:
	Dichvu()
	{
		strcpy_s(mhd, "");
		strcpy_s(mkh, "");
		strcpy_s(tkh, "");
	}
	Dichvu(char* mhd, char* mkh, char* tkh)
	{
		strcpy_s(this->mhd, mhd);
		strcpy_s(this->mkh, mkh);
		strcpy_s(this->tkh, tkh);
	}
	~Dichvu() {}
	virtual void nhap()
	{
		cin.ignore();
		cout << "Nhap ma hoa don: "; cin.getline(mhd, 10);
		cout << "Nhap ma khach hang: "; cin.getline(mkh, 10);
		cout << "Ten khach hang: "; cin.getline(tkh, 20);
	}
	virtual void xuat()
	{
		cout << "\t";
		cout << left << setw(10) << mhd
			 << left << setw(10) << mkh
			 << left << setw(20) << tkh;
	}
	virtual float tongTien() = 0;
	virtual int phanLoai() = 0;
};
class Dichvugiatla : public Dichvu
{
private:
	char tqa[20]; // ten quan ao
	float kg; // khoi luong quan ao
	int dg1; // don gia giat la(don vi trieu dong)
	int tdv; // tien dich vu them
public:
	Dichvugiatla() : Dichvu()
	{
		strcpy_s(tqa, "");
		kg = 0;
		dg1 = 0;
		tdv = 0;
	}
	Dichvugiatla(char* tqa, float kg, int dg1, int tdv, char* mhd, char* mkh, char* tkh) : Dichvu(mhd, mkh, tkh)
	{
		strcpy_s(this->tqa, tqa);
		this->kg = kg;
		this->dg1 = dg1;
		this->tdv = tdv;
	}
	~Dichvugiatla() {}
	void nhap()
	{
		Dichvu::nhap();
		fflush(stdin);
		cout << "Nhap ten quan ao: "; cin.getline(tqa, 20);
		if (strcmp(tqa, "vest") == 0 || strcmp(tqa, "ao lua") == 0)
		{
			cout << "Nhap tien dich vu: "; cin >> tdv;
		}
		cout << "Nhap khoi luong quan ao: "; cin >> kg;
		cout << "Nhap don gia: "; cin >> dg1;
	}
	float tongTien()
	{
		if (kg <= 5)
		{
			if (strcmp(tqa, "vest") == 0 || strcmp(tqa, "ao lua"))
				return kg * dg1 + tdv;
			else
				return kg * dg1;
		}
		else
		{
			if (strcmp(tqa, "vest") == 0 || strcmp(tqa, "ao lua"))
				return (kg * dg1 + tdv) * 0.95;
			else
				return (kg * dg1) * 0.95;
		}
	}
	void xuat()
	{
		Dichvu::xuat();
		cout << left << setw(20) << tqa
			 << left << setw(20) << kg
			 << left << setw(10) << dg1
			 << left << setw(30) << tongTien()
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
	int dg2; // don gia thue xe(don vi trieu dong)
public:
	Dichvuthuexe() : Dichvu()
	{
		h = 0;
		dg2 = 0;
	}
	Dichvuthuexe(int h, int dg2, char* mhd, char* mkh, char* tkh, int sl) : Dichvu(mhd,mkh,tkh)
	{
		this->h = h;
		this->dg2 = dg2;
	}
	~Dichvuthuexe() {}
	void nhap()
	{
		Dichvu::nhap();
		cout << "Nhap so gio thue xe: "; cin >> h;
		cout << "Nhap don gia: "; cin >> dg2;
	}
	float tongTien()
	{
		if (h > 10)
			return h * dg2 * 0.9;
		else
			return h * dg2;
	}
	void xuat()
	{
		Dichvu::xuat();
		cout << left << setw(20) << h
			 << left << setw(10) << dg2
			 << left << setw(30) << tongTien()
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
		 << left << setw(20) << "Ten quan ao"
		 << left << setw(20) << "K.luong"
	 	 << left << setw(10) << "Don gia"
	 	 << left << setw(30) << "Tien giat la"
		 << endl;
}
void tieude2()
{
	cout << "\t";
	cout << left << setw(10) << "Ma hd"
		 << left << setw(10) << "Ma khach"
		 << left << setw(20) << "Ten khach hang"
		 << left << setw(20) << "Gio thue"
		 << left << setw(10) << "Don gia"
		 << left << setw(30) << "Tien thue xe"
		 << endl;
}

int main()
{
	int n, luaChon1, luaChon2;
	Dichvu *d[50];
	do
	{
		cout << "\t_________________________MENU__________________________" << endl
			 << "\t|1. Nhap va in hoa don                                 |" << endl
			 << "\t|2. Tinh tien dich vu va tong tien khach san nhan duoc |" << endl
			 << "\t|3. Dich vu giat la co tien dich vu lon hon 10 trieu   |" << endl
			 << "\t|4. Thoat !                                            |" << endl
			 << "\t|______________________________________________________|" << endl;
		cout << "<!> Nhap lua chon cua ban: "; cin >> luaChon2; cout << endl;
		switch (luaChon2)
		{
			case 1: 
			{
				cout << "Nhap so luong dich vu: "; cin >> n;
				for (int i = 0; i < n; i++)
				{
					cout << "\t(*) Nhap va in ra thong tin dich vu thu " << i + 1 << endl;
					do
					{
						cout << "\t________________________________________________" << endl
							<< "\t|1. Dich vu giat la                             |" << endl
							<< "\t|2. Dich vu thue xe                             |" << endl
							<< "\t|_______________________________________________|" << endl;
						cout << "<!> Nhap lua chon cua ban: "; cin >> luaChon1;
						if (luaChon1 != 1 && luaChon1 != 2)
							cout << "(!) Vui long nhap lai lua chon cua ban !!!" << endl;
					} while (luaChon1 != 1 && luaChon1 != 2);
					if (luaChon1 == 1)
					{
						d[i] = new Dichvugiatla();
					}
					else if (luaChon1 == 2)
						d[i] = new Dichvuthuexe();
					d[i]->nhap();
					cout << endl;
				}
				cout << "\t__________________________________DANH SACH THONG TIN DICH VU GIAT LA_________________________________" << endl;
				tieude1();
				for (int i = 0; i < n; i++)
				{
					if (d[i]->phanLoai() == 1)
						d[i]->xuat();
				}
				cout << endl;
				cout << "\t________________________DANH SACH THONG TIN DICH VU THUE XE_______________________" << endl;
				tieude2();
				for (int i = 0; i < n; i++)
				{
					if (d[i]->phanLoai() == 2)
						d[i]->xuat();
				}
				cout << endl;
				break;
			} 	
			case 2:
			{
				float S = 0, S1 = 0, S2 = 0; // S: tong tien khach san nhan duoc ; S1: tien dich vu giat la ; S2: tien dich vu thue xe
				for (int i = 0; i < n; i++)
				{
					if (d[i]->phanLoai() == 1)
						S1 += d[i]->tongTien();
					else if (d[i]->phanLoai() == 2)
						S2 += d[i]->tongTien();
				}

				cout << "\t=> Tong thanh tien cua dich vu giat la: " << S1 << endl;
				cout << "\t=> Tong thanh tien cua dich vu thue xe: " << S2 << endl;
				cout << "\t=> Tong tien khach san nhan duoc la: " << S1 + S2 << endl;
				cout << endl;
				break;
			}
			case 3:
			{
				cout << "\t____________________DANH SACH THONG TIN DICH VU GIAT LA CO TONG TIEN HON 10 TRIEU______________________" << endl;
				tieude1();
				for (int i = 0; i < n; i++)
				{
					if (d[i]->phanLoai() == 1)
					{
						if (d[i]->tongTien() > 10000)
						{
							d[i]->xuat();
						}
					}
				}
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "(-) Thoat ! Chuong trinh ket thuc !!!" << endl;
				break;
			}
		default:
			cout << "(!) Khong co lua chon nay vui long nhap lai lua chon cua ban !!!" << endl;
			break;
		}
	} while (luaChon2 != 4);
	return 0;
}