#include<iostream>
#include<string>
using namespace std;

/*
class Woman
{
public:
	string fullname;
	int age;
	/*
	void introduce(string language, bool isFull = true) // truyen tham so mac dinh
	// function <=> method (ham thanh vien <=> phuong thuc)
	// tham so mac dinh phai de o phia sau
	{
		if (language == "Vietnam")
		{
			cout << "Xin chao ! Toi la phu nu" << endl;
			if (isFull)
			{
				cout << "Toi rat xinh dep" << endl;
			}
		}
		else
		{
			cout << "Hi ! I am Woman" << endl;
			if (isFull)
			{
				cout << "I am very beautiful" << endl;
			}
		}
	}
	// function co kieu tra ve
string introduce(string language, bool isFull = true)
{
	string msg; // bien ket qua
	if (language == "Vietnam")
	{
		msg = "Xin chao ! Toi la phu nu\n";
		if (isFull)
		{
			msg += "Toi rat xinh dep";
		}
	}
	else
	{
		msg = "Hi ! I am Woman\n";
		if (isFull)
		{
			msg += "I am very beautiful";
		}
	}
	return msg;
}
private:
	int weight;
}; 
*/

class Message // object nho dung struct
{
public:
	string content;
	string sender;
};

class Woman
{
public:
	string fullname;
	int age;
	Message* introduce(string language, bool isFull = true)
	{
		Message *msg = new Message;
		if (language == "Vietnam")
		{
			msg->content = "Xin chao ! Toi la phu nu\n";
			if (isFull)
			{
				msg->content += "Toi rat xinh dep";
			}
		}
		else
		{
			msg->content = "Hi ! I am Woman\n";
			if (isFull)
			{
				msg->content += "I am very beautiful";
			}
		}
		return msg;
	}

	// overloading : nap chong ham (dinh nghia nhieu ham co cung ten nhung ham khac tham so truyen vao)
	Message* introduce(int count)
	{
		Message* msg = new Message;
		for (int i = 0; i < count; i++)
		{
			msg->content += "Hello" + to_string(i) /*chuyen 1 so nguyen thanh chuoi*/ + "\n";

		}
		return msg;
	}
private:
	int weight;
};
int main()
{
	Woman* hariwon = new Woman;
	// hariwon->introduce("Vietnam"); // loi goi ham kieu void
	// string msg = hariwon->introduce("English"); // tao bien de hung lay gia tri cua ham  
	//cout << msg << endl;
	Message* msg = hariwon->introduce("Vietnam"); // de nhan biet dua vao tham so truyen vao
	cout << msg->content << endl;
	return 0;
}