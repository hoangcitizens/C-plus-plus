#include<iostream>
#include<math.h>
using namespace std;

template <class T>
class Stack 
{
public:
    Stack(int size) 
    {
        this->size = size;
        data = new T[size];
        top = -1;
    }
    ~Stack() {}
    // them mot phan tu vao dau stack
    void push(T value) 
    {
        if (top == size - 1) {
            cout << "Stack day" << endl;
            return;
        }
        top++;
        data[top] = value;
    }
    // xoa phan tu dau tien trong stack va tra ve gia tri cho no
    T pop() 
    { 
        if (top == -1) 
        {
            cout << "Stack rong" << endl;
            return 0;
        }
        T value = data[top];
        top--;
        return value;
    }
private:
    T* data;
    int size;
    int top; // chi so cua phan tu dau tien trong stack
};

int main()
{
    Stack<int> intStack(5); 
    // Them cac phan tu vao stack bang phuong thuc push
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    // Lay phan tu dau tien cua stack bang phuong thuc pop
    int a = intStack.pop();
    cout << "Phan tu dau tien cua stack: " << a << endl;
    
    // Them phan tu moi va lay phan tu tiep theo
    intStack.push(40);
    int b = intStack.pop();
    cout << "Phan tu moi sau khi them: " << b << endl;
    
    // Lay cac phan tu con lai trong stack
    int c = intStack.pop();
    cout << "Phan tu con lai trong stack: " << c << endl;
    int d = intStack.pop();
    cout << "Phan tu con lai trong stack: " << d << endl;
    
    // Them phan tu moi vao stack da rong
    intStack.push(50);
    
    // Lay phan tu cuoi cung trong stack
    int e = intStack.pop();
    cout << "Phan tu cuoi stack sau khi them: " << e << endl;
    return 0;
}