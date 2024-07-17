#include<iostream>
#include<math.h>
using namespace std;

int main(){
	// T : diem Toan , L : diem Ly , H : diem Hoa , dTB : diem trung binh
	float T, L, H, dTB;
    cout << "Nhap diem Toan : ";
    cin >> T;
    cout << "Nhap diem Ly : ";
    cin >> L;
    cout << "Nhap diem Hoa : ";
    cin >> H;
    dTB = (T+L+H)/3;
    
    if ( 0 <= T && T <= 10 && 0 <= L && L <= 10 && 0 <= H && H <= 10 ){
        if ( dTB >= 9)
            cout << "Diem trung binh la : "<<dTB<<"\n=>Xep loai Xuat sac "<<endl;
        else 
			if ( 8 <= dTB && dTB < 9)
            	cout << "Diem trung binh la : "<<dTB<<"\n=> Xep loai Gioi "<<endl;
        else 
			if ( 6.5 <= dTB && dTB < 8)
            	cout << "Diem trung binh la : "<<dTB<<"\n=> Xep loai Kha "<<endl;
        else 
			if ( 5 <= dTB && dTB< 6.5)
            	cout << "Diem trung binh la : "<<dTB<<"\n=> Xep loai Trung Binh "<<endl;
        else 
            cout << "Diem trung binh la : "<<dTB<<"\n=> Xep loai Yeu "<<endl;
    }
    else 
        cout << "\aVui long nhap 0 <= diem <= 10 "<<endl;

    return 0;
}

