#include <iostream>
#include <cstdlib>
using namespace std;

class Fraction {
    int numerator, denominator;

public:
    void accept() {
        cout << "Enter numerator and denominator: ";
        cin >> numerator >> denominator;
    }

    void display() {
        int a = abs(numerator);
        int b = abs(denominator);

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        int gcd = (a == 0) ? 1 : a;
        int sign = (denominator < 0) ? -1 : 1;

        cout << (numerator * sign) / gcd
             << "/" << abs(denominator) / gcd << endl;
    }

    Fraction add(Fraction f) {
        Fraction result;
        result.numerator = numerator * f.denominator
                         + f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return result;
    }

    Fraction subtract(Fraction f) {
        Fraction result;
        result.numerator = numerator * f.denominator
                         - f.numerator * denominator;
        result.denominator = denominator * f.denominator;
        return result;
    }
};

int main() {
    Fraction f1, f2, sum, difference;

    cout << "First fraction:\n";
    f1.accept();

    cout << "Second fraction:\n";
    f2.accept();

    sum = f1.add(f2);
    difference = f1.subtract(f2);

    cout << "Addition result: ";
    sum.display();

    cout << "Subtraction result: ";
    difference.display();

    return 0;
}