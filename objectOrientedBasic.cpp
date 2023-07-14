#include <iostream>

using namespace std;

/*
  Real world entities can't be represented by any data type available
  in any programming language. We have different data types like
  int, float, double, string, char. But they are not useful for
  representing any real world entity like, books, SmartPhones etc.
  If we want to create a program to store SmartPhones information
  we don't actually have SmartPhone data type. We only have certain
  data types which may not be sufficient to model a real world things.

  This is where classes and objects come in. And a class essentially
  works as a new data type. Where we can add specifications for our
  objects which works as a template. A 'Book' class is like a
  specification or blueprint of a book. And an object is an instance
  of that blueprint or that class. So the object is an actual book.
  Properties and methods or behaviour are class members of the class.
  check this video on OOP of CodeBeauty on youtube,
  "https://www.youtube.com/watch?v=wN0x9eZLix4"
*/

//CONSTRUCTOR
/*
  constructor is a special type of function that gets called whenever
  an object gets created. We can create a constructor by creating a
  function with the class name. This function has no return type cause
  constructor function does not have one.
  3 properties of a constructor, 1. has no return type, 2. same name as
  its class, 3. must be public
*/

class Phone{
public: //default access specifier of a class is private
    string name;
    int ram;
    string processor;

//constructor that is called while the object is created
    Phone(){
        cout<<"Creating the object"<<endl;
    }

//Object function
    bool isFlagship(){
        if(ram>=6){
            return true;
        }
        return false;
    }
};

class Planet{
public:
    string name;
    int dia;
    bool isHabitable;

//constructor with arguments
    Planet(string argName, int argDia, bool argIsHabitable){
        name = argName;
        dia = argDia;
        isHabitable = argIsHabitable;
    }
/*We also can create multiple constructor with different numbers of
  arguments or different types of arguments. This is called
  constructor overloading which is a type of polymorphism
*/
    Planet(){
        name = "Not sure";
        dia = 0;
        isHabitable = false;
    }
};


//Getters and setters example
class Man{
public:
    void setDick(int aDick){
        if(aDick<5){
            dick = 0;
        }else{
            dick = aDick;
        }

    }
    int getDick(){
        return dick;
    }
    void setHair(string h){
        hair = h;
    }
    string getHair(){
        return hair;
    }

private:
    int dick;
    string hair;
};

int main(){
    Phone phn1;
    phn1.name = "Samsung";
    phn1.ram = 6;

    Phone phn2;
    phn2.name = "Nokia";
    phn2.ram = 4;
    phn2.processor = "SD 720";

    cout<<phn1.name<<" is flagship : "<<phn1.isFlagship()<<endl;
    cout<<phn2.name<<" is flagship : "<<phn2.isFlagship()<<endl;

    Planet earth("Earth", 12000, true);
    Planet mars("Mars", 6700, false);
    Planet xNet;

    cout<<earth.name<<" : "<<earth.dia<<" : "<<earth.isHabitable<<endl;
    cout<<mars.name<<" : "<<mars.dia<<" : "<<mars.isHabitable<<endl;
    cout<<xNet.name<<" : "<<xNet.dia<<" : "<<xNet.isHabitable<<endl;

    //Getters and setters
    cout<<"Getters and setters Example"<<endl;
    Man man1;
    man1.setDick(4);

    cout<<man1.getDick();

    return 0;
}
