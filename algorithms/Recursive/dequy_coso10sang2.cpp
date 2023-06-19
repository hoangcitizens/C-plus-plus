#include <iostream>
using namespace std;

void decToBinary(int n) 
{
    if (n > 1) {
        decToBinary(n / 2);
    }
    cout << n % 2;
}

int main() 
{
    int n;
    cout << "Nhap so can chuyen sang co so 2: "; cin >> n;
    cout << "So " << n << " trong co so 2 la: ";
    decToBinary(n);
    cout << endl;
    return 0;
}