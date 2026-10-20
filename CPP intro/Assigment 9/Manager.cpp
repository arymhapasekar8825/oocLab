#include <iostream>
using namespace std;

class Employee {
protected:
    double salary;

public:
    Employee(double s) {
        salary = s;
    }

    virtual double calculateBonus() {
        return 0;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    Manager(double s) : Employee(s) {}

    double calculateBonus() override {
        return salary * 0.20;
    }
};

class Developer : public Employee {
public:
    Developer(double s) : Employee(s) {}

    double calculateBonus() override {
        return salary * 0.10;
    }
};

int main() {
    Manager m(50000);
    Developer d(40000);

    Employee* e;

    e = &m;
    cout << "Manager Bonus: " << e->calculateBonus() << endl;

    e = &d;
    cout << "Developer Bonus: " << e->calculateBonus() << endl;

    return 0;
}
