#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream outfile("records.txt", ios::app);

    if (!outfile) {
        cout << "Unable to open file!";
        return 1;
    }

    string name;
    int n;

    cout << "Enter number of records: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Enter name: ";
        getline(cin, name);
        outfile << name << endl;
    }

    outfile.close();

    ifstream infile("records.txt");

    if (!infile) {
        cout << "Unable to read file!";
        return 1;
    }

    string line;
    cout << "\nAll Records:\n";

    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close();

    return 0;
}