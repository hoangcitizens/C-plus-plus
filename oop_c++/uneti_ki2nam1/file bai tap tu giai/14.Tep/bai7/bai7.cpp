#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int giaipt(int a, int b, int c)
{	
	ofstream f;
	f.open ("in7.txt", ios::app);
    float delta, x2, x1;
    if (a == 0)
    {
		if (b == 0)
		{
    		if (c == 0)
        		f << "\nPhuong trinh vo so nghiem !" << endl;
    		else
    			f << "\nPhuong trinh vo nghiem !" << endl;
    	}
		else
			f << "\nPhuong trinh co nghiem x = " << (float)-c/b << endl;
    }
    else
	{
	    delta = b*b - 4*a*c;
	    if (delta == 0)	
	        f << "\nPhuong trinh co nghiem kep x1 = x2 = " << -b/(2*a) << endl;   
	    else
			if (delta < 0)
	        	cout << "\nPhuong trinh vo nghiem !" << endl;    
	    else 
		{
	        	f << "\nPhuong trinh có 2 nghiem " << endl;
	        	x1 = (-b+sqrt(delta))/(2*a);
	        	x2 = (-b-sqrt(delta))/(2*a);
	        	f << " Ngiem x1 = " << x1 << endl;
	        	f << " Ngiem x2 = " << x2 << endl; 
	   }
    }
    f.close();   
}
int main()
{
    int a, b, c;
    float delta, x1, x2;
	ifstream f1;
	f1.open("in7.txt");
    if(!f1)
	{
        cout << "Khong mo duoc file!.\n";
        return -1;
    }
   	f1 >> a >> b >> c;
   	f1.close();	
    giaipt(a,b,c);    
    return 0;
}
