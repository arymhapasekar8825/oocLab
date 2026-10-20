#include <iostream>
using namespace std;

int main() {
    int choice;
    double a, b;

    do {
        cout << "\n--- Calculator Menu ---" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        switch (choice) {
            case 1:
                cout << "Result = " << a + b << endl;
                break;

            case 2:
                cout << "Result = " << a - b << endl;
                break;

            case 3:
                cout << "Result = " << a * b << endl;
                break;

            case 4:
                if (b != 0)
                    cout << "Result = " << a / b << endl;
                else
                    cout << "Division by zero is not allowed!"
                         << endl;
                break;

            case 5:
                if (b != 0)
                    cout << "Result = "
                         << static_cast<int>(a) %
                            static_cast<int>(b) << endl;
                else
                    cout << "Modulus by zero is not allowed!"
                         << endl;
                break;

            case 6:
                cout << "Exiting calculator..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}