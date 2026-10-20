#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    int hours, minutes, seconds;

public:
    void accept() {
        cout << "Enter hours, minutes and seconds: ";
        cin >> hours >> minutes >> seconds;
    }

    Time add(Time t) {
        Time result;

        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes
                       + result.seconds / 60;
        result.seconds %= 60;

        result.hours = hours + t.hours
                     + result.minutes / 60;
        result.minutes %= 60;

        return result;
    }

    void display() {
        cout << setfill('0')
             << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << endl;
    }
};

int main() {
    Time t1, t2, result;

    cout << "First time:\n";
    t1.accept();

    cout << "Second time:\n";
    t2.accept();

    result = t1.add(t2);

    cout << "Resultant time: ";
    result.display();

    return 0;
}