#include <iostream>
using namespace std;

class Employee
{
    int empID;
    string empName, department;
    float basicSalary;

public:
    void acceptDetails()
    {
        cout << "Enter Employee ID: ";
        cin >> empID;

        cout << "Enter Employee Name: ";
        cin >> empName;

        cout << "Enter Department: ";
        cin >> department;

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }

    void displayDetails()
    {
        cout << "\n--- Employee Information ---" << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Department: " << department << endl;
        cout << "Basic Salary: " << basicSalary << endl;
    }

    void calculateAnnualSalary()
    {
        cout << "Annual Salary: " << basicSalary * 12 << endl;
    }
};

int main()
{
    Employee e;

    e.acceptDetails();
    e.displayDetails();
    e.calculateAnnualSalary();

    return 0;
}