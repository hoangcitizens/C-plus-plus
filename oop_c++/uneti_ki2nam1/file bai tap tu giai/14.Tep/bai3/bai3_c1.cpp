#include<iostream>
#include<fstream>
using namespace std;

void ghiSoChan(ofstream &f1)
{
	int dem = 0;
	f1 << "Day so chan tu 1 -> 100 \n";
	for (int a=1; a <= 100; a++)
	{
		if (a%2 == 0)
		{
			dem++;
			f1 << a;
		}
		if (dem % 10 == 0)
			f1 << "\n";
		if (dem % 10 != 0)
			f1 << "\t";
	}
	cout << "Da ghi xong tep";
}

int main()
{
	ofstream f("so_chan.txt");
	if (!f)
	{
		cout << "Khong the tao tep" << endl;
		return -1;
	}
	ghiSoChan(f);
	f.close();
	return 0;
}

