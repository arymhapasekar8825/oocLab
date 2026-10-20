#include <iostream>
#include <string>
using namespace std;

class Employee
{
    int empId;
    string empName;
    float basicSalary, HRA, DA, grossSalary;

public:
    // Parameterized constructor
    Employee(int id, string name, float salary)
    {
        empId = id;
        empName = name;
        basicSalary = salary;
        HRA = basicSalary * 0.20;
        DA = basicSalary * 0.10;
    }

    // Calculate gross salary
    void calculateSalary()
    {
        grossSalary = basicSalary + HRA + DA;
    }

    // Display employee details
    void display()
    {
        cout << "\nEmployee ID: " << empId;
        cout << "\nEmployee Name: " << empName;
        cout << "\nBasic Salary: " << basicSalary;
        cout << "\nHRA: " << HRA;
        cout << "\nDA: " << DA;
        cout << "\nGross Salary: " << grossSalary << endl;
    }

    // Destructor
    ~Employee()
    {
        cout << "\nEmployee object destroyed." << endl;
    }
};

int main()
{
    Employee e1(101, "Rahul", 20000);

    e1.calculateSalary();
    e1.display();

    return 0;
}