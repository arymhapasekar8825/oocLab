#include <iostream>
using namespace std;

class Time
{
private:
    int hours, minutes, seconds;

public:
    // Constructor
    Time(int h = 0, int m = 0, int s = 0)
        : hours(h), minutes(m), seconds(s) {}

    // Convert total seconds into HH:MM:SS
    Time convertSeconds(int totalSeconds)
    {
        int h = totalSeconds / 3600;
        totalSeconds = totalSeconds % 3600;

        int m = totalSeconds / 60;
        int s = totalSeconds % 60;

        return Time(h, m, s);
    }

    // Display time
    void display() const
    {
        cout << hours << " hours "
             << minutes << " minutes "
             << seconds << " seconds" << endl;
    }
};

int main()
{
    int totalSeconds;

    cout << "Enter time in seconds: ";
    cin >> totalSeconds;

    Time t;
    Time result = t.convertSeconds(totalSeconds);

    cout << "Converted Time: ";
    result.display();

    return 0;
}
