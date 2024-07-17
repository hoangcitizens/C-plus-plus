#include<iostream>
#include<iomanip>
#define max 50

using namespace std;

void input(int a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << "Nhap a["<<i<<"]["<<j<<"] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void output(int a[max][max], int n, int m)
{
	
	for(int i=0; i<m; i++)
	{
		cout << "\t";
		for(int j=0; j<n; j++)
			cout << left << setw(6) << a[i][j];
		cout << endl;
	}	
}

int main()
{
	int n, m, p, q, a[max][max], b[max][max], c[max][max];
	cout << "Nhap so hang cua ma tran A: "; cin >> m;
	cout << "Nhap so cot cua ma tran A: "; cin >> n;
	input(a,n,m);
	cout << "Ma tran A: "<<endl;
	output(a,n,m);
	cout << "Nhap so hang cua ma tran B: "; cin >> q;
	cout << "Nhap so cot cua ma tran B: "; cin >> p;
	input(b,p,q);
	cout << "Ma tran B: "<<endl;
	output(b,p,q);
	cout << "Tich hai ma tran AxB la: "<<endl;
	if (n == q)
	{
		for(int i=0; i<m; i++)
        {
        	cout << "\t";
            for(int j=0; j<q; j++)
            {
            	c[i][j] = 0;
                for(int k=0; k<n; k++)
                    c[i][j] += (a[i][k]*b[k][j]);
                cout<< left << setw(6) << c[i][j];
            }
            cout<<endl;
        }
	}
	else
		cout << "Khong the nhan hai ma tran vi so cot ma tran A khac so hang ma tran B"<<endl;
	return 0;
}

