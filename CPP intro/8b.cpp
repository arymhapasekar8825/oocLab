// C++ program to show binary operator overloading

#include <iostream>
using namespace std;

class Distance
{
public:
    int feet, inch;

    // Default constructor
    Distance()
    {
        this->feet = 0;
        this->inch = 0;
    }

    // Parameterized constructor
    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }

    // Overloading (+) operator
    Distance operator+(Distance &d2)
    {
        // Create an object to return
        Distance d3;

        d3.feet = this->feet + d2.feet;
        d3.inch = this->inch + d2.inch;
        cout<<d2.feet<<endl;
        cout<<d2.inch;

        // Return the result
        return d3;
    }
};

// Driver code
int main()
{
    Distance d1(8, 9);
    Distance d2(10, 2);
    Distance d3;

    // Use overloaded operator
    d3 = d2 + d1;

    cout << "\nTotal Feet & Inches: "
         << d3.feet << "'" << d3.inch;

    return 0;
}