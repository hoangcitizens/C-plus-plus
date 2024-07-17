#include<iostream>
using namespace std;

int main(){
	unsigned int n;
	cout << "Nhap vao so nguyen duong n = ";
	cin >> n;
	cout << "So nguyen to trong pham vi "<<n<<" la : "<<endl;
	for (int i=2; i<=n ;i++){
		int S=0;
		for (int j=1; j<n ;j++){
			if(i%j==0)
				S++;
		}
		if (S==2)
			cout<<"  "<<i;
	}
	return 0;
}

