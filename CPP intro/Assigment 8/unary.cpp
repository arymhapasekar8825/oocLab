

#include <iostream>
using namespace std;

class Distance
{
public:
    int feet, inch;

    // Constructor to initialize the object's value
    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
     
    }

    // Overloading (-) operator
    void operator-()
    {
        feet--;
        inch--;

        cout << "\nFeet & Inches (Decrement): "
             << feet << " " << inch <<"\n";

           
    }

     void operator+()
    {
        feet++;
        inch++;

        cout << "\nFeet & Inches (Increase): "
             << feet << " " << inch <<"\n";

           
    }
};

// Driver code
int main()
{
    Distance d1(8, 9);

    // Use unary operator as a single operand
    -d1;
    +d1;
    
    return 0;
}