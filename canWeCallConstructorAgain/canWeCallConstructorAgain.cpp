#include <iostream>

using namespace std;

class Phone{
private:
    int ram;
    int storage;
public:
    Phone(int aRam, int aStorage){
        ram = aRam;
        storage = aStorage;
    }
    void setRam(int sRam){
        ram = sRam;
    }
    int getRam(){
        return ram;
    }
};

int main(){
    Phone phn1(4, 128);
    cout<<phn1.getRam()<<endl;
    Phone phn1 = Phone(43,23);
    cout<<phn1.getRam();

    return 0;
}
