// 10) Write a C++ program to find the largest of three numbers.

#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if(a >= b && a >= c)
        cout << "Largest = " << a;
    else if(b >= a && b >= c)
        cout << "Largest = " << b;
    else
        cout << "Largest = " << c;

    return 0;
}
