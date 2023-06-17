#include<iostream>
#include<math.h>
using namespace std;

template <class T>
class Array
{
public:
    Array(int n)
    {
        this->n = n;
        a = new T[n];
    }
    ~Array(){}
    void import()
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap a[" << i <<"] = "; cin >> a[i];
        }
    }
    void display()
    {
        cout << "(*) Mang vua nhap: ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ; ";
        }
        cout << endl;
    }
    void sum()
    {
        T S = 0;
        for (int i = 0; i < n; i++)
        {
            S += a[i];
        }
        cout << "(*) Tong cac phan tu trong mang: " << S << endl;
    }
    void arrange()
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] > a[j])
					swap(a[i], a[j]);
			}
		}
		cout << "(*) Mang sau sap xep tang dan: ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ; ";
        }
        cout << endl;
	}
    void findMax()
    {
        T max = a[0];
        for (int i = 0; i < n; i++)
        {
            if (max < a[i])
                max = a[i];
        }
        cout << "(*) Phan tu lon nhat trong mang la : " << max << endl;
    }
    void findMin()
    {
        T min = a[0];
        for (int i = 0; i < n; i++)
        {
            if (min > a[i])
                min = a[i];
        }
        cout << "(*) Phan tu nho nhat trong mang la : " << min << endl;
    }
    // tinh tong trung binh cac phan tu
    void sumS()
    {
        T S = 0;
        for (int i = 0; i < n; i++)
        {
            S += a[i];
        }
        cout << "(*) Trung binh tong cua " << n << " phan tu trong mang: " << S/n << endl;
    }
    // kiem tra so nguyen to
    bool isPrime(T x)
    { 
        if (x < 2) 
            return false;
        for (int i = 2; i <= sqrt(x); i++) 
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    void prime()
    {
        cout << "(*) Phan tu la so nguyen to trong mang la: ";
        for (int i = 0; i < n; i++) 
        {
            if (isPrime(a[i]) == true)
            {
                cout << a[i] << " ; ";
            }
        }
        cout << endl;
    }
    bool isSymmetric(T arr[]) 
    {
        for (int i = 0; i < n / 2; i++) 
        {
            if (arr[i] != arr[n - i - 1])
                return false;
        }
        return true;
    }
    void symmetric()
    {
        if (isSymmetric(a) == true) 
            cout << "(*) Mang doi xung !" << endl;
        else 
            cout << "(*) Mang khong doi xung !" << endl;
    }
private:
    T *a;
    int n;
};

int main()
{
    int n; cout << "Nhap so phan tu cua mang: "; cin >> n;
    Array <int> a(n);
    a.import();
    a.display();
    a.sum();
    a.arrange();
    a.findMax();
    a.findMin();
    a.sumS();
    a.prime();
    a.symmetric();
    return 0;
}