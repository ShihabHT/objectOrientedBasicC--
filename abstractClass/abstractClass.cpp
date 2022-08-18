#include <iostream>

using namespace std;

class AbstractPhone{
    virtual void makeCall()=0;
    virtual void sendText()=0;
};
class Phone:AbstractPhone{
public:
    string name;
    Phone(string Aname){name = Aname;}

    void makeCall(){
        cout<<"Calling Google...."<<endl;
    }
    void sendText(){
        cout<<"Texting NASA...."<<endl;
    }

};

class Employee{
    string name;
    int age;
public:
    Employee(string aName, int aAge){
        name = aName;
        age = aAge;
    }
    string getName(){return name;}
    int getAge(){return age;}
    void askForPromotion(){
        if(age>30)
            cout<<name<<" promoted"<<endl;
        else
            cout<<name<< " Not promoted"<<endl;
    }

};
/*All class gives the default constructor but if we create constructor on
your own the you lose the default one. And if we inherit that class to
another then that class also loses its default constructor. So we have to
define the constructor for the child class manually
*/
class Developer:public Employee{
public:
    string favLan;
    Developer(string aName, int aAge, string aFavLan):Employee(aName, aAge){
        favLan = aFavLan;
    }//as we have created constructor for parent class we don't have to do it again and this is the way to create the object in this case.
    void debug(){cout<<getName()<<" Debugging python..."<<endl;}
};

int main(){
    Phone samsung("Samsung");
    cout<<samsung.name<<endl;
    samsung.makeCall();
    samsung.sendText();

    Developer d("Shihab", 26, "Python");
    d.debug();
    d.askForPromotion();

    return 0;
}
// successfully created repo in git with vs code