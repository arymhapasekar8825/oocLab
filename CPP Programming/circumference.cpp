// 5) Write a C++ program to calculate the area and circumference of a circle.

#include <iostream>
using namespace std;

int main()
{
    float radius, area, circumference;
    const float PI = 3.14;

    cout << "Enter radius: ";
    cin >> radius;

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    cout << "Area = " << area << endl;
    cout << "Circumference = " << circumference << endl;

    return 0;
}