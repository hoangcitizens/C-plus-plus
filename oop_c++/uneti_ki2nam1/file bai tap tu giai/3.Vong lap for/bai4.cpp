#include<iostream>
using namespace std;

int main(){
	int x, y;
	cout << "Nhap chieu rong : ";
	cin >> x;
	cout << "Nhap chieu dai : ";
	cin >> y;
	if (x>0 && y>0){
		for (int i=1; i<=x ; i++){
			for (int j=1; j<=y ; j++)
				cout << "* ";
		cout << endl;		
		}
	}
	else
		cout << "Vui long nhap vao chieu dai va chieu rong la so duong !"<<endl;
	return 0;
}

