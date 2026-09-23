// 9) Write a C++ program to find largest of two numbers using an if-else statement.

#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    if(a > b)
        cout << "Largest = " << a;
    else
        cout << "Largest = " << b;

    return 0;
}