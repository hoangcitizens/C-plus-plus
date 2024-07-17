#include<iostream>
using namespace std;

int main(){
	float n, S=0;
	int dem=0, demSoAm=0;
	do{
		cout << "Nhap vao mot so thuc : ";
		cin >> n;
		if (n!=0){
			S+=n;
			dem++;
		}
		if (n<0)
			demSoAm++;
	} while(n!=0);
	cout << "Tong cac phan tu da nhap la S = "<<S/dem<<endl;
	cout << "So phan tu am la : "<<demSoAm<<endl;
	return 0;
}

