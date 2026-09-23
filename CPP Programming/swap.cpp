// 6) Write a C++ program to swap two numbers using third variable.

#include <iostream>
using namespace std;

int main()
{
    int a, b, temp;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    temp = a;
    a = b;
    b = temp;

    cout << "After swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b;

    return 0;
}