#include <iostream>
using namespace std;

class Product
{
    int productID, quantity;
    string productName;
    float unitPrice;

public:
    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productID;

        cout << "Enter Product Name: ";
        cin >> productName;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Unit Price: ";
        cin >> unitPrice;
    }

    void calculateTotalCost()
    {
        cout << "Total Cost: " << quantity * unitPrice << endl;
    }

    void displayDetails()
    {
        cout << "\n--- Product Information ---" << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Unit Price: " << unitPrice << endl;
    }
};

int main()
{
    Product p;

    p.acceptDetails();
    p.displayDetails();
    p.calculateTotalCost();

    return 0;
}