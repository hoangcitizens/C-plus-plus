#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int dem = 0;
	fstream f("so_chan2.txt",ios::out);
	if (!f)
	{
		cout << "Khong the mo tep" << endl;
		return -1;
	}
	f << "Day so chan tu 1 -> 100 \n";
	for (int a=1; a<=100; a++)
	{
		if (a%2 == 0)
		{
			dem++;
			f << a;
		}
		if (dem % 10 == 0)
			f << "\n";
		if (dem % 10 != 0)
			f << "\t";
	}
	f.close();
	return 0;
}

