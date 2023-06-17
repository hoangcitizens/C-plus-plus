#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

class Subscriber
{
public:
	Subscriber();
	~Subscriber();
	virtual void import();
	virtual void display();
	virtual float fee() = 0;
	virtual int options() = 0;
protected:
};
Subscriber::Subscriber(){}
Subscriber::~Subscriber(){}
void Subscriber::import(){}
void Subscriber::display(){}

class DialUp : public Subscriber
{
public:
	DialUp(float);
	~DialUp();
	void import() override;
	void display() override;
	float fee();
	int options();
private:
	float time;
};

DialUp::DialUp(float time = 0) : Subscriber()
{
	this->time = time;
}
DialUp::~DialUp(){}
void DialUp::import()
{
	cout << "Nhap so phut truy cap: "; cin >> time;
}
float DialUp::fee()
{
	return 30 * time + 30000;
}
void DialUp::display()
{
	cout << "\t" << left << setw(20) << "|      Dial Up"
		 << "|" << left << setw(14) << time
		 << "|" << left << setw(14) << "Unknown"
		 << "|" << left << setw(13) << fee() << "|" << endl;
}
int DialUp::options()
{
	return 1;
}

class ADSL : public Subscriber
{
public:
	ADSL(float);
	~ADSL();
	void import() override;
	void display() override;
	float fee();
	int options();
private:
	float data;
};

ADSL::ADSL(float data = 0) : Subscriber()
{
	this->data = data;
}
ADSL::~ADSL() {}
void ADSL::import()
{
	cout << "Nhap so dung luong truy cap: "; cin >> data;
}
float ADSL::fee()
{
	return 50 * data + 50000;
}
void ADSL::display()
{
	cout << "\t" << left << setw(20) << "|       ADSL"
		 << "|" << left << setw(14) << "Unknown"
		 << "|" << left << setw(14) << data
		 << "|" << left << setw(13) << fee() << "|" << endl;
}
int ADSL::options()
{
	return 2;
}

class T1 : public Subscriber
{
public:
	T1();
	~T1();
	void display() override;
	float fee();
	int options();
};

T1::T1() : Subscriber() {}
T1::~T1() {}
float T1::fee()
{
	return 2000000;
}
void T1::display()
{
	cout << "\t" << left << setw(20) << "|         T1"
		 << "|" << left << setw(14) << "Unknown"
		 << "|" << left << setw(14) << "Unknown"
		 << "|" << left << setw(13) << fee() << "|" << endl;
}
int T1::options()
{
	return 3;
}

void title()
{
	cout << "\t" << "_________________________________________________________________" << endl << "\t"
		 << left << setw(20) << "|   Loai thue bao"
		 << left << setw(15) << "|    So phut"
		 << left << setw(15) << "| So dung luong"
		 << left << setw(15) << "|   Cuoc phi  |" << endl << "\t"
		 << "*---------------------------------------------------------------*" << endl;

}

class ManagerSubscriber
{
public:
	ManagerSubscriber();
	void init();
	void sum();
	void sumS();
	void findADSL();
	Subscriber* s[20];
	int n;
	void menu();
};

ManagerSubscriber::ManagerSubscriber(){}
void ManagerSubscriber::init()
{
	int options;
	cout << "Nhap so luong thue bao: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin thue bao thu " << i + 1 << endl;
		do
		{
			cout << "\t________________" << endl
				<< "\t|1. Dial Up     |" << endl
				<< "\t|2. ADSL        |" << endl
				<< "\t|3. T1          |" << endl
				<< "\t|_______________|" << endl;
			cout << "\t<+> Nhap loai thue bao: "; cin >> options;
			if (options != 1 && options != 2 && options != 3)
				cout << "\t(!) Vui long nhap lai lua chon cua ban !!!" << endl;
		} while (options != 1 && options != 2 && options != 3);
		if (options == 1)
			s[i] = new DialUp();
		if (options == 2)
			s[i] = new ADSL();
		if (options == 3)
			s[i] = new T1();
		s[i]->import();
	}
	cout << "\t\t\t\tDANH SACH THONG TIN THUE BAO" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
			s[i]->display();
			cout << "\t*---------------------------------------------------------------*" << endl;
	}
	cout << endl;
}
void ManagerSubscriber::sum()
{
	float Sd = 0, Sa = 0, St = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i]->options() == 1)
			Sd += s[i]->fee();

		else if (s[i]->options() == 2)
			Sa += s[i]->fee();

		else if (s[i]->options() == 2)
			St += s[i]->fee();
		else
			cout << "0" << endl;
	}
	cout << "\t=> Tong phi cuoc cua loai thue bao DialUp la: " << Sd << endl;
	cout << "\t=> Tong phi cuoc cua loai thue bao ADSL la: " << Sa << endl;
	cout << "\t=> Tong phi cuoc cua loai thue bao T1 la: " << St << endl;
	cout << endl;
}
void ManagerSubscriber::sumS()
{
	float S = 0;
	for (int i = 0; i < n; i++)
	{
		S += s[i]->fee();
	}
	cout << "\tTong tien cuoc phi thu duoc cua tat ca cac thue bao trong thang: " << S << endl;
	cout << endl;
}
void ManagerSubscriber::findADSL()
{
	Subscriber *max = s[0];
	cout << "\t\tTHONG TIN THUE BAO ADSL TIEN CUOC LON NHAT" << endl;
	title();
	for (int i = 1; i < n; i++)
	{
		if (s[i]->options() == 2)
		{
			if (s[i]->fee() > max->fee())
			{
				max = s[i];
			}
		}
	}
	max->display();
	cout << endl;
}
void ManagerSubscriber::menu()
{
	int options;
	do
	{
		cout << "\t____________________________MENU_____________________________" << endl
			 << "\t|1. Quan ly danh sach thue bao                              |" << endl
			 << "\t|2. Tinh tong tien cuoc cua tung loai thue bao              |" << endl
			 << "\t|3. Tinh tong tien cua tat ca cac thue bao trong thang      |" << endl
			 << "\t|4. Tim va xuat thong tin thue bao ADSL co cuoc lon nhat.   |" << endl
			 << "\t|5. Exit !!!                                                |" << endl
			 << "\t|___________________________________________________________|" << endl;
		cout << "\tNhap lua chon cua ban: "; cin >> options;
		switch (options)
		{
		case 1:
		{
			init();
			break;
		}
		case 2:
		{
			sum();
			break;
		}
		case 3:
		{
			sumS();
			break;
		}
		case 4:
		{
			findADSL();
			break;
		}
		case 5:
		{
			cout << "\t(!) Exit ! Ket thuc chuong trinh !!!" << endl;
			break;
		}
		default:
			cout << "\t(!) Khong co lua chon nay vui long chon lai !!!" << endl;
			cout << "\tNhap lua chon cua ban: "; cin >> options;
			if (options == 5)
				cout << "\t(!) Exit ! Ket thuc chuong trinh !!!" << endl;
			break;
		}
	} while (options != 5);
}

int main()
{
	ManagerSubscriber m;
	m.menu();
	return 0;
}