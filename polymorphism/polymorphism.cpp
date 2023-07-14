#include <iostream>

using namespace std;

class Employee{
    public:
    string name;
    virtual void work(){
        cout << name << " is checking e-mail" << endl;
    }
};
class Developer:public Employee{
    public:
    string favLan;
    void work(){
        cout << name << " is coding " << favLan << endl;
    }
};
class Teacher:public Employee{
    public:
    string favSub;
    void work(){
        cout << name << " is teaching " << favSub << endl;
    }
};

int main(){
    Developer d;
    d.name = "Shihab";
    d.favLan = "python";

    Teacher t;
    t.name = "Mim";
    t.favSub = "English";

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->work(); //'->' is symbol is used when we want to access members using a pointer
    e2->work(); //the symbol automatically appears when we type '.' like - e1.work()

/*
  the most common use of polymorphism is when a parent class reference is
  used to refer to a child class.
  Notice the work() method in parent class, Employee, is virtual. it tells please check if
  there is a implementation of the same method in the derived classes if so use that.
*/

    return 0;
}