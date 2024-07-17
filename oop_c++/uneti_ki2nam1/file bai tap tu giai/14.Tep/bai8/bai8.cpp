#include<iostream>
#include<fstream>
using namespace std;

void doctep(int &x, int &y, int &z)
{    
	fstream f("in8.txt",ios::in); 
	f >> x >> y >> z;	
	f.close();
}

int main()
{ 
	int a, b, c;
	doctep(a,b,c);
	fstream f("out8.txt",ios::out);
	if ((a+b>c) && (b+c>a) && (a+c>b))
    {	
		f << "Day la 3 canh tam giac !" << endl;
    	if(a==b && b==c)
    		f << "Do la tam giac deu !" << endl;
   		else
   			if(a==b || b==c || c==a)
   				f << "Do la tam giac can !" << endl;
			else
				if(a*a + b*b==c*c || b*b + c*c == a*a|| a*a + c*c == b*b)
					f << "Do la tam giac vuong !" << endl;
				else
					f << "Do la tam giac thuong !" << endl;
	}
	else
   		f << "Khong tao thanh tam giac !" << endl;
	f.close();
	return 0;
}
