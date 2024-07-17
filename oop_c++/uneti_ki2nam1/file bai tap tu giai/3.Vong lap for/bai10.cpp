#include<iostream>
using namespace std;

int main(){
	unsigned int h;
	cout << "Nhap vao so nguyen duong h = ";
	cin >> h;
	for (int i=h; i<=h ;i--){
		for (int j=1; j<=i ;j++)
			cout <<"* ";
		cout << endl;
	}
	return 0;
}

