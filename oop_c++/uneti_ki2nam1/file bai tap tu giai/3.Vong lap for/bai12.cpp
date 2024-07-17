#include<iostream>
using namespace std;

int main(){
	int n;
    cout<<"Nhap n = "; 
	cin>>n;
    cout<<"Cac so chinh phuong tu 1 den "<<n<<" la : "<<endl;
    for (int i=1; i<=n; i++) {  
        for (int j=1; j<=i; j++){
            if (j*j==i)
                cout<<" "<<i;
        }
    }
	return 0;
}

