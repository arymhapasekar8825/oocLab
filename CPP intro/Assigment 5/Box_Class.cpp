#include <iostream>
using namespace std;

class Box
{
    float length, breadth, height;

public:
    // Default constructor
    Box()
    {
        length = 1;
        breadth = 1;
        height = 1;
    }

    // Parameterized constructor
    Box(float l, float b, float h)
    {
        length = l;
        breadth = b;
        height = h;
    }

    // Copy constructor
    Box(const Box &obj)
    {
        length = obj.length;
        breadth = obj.breadth;
        height = obj.height;
    }

    // Calculate volume
    float volume()
    {
        return length * breadth * height;
    }

    // Display box information
    void display()
    {
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Height: " << height << endl;
        cout << "Volume: " << volume() << endl;
    }

    // Destructor
    ~Box()
    {
        cout << "Box object destroyed." << endl;
    }
};

int main()
{
    Box b1;
    cout << "Default Box:" << endl;
    b1.display();

    Box b2(2, 3, 4);
    cout << "\nParameterized Box:" << endl;
    b2.display();

    Box b3(b2);
    cout << "\nCopied Box:" << endl;
    b3.display();

    return 0;
}
