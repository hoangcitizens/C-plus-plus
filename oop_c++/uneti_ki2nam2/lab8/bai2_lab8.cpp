#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

// Lop Quay
class Counter
{
public:
	Counter(string, int, float, float);
	~Counter();
	virtual void import();
	virtual float salesTax() = 0; // tinh thue doanh thu mat hang
	virtual float serviceFee(); // tinh tien dich vu
	virtual float counterRent(); // tien thue quay
	virtual float pay(); // tinh tien phai dong
	virtual void display();
	virtual int check() = 0;
protected:
	string id; // ma quay
	int s; // so thu tu
	float acreage; // dien tich
	float revenue; // doanh thu
};

Counter::Counter(string id = "Unknown", int s = 0, float acreage = 0, float revenue = 0)
{
	this->id = id;
	this->s = s;
	this->acreage = acreage;
	this->revenue = revenue;
}
Counter::~Counter() {}
void Counter::import()
{
	cout << "Nhap so thu tu quay: "; cin >> s;
	cin.ignore();
	cout << "Nhap ma quay: "; getline(cin, id);
	cout << "Nhap dien tich quay: "; cin >> acreage;
	cout << "Nhap doanh thu quay: "; cin >> revenue;
}
float Counter::serviceFee()
{
	return 0;
}
float Counter::counterRent()
{
	return 5 * (float)pow(10, 7) * acreage;
}
float Counter::pay()
{
	return serviceFee() + counterRent() + salesTax();
}
void Counter::display()
{
	cout << "\t"
		 << "|" << left << setw(9) << s
		 << "|" << left << setw(14) << id
		 << "|" << left << setw(14) << acreage
		 << "|" << left << setw(14) << revenue
		 << "|" << left << setw(14) << salesTax()
		 << "|" << left << setw(14) << serviceFee()
		 << "|" << left << setw(14) << counterRent()
		 << "|" << left << setw(13) << pay() << "|" << endl;
}

// Lop Quay Quan Ao
class ClothesCounter : public Counter
{
public:
	ClothesCounter(string, int, float, float);
	~ClothesCounter();
	void import() override;
	float salesTax(); // tinh thue doanh thu mat hang
	float counterRent(); // tien thue quay
	float pay(); // tinh tien phai dong
	void display() override;
	int check();  // phan loai quay
};

ClothesCounter::ClothesCounter(string id = "Unknown", int s = 0, float acreage = 0, float revenue = 0)
	: Counter(id,s,acreage,revenue) {}
ClothesCounter::~ClothesCounter() {}
void ClothesCounter::import()
{
	Counter::import();
}
float ClothesCounter::salesTax()
{
	return revenue * (float)0.05;
}
float ClothesCounter::counterRent()
{
	return Counter::counterRent();
}
float ClothesCounter::pay()
{
	return Counter::pay();
}
void ClothesCounter::display()
{
	Counter::display();
}
int ClothesCounter::check()
{
	return 1;
}

// Lop Quay Thuc Pham
class FoodCounter : public Counter
{
public:
	FoodCounter(string, int, float, float, float);
	~FoodCounter();
	void import();
	float salesTax(); // tinh thue doanh thu mat hang
	float counterRent(); // tien thue quay
	float serviceFee(); // tinh tien dich vu
	float pay(); // tinh tien phai dong
	void display();
	int check();
private:
	float fee; // tien dich vu
};

FoodCounter::FoodCounter(string id = "Unknown", int s = 0, float acreage = 0, float revenue = 0, float fee = 0)
	: Counter(id, s, acreage, revenue)
{
	this->fee = fee;
}
FoodCounter::~FoodCounter() {}
void FoodCounter::import()
{
	Counter::import();
	cout << "Nhap tien dich vu: "; cin >> fee;
}
float FoodCounter::salesTax()
{
	return revenue * (float)0.1;
}
float FoodCounter::counterRent()
{
	return Counter::counterRent();
}
float FoodCounter::serviceFee()
{
	return fee;
}
float FoodCounter::pay()
{
	return Counter::pay();
}
void FoodCounter::display()
{
	Counter::display();
}
int FoodCounter::check()
{
	return 2;
}

