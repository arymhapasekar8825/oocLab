// 4) Write a C++ program to calculate the area and perimeter of a rectangle.

#include <iostream>
using namespace std;

int main()
{
    float length, breadth, area, perimeter;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter breadth: ";
    cin >> breadth;

    area = length * breadth;
    perimeter = 2 * (length + breadth);

    cout << "Area = " << area << endl;
    cout << "Perimeter = " << perimeter;

    return 0;
}