#include<iostream>
#include<iomanip>
#include<string.h>
#define MAXHS 5
#define MAXLEN 30
using namespace std;

int main()
{
	int count = 0;
	char ds[MAXHS][MAXLEN];
	char *ptr[MAXHS], *tmp;
	while (count < MAXHS)
	{
		cout << "Nhap hoc sinh thu " << count+1 << ": ";
		gets(ds[count]);
		if (strlen(ds[count]) == 0)
			break;
		ptr[count] = ds[count];
		++count;
	}
	for (int i=0; i<count-1; i++)
	{
		for (int j=i+1; j<count; j++)
		{
			if (strcmp(ptr[i],ptr[j])>0)
			{
				tmp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = tmp;
			}
		}
	}
	cout << setw(10) << "Stt" << setw(10) << "Gia tri" << endl;
	for (int i=0; i<count; i++)
		cout << setw(10) << i+1 << setw(10) << ptr[i] << endl;
	return 0;
}

