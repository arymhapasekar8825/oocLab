

#include <iostream>
using namespace std;

// Base class
class Vehicle
{
public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

// First subclass
class Car : public Vehicle
{
public:
    Car()
    {
        cout << "This Vehicle is Car" << endl;
    }
};

// Second subclass
class Bus : public Vehicle
{
public:
    Bus()
    {
        cout << "This Vehicle is Bus" << endl;
    }
};

// Main function
int main()
{
    // Creating objects of subclasses
    Car obj1;
    Bus obj2;

    return 0;
}