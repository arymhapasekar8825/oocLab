#include <iostream>
#include <string>

using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string department;
    double consultationFee;
    double labFee;
    double medicineFee;

    // Simple constructor
    Patient(int pId, string pName, int pAge, string pDept, double cFee, double lFee, double mFee) {
        id = pId;
        name = pName;
        age = pAge;
        department = pDept;
        consultationFee = cFee;
        labFee = lFee;
        medicineFee = mFee;
    }

    // Function to calculate total charge
    double calculateTotal() {
        return consultationFee + labFee + medicineFee;
    }

    // Function to print details
    void display() {
        cout << "\n--- Patient Bill Details ---\n";
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Department: " << department << "\n";
        cout << "Consultation Fee: " << consultationFee << "\n";
        cout << "Lab Fee: " << labFee << "\n";
        cout << "Medicine Fee: " << medicineFee << "\n";
        cout << "Total Payable: " << calculateTotal() << "\n";
    }
};

int main() {
    int id, age;
    string name, dept;
    double cFee, lFee, mFee;

    // Take user input
    cout << "Enter Patient ID: ";
    cin >> id;

    cin.ignore(); // Clears enter key
    cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();
    cout << "Enter Department: ";
    getline(cin, dept);

    cout << "Enter Consultation Fee: ";
    cin >> cFee;

    cout << "Enter Lab Fee: ";
    cin >> lFee;

    cout << "Enter Medicine Fee: ";
    cin >> mFee;

    // Create object and display
    Patient p1(id, name, age, dept, cFee, lFee, mFee);
    p1.display();

    return 0;
}