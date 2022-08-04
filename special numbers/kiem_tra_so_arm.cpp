#include<iostream>
#include<math.h>
using namespace std;

/*So armstrong la so co tong luy thua bac n cua cac chu so cua no
 bang chinh no. VD: 371 = 3^3 + 7^3 + 1^3 = 27 + 343 + 1 = 371*/
 
 int count_digit(int n) // ham dem so luong chu so cua 1 so
 {
 	int count = 0; // count la bien dem
 	while (n > 0)
 	{
 		n /= 10; // moi lan chia cho 10 n mat di mot chu so
 		++count; // bien dem tang len sau moi lan mat mot chu so
	}
	return count;
 }
bool kiem_tra_so_arm(int n)
{
	int num_digit = count_digit(n); // num_digit la so luong chu so
	int tmp = n, sum = 0, last; // tmp: bien tam thoi
	while (tmp > 0)
	{
		last = tmp % 10; // last chia lay phan du (lay chu so cuoi cung cua mot so)
		tmp /= 10; // bo chu so cuoi cung di
		sum += pow(last,num_digit); // pow ham binh phuong
	}
	if (sum == n)
		return true;
	return false;
}
int main()
{
	int n;
	cout << "Nhap so can kiem tra: ";
	cin >> n;
	if (kiem_tra_so_arm(n))
		cout << "So " << n << " la so Armstrong !" << endl;
	else
		cout << "So " << n << " khong la so Armstrong !" << endl;
	return 0;
}

