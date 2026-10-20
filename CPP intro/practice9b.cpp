#include <iostream> 
using namespace std;

// Base class named Shape
class Employee { 
public: 
    Employee()
    {
        cout<<"This is constuctor of Employee"<<endl;
    }
    // Pure virtual function 
    virtual void calculateBonus() const = 0; 

   
}; 

class Manager : public Employee { 
private:
    int salary;
public: 
    Manager(int sal):salary(sal){}
        
 
    void calculateBonus() const override { 
        cout<<"Manager Bonus="<<salary/10<<endl; 
    } 
   
}; 
class Devloper : public Employee { 
private:
    int salary;
public: 
     Devloper(int sal):salary(sal){}
        
 
    void calculateBonus() const override { 
        cout<<"Devloper Bonus="<<salary/5<<endl; 
    } 
   
}; 
int main(){

    Manager m(25000);
    m.calculateBonus();
    
    Devloper d(25000);
    d.calculateBonus();

    return 0;
}