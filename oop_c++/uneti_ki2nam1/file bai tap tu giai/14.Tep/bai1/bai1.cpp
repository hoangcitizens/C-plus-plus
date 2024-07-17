#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int n;
	fstream f;
	f.open("output.txt",ios::out);
	if (!f)
	{
		cout << "Khong tao duoc tep !" << endl;
		return -1;
	}
	cout << "Nhap n = ";
	cin >> n;
	if (n % 2 == 0)
		f << n << " la so chan" << endl;
	else
		f << n << " la so le" << endl;
	cout <<  "\nDa ghi tep !" << endl;
	return 0;
}

