#include <iostream> 
#include <cmath>    

const double PI = 3.14159; 

// Base class named Shape
class Shape { 
public: 
    // Pure virtual function to calculate the area
    virtual double calculateArea() const = 0; 

    // Pure virtual function to calculate the perimeter
    virtual double calculatePerimeter() const{
        return 2*PI;
    }
}; 

// Derived class named Circle inheriting from Shape
class Circle : public Shape { 
private: 
    double radius; 

public: 
    // Constructor for Circle class
    Circle(double rad) : radius(rad) {} 

    // Override the virtual member function to calculate the area
    double calculateArea() const override { 
        return PI * pow(radius, 2); 
    } 

    // Override the virtual member function to calculate the perimeter
 /*   double calculatePerimeter() const override { 
        return 2 * PI * radius; 
    } */
}; 

// Derived class named Rectangle inheriting from Shape
class Rectangle : public Shape { 
private: 
    double length; 
    double width;  

public: 
    // Constructor for Rectangle class
    Rectangle(double len, double wid) : length(len), width(wid) {} 

    // Override the virtual member function to calculate the area
    double calculateArea() const override { 
        return length * width; 
    } 

    // Override the virtual member function to calculate the perimeter
    double calculatePerimeter() const override { 
        return 2 * (length + width); 
    } 
}; 

// Derived class named Triangle inheriting from Shape
class Triangle : public Shape { 
private: 
    double side1; 
    double side2; 
    double side3; 

public: 
    // Constructor for Triangle class
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {} 

    // Override the virtual member function to calculate the area using Heron's formula
    double calculateArea() const override { 
        double s = (side1 + side2 + side3) / 2; 
        return sqrt(s * (s - side1) * (s - side2) * (s - side3)); 
    } 

    // Override the virtual member function to calculate the perimeter
    double calculatePerimeter() const override { 
        return side1 + side2 + side3; 
    } 
}; 

int main() { 
    // Create instances of different shapes
    
    Circle circle(7.0); 
    Rectangle rectangle(4.2, 8.0); 
    Triangle triangle(4.0, 4.0, 3.2); 

    // Calculate and display the area and perimeter of each shape 
    std::cout << "Circle: " << std::endl; 
    std::cout << "Area: " << circle.calculateArea() << std::endl; 
    std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl; 

    std::cout << "\nRectangle: " << std::endl; 
    std::cout << "Area: " << rectangle.calculateArea() << std::endl; 
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl; 

    std::cout << "\nTriangle: " << std::endl; 
    std::cout << "Area: " << triangle.calculateArea() << std::endl; 
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl; 

    return 0; 
}
