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

    e1->work();
    e2->work();

    return 0;
}