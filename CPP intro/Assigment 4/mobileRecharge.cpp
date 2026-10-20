#include <iostream>
#include <string>

using namespace std;

class MobileRecharge {
private:
    string mobileNumber;
    string userName;
    double balance;

public:
    // Simple parameterized constructor
    MobileRecharge(string mobNum, string name, double initialBalance) {
        mobileNumber = mobNum;
        userName = name;
        balance = initialBalance;
    }

    // Function to recharge account (add balance)
    void recharge(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            cout << "\nSuccess: Recharged Rs. " << amount << "\n";
            cout << "Updated Balance: Rs. " << balance << "\n";
        } else {
            cout << "\nError: Invalid recharge amount!\n";
        }
    }

    // Function to deduct balance (for calls, data, or SMS)
    void deductBalance(double amount) {
        if (amount <= 0) {
            cout << "\nError: Deduction amount must be greater than zero!\n";
        } else if (amount > balance) {
            cout << "\nError: Insufficient balance! Current balance: Rs. " << balance << "\n";
        } else {
            balance = balance - amount;
            cout << "\nSuccess: Deducted Rs. " << amount << "\n";
            cout << "Remaining Balance: Rs. " << balance << "\n";
        }
    }

    // Function to display account details
    void displayAccountDetails() {
        cout << "\n====================================\n";
        cout << "        MOBILE ACCOUNT DETAILS      \n";
        cout << "====================================\n";
        cout << "Customer Name : " << userName << "\n";
        cout << "Mobile Number : " << mobileNumber << "\n";
        cout << "Current Balance: Rs. " << balance << "\n";
        cout << "====================================\n";
    }
};

int main() {
    string mob, name;
    double initialBal;

    // Taking initial input from user
    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter 10-digit Mobile Number: ";
    getline(cin, mob);

    cout << "Enter Opening Balance (Rs.): ";
    cin >> initialBal;

    // Creating object using simple parameterized constructor
    MobileRecharge account(mob, name, initialBal);

    int choice = 0;
    do {
        cout << "\n=== Mobile Recharge Menu ===";
        cout << "\n1. Display Account Details";
        cout << "\n2. Recharge Account";
        cout << "\n3. Deduct Balance (Call/Data charge)";
        cout << "\n4. Exit";
        cout << "\nEnter choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.displayAccountDetails();
                break;
            case 2: {
                double amt;
                cout << "Enter amount to recharge: Rs. ";
                cin >> amt;
                account.recharge(amt);
                break;
            }
            case 3: {
                double amt;
                cout << "Enter amount to deduct: Rs. ";
                cin >> amt;
                account.deductBalance(amt);
                break;
            }
            case 4:
                cout << "Thank you for using our service!\n";
                break;
            default:
                cout << "Invalid choice! Please select 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}