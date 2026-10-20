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
        cout<<"i am from operator"<<d2.feet <<" "<<d2.inch;
        // Create an object to return
        Distance d3;

        d3.feet = this->feet + d2.feet;
        d3.inch = this->inch + d2.inch;



        // Return the result
        return d3;
    }


        Distance operator-(Distance &d2)
    {
        cout<<"i am from operator"<<d2.feet <<" "<<d2.inch;
        // Create an object to return
        Distance d4;

        d4.feet = this->feet - d4.feet;
        d4.inch = this->inch - d4.inch;



        // Return the result
        return d4;
};

// Driver code
int main()
{
    Distance d1(8, 9);
    Distance d2(10, 2);
    Distance d3;
    Distance d4;

    // Use overloaded operator
    d3 = d1 + d2;
    d4 =d1 - d2;
   

    cout << "\nTotal Feet & Inches: "
         << d3.feet << "'" << d3.inch<<"\n";

    cout << "\nTotal Feet & Inches: "
         << d4.feet << "'" << d4.inch<<"\n";     

   

    return 0;
}