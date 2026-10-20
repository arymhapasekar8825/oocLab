#include <iostream> 
using namespace std;

// Base class named Shape
class Vehical { 
public: 
    // Pure virtual function to calculate the area
    virtual void start() const = 0; 

    // Pure virtual function to calculate the perimeter
    virtual void stop() const = 0;
}; 

// Derived class named Circle inheriting from Shape
class Car : public Vehical { 
 

public: 
 
    void start() const override { 
        cout<<"Car Starts"<<endl; 
    } 
    void stop() const override { 
        cout<<"Car Stop"<<endl; 
    } 

}; 
class Bike : public Vehical { 
 

public: 
 
    void start() const override { 
        cout<<"Bike Starts"<<endl; 
    } 
    void stop() const override { 
        cout<<"Bike Stop"<<endl; 
    } 

}; 
int main(){

    Car c1;
    Bike b1;

    c1.start();
    c1.stop();

    b1.start();
    b1.stop();

    return 0;
}