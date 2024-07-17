#include<iostream>
#include<fstream>
using namespace std;

void ghiSoLe(ofstream &file)
{
	int dem = 0;
	file << "Day so le tu 1 -> 100 \n";
	for(int a = 1; a <= 100; a++)
	{
		if(a%2 != 0)
		{
			dem ++;
			file << a;
		} 
		if(dem % 10 == 0)
			file << "\n";
		if(dem % 10 != 0)
			file << "\t";
	}
	cout << "Da ghi tep" << endl;;
}

int main()
{
	ofstream f("so_le.txt");
	if(!f)
	{ 
		cout<<"Khong the mo tep";
		return -1;
	}
	ghiSoLe(f);
	f.close();
	return 0;
}

