#include <iostream> 
#include <fstream> 
using namespace std;

void doctep(char tentep[], int &x, int &y, int &z)    
{ 
	fstream f(tentep,ios::in);
   	if(!f)		
  	{	
	  	cout << "Khong the mo duoc tep tin !" << f << endl;
		exit(1);
   	}
    f >> x >> y >> z;	
    f.close();
}
int max(int a, int b, int c)
{	
	int m = a;
	if (m < b)
		m = b;
	if (m < c)
		m = c;	   
    return m;
}
int min(int a, int b, int c)
{
	int m = a;
	if (m > b)
		m = b;
	if (m > c)
		m = c;	   
    return m;
}
void ghitep(char tentep[], int &x, int &y, int &z)
{
    fstream f1(tentep,ios::out);
    if(!f1)			
    { 	
		cout << " Khong tao duoc tep !" << f1 << endl;		
	 	exit(1);
    }
    f1 << "\n" << "So lon nhat trong 3 so la: " << max(x, y, z);   //ghi vao tep
    f1 << "\n" << "So nho nhat trong 3 so la: " << min(x, y, z);   //ghi vao tep
    cout << "=> Da ghi xong tep !" << endl;
}

int main() 
{ 
	char f[30];			  
  	int a, b, c;
  	cout << "Nhap ten tep doc du lieu: "; cin.getline(f,30);
  	doctep(f, a, b, c);
  	cout << "Nhap ten tep ghi du lieu: "; cin.getline(f,30);
  	ghitep(f, a, b, c); 	
  	return 0;
}
