#include <iostream>

using namespace std;

/*
  abstraction means hiding complex things behind a procedure
  that makes then look simple. Like  we can send a message on
  out smartphones but we don't need to worry about the 
  processes it goes through.
  
  virtual keyword is used to make it obligatory to implement
  this method whichever class wants to inherit this class. 
  compiler will throw an error if this function is not implemented.
  * Childclass = subclass = derived class
  * parentClass = base class
*/

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