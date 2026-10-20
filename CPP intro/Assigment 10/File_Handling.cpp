#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Create ofstream object to write into file
    ofstream fout;
    string line;

    // Open file in output mode
    fout.open("sample.txt");

    // Write content into file
    while (fout)
    {
        getline(cin, line);

        // Enter -1 to stop writing
        if (line == "-1")
            break;

        fout << line << endl;
    }

    // Close the file
    fout.close();

    // Create ifstream object to read the file
    ifstream fin;
    fin.open("sample.txt");

    // Read and display file content
    while (getline(fin, line))
    {
        cout << line << endl;
    }

    // Close the file
    fin.close();

    return 0;
}