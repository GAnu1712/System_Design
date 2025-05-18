#include<iostream>
#include<string>
using namespace std;
/*
Encapsulation says 2 things:
1. An Object's Characteristics and its behaviour are encapsulated together
within that Object.
2. All the characteristics or behaviours are not for everyone to access.
Object should provide data security.

We follow above 2 pointers about Object of real world in programming by:
1. Creating a class that act as a blueprint for Object creation. Class contain
all the characteristics (class variable) and behaviour (class methods) in one block,
encapsulating it together.
2. We introduce access modifiers (public, private, protected) etc to provide data
security to the class members.
*/
class SportCar{
    private:

    //characters
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int CurrentGear;
    string tyre;

public:
    SportCar(string b,string m){
        this->brand=b;
        this->model=m;
        isEngineOn=false;
        currentSpeed=0;
        CurrentGear=0;
        tyre="MRF";
    }

    //getters and setters
    int getCurrentSpeed()
    {
        return this->currentSpeed;
    }

    string getTyre(){
        return this->tyre;
    }
    void setTyre(string tyre)
    {
        //validations
        this->tyre=tyre;
    }
    //behaviours-->methods
    void startEngine(){
        isEngineOn=true;
        cout<< brand<<" "<< model<<" : Engine starts with a roar!!"<<endl;
    }

    void shiftGear(int gear)
    {
        if(!isEngineOn){
            cout<< brand<<" "<< model<<" : Engine is off ! Cannot Shift Gear."<<endl;
            return;
        }
        CurrentGear=gear;
         cout<< brand<<" "<< model<<" : Shifted to Gear"<<CurrentGear<<endl;
    }

    void accelerate(){
        if(!isEngineOn){
             cout<< brand<<" "<< model<<" : Engine is off !!! cannot accelerate."<<endl;
             return;
        }
        currentSpeed+=20;
         cout<< brand<<" "<< model<<" : Accelerating to"<<currentSpeed<<endl;
    }
    void brake(){
        currentSpeed-=20;
        if(currentSpeed < 0) currentSpeed=0;
         cout<< brand<<" "<< model<<" : Breaking!! speed is now"<<currentSpeed<<"km/h"<<endl;
    }
    void stopEngine(){
        isEngineOn=true;
        CurrentGear=0;
        currentSpeed=0;
        cout<< brand<<" "<< model<<" : Engine Turned off"<<endl;
    }
    ~SportCar() {}
};
//Main method
int main(){
    SportCar* myCar1=new SportCar("Ford","Mustang");
    myCar1->startEngine();
    myCar1->shiftGear(1);
    myCar1->accelerate();
    myCar1->brake();
    myCar1->stopEngine();

    //Setting arbitary value to speed
   // myCar1->currentSpeed=500;
    //cout<< "Current Speed of My Sports Car is set to "<< myCar1->currentSpeed<<endl;
    cout<< myCar1->getCurrentSpeed();
    delete myCar1;
    return 0;
}