// 3) Write a C++ program to perform addition, subtraction, multiplication, division and modulus of two numbers using menu driven code (switch case).

#include <iostream>
using namespace std;

int main()
{
    int a, b, choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\n1. Addition";
    cout << "\n2. Subtraction";
    cout << "\n3. Multiplication";
    cout << "\n4. Division";
    cout << "\n5. Modulus";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "Addition = " << a + b;
            break;

        case 2:
            cout << "Subtraction = " << a - b;
            break;

        case 3:
            cout << "Multiplication = " << a * b;
            break;

        case 4:
            cout << "Division = " << a / b;
            break;

        case 5:
            cout << "Modulus = " << a % b;
            break;

        default:
            cout << "Invalid choice";
    }

    return 0;
}