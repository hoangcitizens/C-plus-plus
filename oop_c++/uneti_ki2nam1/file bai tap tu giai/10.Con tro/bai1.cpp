#include<iostream>
using namespace std;

int main()
{
	int a = 15; // khai bao bien nguyen 
	int *p;     // bien con tro p
	p = &a;
	// luu tru dia chi cua a vao bien con tro p
	cout << "Gia tri cua bien a la : "<<a<<endl;
	// In dia chi duoc luu tru trong bien con tro p
	cout << "Dia chi luu tru trong bien con tro p la: ";
	cout << p << endl;
	cout << "Gia tri cua con tro P la: "<<*p<<endl;
	return 0;
}

