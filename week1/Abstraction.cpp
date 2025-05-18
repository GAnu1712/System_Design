#include<iostream>
#include<string>
using namespace std;
/*
Abstract class --> Act as an interface for Outsiude world to operate the car. 
This abstract class tells 'WHAT' all it can do rather then 'HOW' it does that.
Since this is an abstract class we cannot directly create Objects of this class. We
need to Inherit it first and then that child class will have the responsibility to 
provide implementation details of all the abstract (virtual) methods in the class.

In our real world example of Car, imagine you sitting in the car and able to operate
the car (startEngine, accelerate, brake, turn) just by pressing or moving some
pedals/buttons/stearing wheel etc. You dont need to know how these things work, and
also they are hidden under thre hood.
This Class 'Car' denotes that (pedals/buttons/stearing wheel etc). 
*/
//Real life Car
 
class Car{
    public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual ~Car(){}

}; 
/*
This is a Concrete class (A class that provide implementation details of an abstract class).
Now anyone can make an Object of 'SportsCar' and can assign it to 'Car' (Parent class) pointer 
(See main method for this)

In our real world example of Car, as you cannot have a real car by just having its body only
(all these buttons or pedals). You need to have the actual implementation of 'What' happens
when we press these buttons. 'SportsCar' class denotes that actual implementation. 

Hence we can concude, to denote a real world car in programming we created 2 classes.
One to deonte all the user-interface like pedals, buttons, stearing wheels etc ('Car' class).
And another one to denote the actual car with all the implementations of these buttons (SportsCar' class).
 */

class SportCar :public Car {
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int CurrentGear;

    SportCar(string b,string m){
        this->brand=b;
        this->model=m;
        isEngineOn=false;
        currentSpeed=0;
        CurrentGear=0;
    }

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
};
int  main()
{
    Car* myCar=new SportCar("Ford","Mustang");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
    return 0;
}