#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    float marks;
    string dept;

public:
    void inputDetails()
    {
        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Marks: ";
        cin >> marks;

        cout << "Enter Department Name: ";
        cin >> dept;
    }

    void displayDetails() const
    {
        cout << "\n----- Student Details -----\n";
        cout << "Name    : " << name << endl;
        cout << "Roll No.: " << rollNo << endl;
        cout << "Marks   : " << marks << endl;
         cout << "Department   : " << dept << endl;
    }
};

int main()
{
    Student s;

    s.inputDetails();
    s.displayDetails();

    return 0;
}