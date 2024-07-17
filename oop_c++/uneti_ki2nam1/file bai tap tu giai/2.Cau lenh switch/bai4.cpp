#include<iostream>
using namespace std;

int main(){
	unsigned int x, a, b;
	do{
		cout << "Nhap vao so nguyen co hai chu so: ";
	    cin >> x;
	    if (x<10 || x>90)
	    	cout << "Loi ! Vui long nhap vao so nguyen co hai chu so !"<<endl;
	} while (x<10 || x>90);
	a = x/10;
	b = x%10;
	switch (a){
		case 1:cout << "Muoi" << endl; break;
		case 2:cout << "Hai muoi"; break;
		case 3:cout << "Ba muoi"; break;
		case 4:cout << "Bon muoi"; break;
		case 5:cout << "Nam muoi"; break;
		case 6:cout << "Sau muoi"; break;
		case 7:cout << "Bay muoi"; break;
		case 8:cout << "Tam muoi"; break;
		case 9:cout << "Chin muoi"; break;
	};
	switch (b){
		case 1:cout << " mot" << endl; break;
		case 2:cout << " hai " << endl; break;
		case 3:cout << " ba" << endl; break;
		case 4:cout << " bon" << endl; break;
		case 5:cout << " nam" << endl; break;
		case 6:cout << " sau" << endl; break;
		case 7:cout << " bay" << endl; break;
		case 8:cout << " tam" << endl; break;
		case 9:cout << " chin" << endl; break;
	};
	return 0;
}

