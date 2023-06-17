/*
	abstraction : truu tuong (the hien tinh khong ro rang khong cu the)
	 < tinh truu tuong cua doi tuong chi hien thi nhung chuc nang can thiet ra ben ngoai va che dau di cai chi tiet ben trong >
*/

#include<iostream>
#include<string>
using namespace std;

class Woman
{
public:
	Woman(string fullname, int age, float weight, float height)
	{
		this->fullname = fullname;
		this->age = age;
		this->weight = weight;
		this->height = height;
	}
	void introduce()
	{
		cout << "Hi ! My name is " << fullname << ".\n";
		cout << "How I am " << age << " year old.\n";
	}
	void setAge(int age) 
	{
		this->age = age;
	}
	int getAge()
	{
		return age;
	}
	float getWeight()
	{
		return weight;
	}
	float getHeight()
	{
		return height;
	}
private:
	string fullname;
	int age;
	float weight; // can nang
	float height; // chieu cao
};

class HeathChecker // lop kiem tra suc khoe
{
public:
	void check(Woman* woman) // truyen thong tin cua doi tuong woman vao ham
	{
		weight = woman->getWeight();
		height = woman->getHeight();
		bloodPressure = 130; // getDevice() : thu tu 1 thiet bi nao do
		heartBeat = 80; // getDevice()
	}
	string getResult()
	{
		float bmi = weight / (height * height);
		if (bmi > 18.5 && bmi < 24.9 && bloodPressure >= 120 && bloodPressure < 140 && heartBeat >= 60 && heartBeat < 100)
			return "Normal";
		else
			return "Abnormal";
	}
private:
	float weight; // can nang
	float height; // chieu cao
	int bloodPressure; // huyet ap
	int heartBeat; // nhip tim
};

int main()
{
	Woman* hariwon = new Woman("Hariwon", 35, 60, 1.65);
	HeathChecker* checker = new HeathChecker;
	checker->check(hariwon);
	string result = checker->getResult();
	cout << result << endl;
	return 0;
}