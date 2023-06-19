/*
	Voi n = 1: Chuyen dia tu A -> C
	Voi n > 1: Chuyen n-1 tu A -> B
			   Chuyen dia cuoi tu A -> C
			   Chuyen n-1 dia tu B -> C
*/

#include<iostream>
using namespace std;

void hanoi(int n, char A, char C, char B)
{
	if (n == 1)
	{
		cout << "Chuyen dia tu cot " << A << " sang cot " << C << endl;
		return;
	}
	hanoi(n - 1, A, B, C);
	cout << "Chuyen dia tu cot " << A << " sang cot " << C << endl;
	hanoi(n - 1, B, C, A);
}

int main()
{
	int n;
	cout << "Nhap so dia trong thap: "; cin >> n;
	hanoi(n, 'A', 'C', 'B');
	return 0;
}