#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;

public:
    friend istream& operator>>(istream& in, Student& s) {
        in >> s.roll >> s.name;
        return in;
    }

    friend ostream& operator<<(ostream& out, Student& s) {
        out << "Roll Number: " << s.roll << endl;
        out << "Name: " << s.name << endl;
        return out;
    }
};

int main() {
    Student s;

    cout << "Enter roll number and name:\n";
    cin >> s;

    cout << "\nStudent Details:\n";
    cout << s;

    return 0;
}