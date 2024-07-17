#include<iostream>
using namespace std;

int main()
{
	int i, j; // khai bao 2 bien nguyen i, j
	int *p, *q; // khai bao 2 con tro nguyenp, q
	p = &i; // cho p tro toi i
	q = &j; // cho q tro toi j
	cout << "Dia chi bien i la: "<<&i<<endl;
	cout << "Dia chi bien J la: "<<q<<endl; // dung q hoac &j de lay dia chi
	i = 2; // gan i bang 2
	*q = 5; // gan j bang 5 (thong qua q)
	i++;
	cout << "i = "<<i<<endl; // tang i va in i = 3
	(*q)++;
	cout << "j = "<<j<<endl; // tang j vain j = 6
	(*p) = (*q) * 2 + 1; // gan lai i thong qua p
	cout << "i = "<<i<<endl; // in ra i = 13
	return 0;
}

