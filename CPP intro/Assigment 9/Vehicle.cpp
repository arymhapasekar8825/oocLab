#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void start() = 0;
    virtual void stop() = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Car is starting." << endl;
    }

    void stop() override {
        cout << "Car is stopping." << endl;
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Bike is starting." << endl;
    }

    void stop() override {
        cout << "Bike is stopping." << endl;
    }
};

int main() {
    Car c;
    Bike b;

    Vehicle* v;

    v = &c;
    v->start();
    v->stop();

    v = &b;
    v->start();
    v->stop();

    return 0;
}