// Lop Quay Trang Suc
class JewelryCounter : public Counter
{
public:
	JewelryCounter(string, int, float, float);
	~JewelryCounter();
	void import();
	float salesTax(); // tinh thue doanh thu mat hang
	float counterRent(); // tien thue quay
	float pay(); // tinh tien phai dong
	void display();
	int check();
};

JewelryCounter::JewelryCounter(string id = "Unknown", int s = 0, float acreage = 0, float revenue = 0)
	: Counter(id, s, acreage, revenue) {}
JewelryCounter::~JewelryCounter() {}
void JewelryCounter::import()
{
	Counter::import();
}
float JewelryCounter::salesTax()
{
	if (revenue < pow(10, 8))
		return revenue * (float)0.2;
	else
		return revenue * (float)0.3;
}
float JewelryCounter::counterRent()
{
	return Counter::counterRent();
}
float JewelryCounter::pay()
{
	return Counter::pay();
}
void JewelryCounter::display()
{
	Counter::display();
}
int JewelryCounter::check()
{
	return 3;
}

void title()
{
	cout << "\t" << "___________________________________________________________"
		 << "________________________________________________________" << endl << "\t"
		 << left << setw(10) << "|   Stt"
		 << left << setw(15) << "|    Ma quay"
		 << left << setw(15) << "|   Dien tich"
		 << left << setw(15) << "|   Doanh thu"
		 << left << setw(15) << "|Thue doanh thu"
		 << left << setw(15) << "| Tien dich vu"
		 << left << setw(15) << "|Tien thue quay"
		 << left << setw(15) << "|  Tong tien  |" << endl << "\t"
		 << "*------------------------------------------------------------"
		 << "-----------------------------------------------------*" << endl;
}

// Lop Sieu thi
class Supermarket
{
public:
	Supermarket();
	void init();
	void sumPay(); // tinh tong tien phai dong
	Counter* c[20];
	int n;
};

Supermarket::Supermarket() {}
void Supermarket::init()
{
	int options;
	cout << "Nhap so luong quay: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin quay hang thu " << i + 1 << endl;
		do
		{
			cout << "\t_____________________" << endl
				<< "\t|1. Quay quan ao     |" << endl
				<< "\t|2. Quay thuc pham   |" << endl
				<< "\t|3. Quay trang suc   |" << endl
				<< "\t|____________________|" << endl;
			cout << "\t<+> Nhap loai quay hang: "; cin >> options;
			if (options != 1 && options != 2 && options != 3)
				cout << "\t(!) Vui long nhap lai lua chon cua ban !!!" << endl;
		} while (options != 1 && options != 2 && options != 3);
		if (options == 1)
			c[i] = new ClothesCounter();
		if (options == 2)
			c[i] = new FoodCounter();
		if (options == 3)
			c[i] = new JewelryCounter();
		c[i]->import();
	}
	cout << "\t\t\t\t\t\tDANH SACH THONG TIN QUAY BAN HANG" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		c[i]->display();
		cout << "\t*------------------------------------------------------------"
			 << "-----------------------------------------------------*" << endl;
	}
	cout << endl;
}
void Supermarket::sumPay()
{
	int countC = 0, countF = 0, countJ = 0; // dem so luong tung quay 
	float Sc = 0, Sf = 0, Sj = 0; // tong tien cua tung loai quay
	for (int i = 0; i < n; i++)
	{
		if (c[i]->check() == 1)
		{
			Sc += c[i]->pay();
			countC++;
		}
		else if (c[i]->check() == 2)
		{
			Sf += c[i]->pay();
			countF++;
		}
		else if (c[i]->check() == 3)
		{
			Sj += c[i]->pay();
			countJ++;
		}
		else
			cout << "0" << endl;
	}
	cout << "\t=> Tong tien cua " << countC << " quay Quan Ao phai dong la : " << Sc << endl;
	cout << "\t=> Tong tien cua " << countF << " quay Thuc Pham phai dong la: " << Sf << endl;
	cout << "\t=> Tong tien cua " << countJ << " quay Trang Suc la: " << Sj << endl;
	cout << endl;
}

int main()
{
	Supermarket s;
	s.init();
	s.sumPay();
	return 0;
}