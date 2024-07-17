#include <iostream>
#include <string.h> 
using namespace std;

void tanSuat(char a[])	
{	
	int n = strlen(a);
	for(int i=0; i<n; i++)
	{	
		int kt = 1;		
		for(int j=i-1; j>0; j--)
		{
		
			if(a[i] == a[j])
			{	
				kt = 0;	
				break;
			}
		}
		if(kt == 1)
		{	
			int count = 0;
			for(int k=0; k<n; k++)
			{
				if(a[i] == a[k])
					count++;
			}
			cout<<"Ky tu "<<a[i]<<" xuat hien "<<count<<" lan"<<endl;	
		}
	}	
}	
int main()
{	
	char s[50];
	cout<<"Nhap vao mot xau: "; 
	cin.getline(s,50);
	tanSuat(s);
	return 0;
}
