#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

class Account {
public:
    int accountNumber;
    std::string holderName;
    std::string accountType;
    double balance;

    Account(int accNum, std::string name, std::string type, double bal)
        : accountNumber(accNum), holderName(name), accountType(type), balance(bal) {}
};

class BankManager {
private:
    std::vector<Account> accounts;
    const std::string filename = "bank_records.txt";

    void saveToFile() const {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error writing to bank records file.\n";
            return;
        }
        for (const auto& acc : accounts) {
            outFile << acc.accountNumber << ","
                    << acc.holderName << ","
                    << acc.accountType << ","
                    << acc.balance << "\n";
        }
        outFile.close();
    }

    void loadFromFile() {
        std::ifstream inFile(filename);
        if (!inFile) return;

        accounts.clear();
        std::string line;
        while (std::getline(inFile, line)) {
            if (line.empty()) continue;
            size_t pos = 0;
            std::vector<std::string> tokens;
            while ((pos = line.find(',')) != std::string::npos) {
                tokens.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            tokens.push_back(line);

            if (tokens.size() == 4) {
                int accNum = std::stoi(tokens[0]);
                std::string name = tokens[1];
                std::string type = tokens[2];
                double bal = std::stod(tokens[3]);
                accounts.emplace_back(accNum, name, type, bal);
            }
        }
        inFile.close();
    }

    Account* findAccount(int accNum) {
        for (auto& acc : accounts) {
            if (acc.accountNumber == accNum) {
                return &acc;
            }
        }
        return nullptr;
    }

public:
    BankManager() {
        loadFromFile();
    }

    void openAccount() {
        int accNum;
        std::string name, type;
        double initialDeposit;

        std::cout << "\n--- Open New Account ---\n";
        std::cout << "Enter New Account Number: ";
        std::cin >> accNum;

        if (findAccount(accNum) != nullptr) {
            std::cout << "Error: Account number " << accNum << " already exists.\n";
            return;
        }

        std::cin.ignore();
        std::cout << "Enter Account Holder Name: ";
        std::getline(std::cin, name);

        std::cout << "Enter Account Type (Savings / Current): ";
        std::getline(std::cin, type);

        std::cout << "Enter Initial Deposit: ";
        std::cin >> initialDeposit;

        if (initialDeposit < 0) {
            std::cout << "Error: Initial deposit cannot be negative.\n";
            return;
        }

        accounts.emplace_back(accNum, name, type, initialDeposit);
        saveToFile();
        std::cout << "Account created successfully.\n";
    }

    void depositMoney() {
        int accNum;
        double amount;

        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        Account* acc = findAccount(accNum);
        if (!acc) {
            std::cout << "Account not found.\n";
            return;
        }

        std::cout << "Enter Amount to Deposit: ";
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "Invalid deposit amount.\n";
            return;
        }

        acc->balance += amount;
        saveToFile();
        std::cout << "Deposit successful. New Balance: " 
                  << std::fixed << std::setprecision(2) << acc->balance << "\n";
    }

    void withdrawMoney() {
        int accNum;
        double amount;

        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        Account* acc = findAccount(accNum);
        if (!acc) {
            std::cout << "Account not found.\n";
            return;
        }

        std::cout << "Current Balance: " << std::fixed << std::setprecision(2) << acc->balance << "\n";
        std::cout << "Enter Amount to Withdraw: ";
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "Invalid withdrawal amount.\n";
            return;
        }

        if (amount > acc->balance) {
            std::cout << "Insufficient funds.\n";
            return;
        }

        acc->balance -= amount;
        saveToFile();
        std::cout << "Withdrawal successful. Remaining Balance: " 
                  << std::fixed << std::setprecision(2) << acc->balance << "\n";
    }

    void displayAccountDetails() {
        int accNum;
        std::cout << "\nEnter Account Number: ";
        std::cin >> accNum;

        Account* acc = findAccount(accNum);
        if (!acc) {
            std::cout << "Account not found.\n";
            return;
        }

        std::cout << "\n----------------------------------------\n";
        std::cout << "            ACCOUNT DETAILS             \n";
        std::cout << "----------------------------------------\n";
        std::cout << "Account Number : " << acc->accountNumber << "\n";
        std::cout << "Holder Name    : " << acc->holderName << "\n";
        std::cout << "Account Type   : " << acc->accountType << "\n";
        std::cout << "Balance        : " << std::fixed << std::setprecision(2) << acc->balance << "\n";
        std::cout << "----------------------------------------\n";
    }

    void displayAllAccounts() const {
        std::cout << "\n" << std::string(65, '=') << "\n";
        std::cout << std::left << std::setw(15) << "Account No."
                  << std::setw(25) << "Holder Name"
                  << std::setw(12) << "Type"
                  << std::setw(13) << "Balance" << "\n";
        std::cout << std::string(65, '=') << "\n";

        if (accounts.empty()) {
            std::cout << "No bank records found.\n";
        } else {
            for (const auto& acc : accounts) {
                std::cout << std::left << std::setw(15) << acc.accountNumber
                          << std::setw(25) << acc.holderName
                          << std::setw(12) << acc.accountType
                          << std::fixed << std::setprecision(2) << acc.balance << "\n";
            }
        }
        std::cout << std::string(65, '=') << "\n";
    }

    void closeAccount() {
        int accNum;
        std::cout << "\nEnter Account Number to Close: ";
        std::cin >> accNum;

        for (auto it = accounts.begin(); it != accounts.end(); ++it) {
            if (it->accountNumber == accNum) {
                accounts.erase(it);
                saveToFile();
                std::cout << "Account " << accNum << " closed successfully.\n";
                return;
            }
        }
        std::cout << "Account not found.\n";
    }
};

int main() {
    BankManager bank;
    int choice;

    do {
        std::cout << "\n=========================================\n";
        std::cout << "        BANK MANAGEMENT SYSTEM           \n";
        std::cout << "=========================================\n";
        std::cout << "1. Open New Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Balance / Account Inquiry\n";
        std::cout << "5. Display All Account Holders\n";
        std::cout << "6. Close an Account\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice (1-7): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                bank.openAccount();
                break;
            case 2:
                bank.depositMoney();
                break;
            case 3:
                bank.withdrawMoney();
                break;
            case 4:
                bank.displayAccountDetails();
                break;
            case 5:
                bank.displayAllAccounts();
                break;
            case 6:
                bank.closeAccount();
                break;
            case 7:
                std::cout << "Exiting application.\n";
                break;
            default:
                std::cout << "Invalid choice. Please select an option between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}