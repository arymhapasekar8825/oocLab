
#include <iostream>
using namespace std;

class Database {
public:
    static int connectionCount;
    
    // This function acts like a "static block"
    static int init() {
        cout << "Static block running: Connecting to DB..." << endl;
        return 0; // setup code here
    }
};

// Call init() during static initialization
int Database::connectionCount = Database::init(); 

int main() {
    cout << "Main starts" << endl;
}