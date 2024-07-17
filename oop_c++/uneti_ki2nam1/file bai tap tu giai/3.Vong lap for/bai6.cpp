#include<iostream>
using namespace std;

int main(){
	unsigned int n;
	cout << "Nhap vao so nguyen duong n = ";
	cin >> n;
	cout << "Cac so hoan hao trong pham vi "<<n<<" la : ";
	for (int i=1; i<=n ; i++){
		int S=0;
		for (int j=1; j<i ; j++){
			if (i%j==0)
				S += j;
		}
		if (S==i)
			cout << i << "  ";
	}
	return 0;
}

