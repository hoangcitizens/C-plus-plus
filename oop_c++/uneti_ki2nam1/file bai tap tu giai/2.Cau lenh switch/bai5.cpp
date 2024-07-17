#include<iostream>
#include<math.h>
using namespace std;

int main(){
	unsigned int x, a, b, c;
	do{
		cout << "Nhap vao so nguyen co ba chu so: ";
	    cin >> x;
	    if (x<100 || x>999)
	    	cout << "Loi ! Vui long nhap vao so nguyen co ba chu so !"<<endl;
	} while (x<100 || x>999);
	a = x/100;
	b = (x%100)/10;
	c = x%10;
	switch (a){
		case 1:cout << "Mot tram"; break;
		case 2:cout << "Hai tram"; break;
		case 3:cout << "Ba tram"; break;
		case 4:cout << "Bon tram"; break;
		case 5:cout << "Nam tram"; break;
		case 6:cout << "Sau tram"; break;
		case 7:cout << "Bay tram"; break;
		case 8:cout << "Tam tram"; break;
		case 9:cout << "Chin tram"; break;
	};
	switch (b){
	 	case 0:cout << " linh"; break;
		case 1:cout << " muoi" ; break;
		case 2:cout << " hai muoi"; break;
		case 3:cout << " ba muoi"; break;
		case 4:cout << " bon muoi"; break;
		case 5:cout << " nam muoi"; break;
		case 6:cout << " sau muoi"; break;
		case 7:cout << " bay muoi"; break;
		case 8:cout << " tam muoi"; break;
		case 9:cout << " chin muoi"; break;
	};
	switch (c){
		case 1:cout << " mot"; break;
		case 2:cout << " hai "; break;
		case 3:cout << " ba"; break;
		case 4:cout << " bon"; break;
		case 5:cout << " nam"; break;
		case 6:cout << " sau"; break;
		case 7:cout << " bay"; break;
		case 8:cout << " tam"; break;
		case 9:cout << " chin"; break;
	};
	return 0;
}

