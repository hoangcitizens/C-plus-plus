#include<iostream>
using namespace std;

int main(){
   unsigned int chiSo;
   cout << "Nhap chi so tieu thu dien: ";
   cin >> chiSo;
   float giaTien;
   if (chiSo < 100 || chiSo == 100)
   	    giaTien = chiSo*500;
   else 
        giaTien = 100*500+(chiSo-100)*800;
    cout << "Chi so tieu thu dien la : "<<chiSo<<" kW";     
    cout << "\nGia tien dien la: "<<giaTien;
   return 0;
}

