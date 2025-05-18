#include<iostream>
#include<string>
using namespace std;

/*
We know that real world Objects show inheritance relationship where we
have parent object and child object. child object have all the characters
or behaviours that parent have plus some additional characters/behaviours.
Like all cars in real world have a brand, model etc and can start, stop, 
accelerate etc. But some specific cars like manual car have gear System
while other specific cars like Electric cars have battery system.

We represent this scenario of real world in programming by creating a parent class and
defining all the characters(variables) or behaviours(methods) that all cars 
have in parent class. Then we create different child classes that inherits 
from this parent class and define only those characters and behaviours
that are specific to them. Although objects of these child classes can 
access or call parent class characters(variables) and behaviours(methods).
Hence providing code reusability.
*/

class Car{
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public:
    Car(string b,string m){
        this->brand=b;
        this->model=m;
        isEngineOn=false;
        currentSpeed=0;
    }

    //Commom methods for all cars
    void startEngine(){
        isEngineOn=true;
        cout<< brand<<" "<< model<<" : Engine starts with a roar!!"<<endl;
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
        isEngineOn=false;
        currentSpeed=0;
        cout<< brand<<" "<< model<<" : Engine Turned off"<<endl;
    }
    virtual ~Car() {}

};

class ManualCar :public Car{ //Inherits from Car
    private:
    int currentGear; //Specific to manual car
    public:
    ManualCar(string b,string m) : Car(b,m){
        currentGear=0;
    }
    //Specialized method for Car
    void shiftGear(int gear){
        currentGear=gear;
         cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }
};

class ElectricCar :public Car{//inherits from car
    private:
    int batterylevel; //specific to electric car only
    public:
    ElectricCar(string b,string m) :Car(b,m){
        batterylevel=100;
    }
    //specialised method for electric car
    void chargeBattery(){
        batterylevel=100;
        cout << brand << " " << model << " : Battery fully charged!!!"<< endl;
    }
};

//Maon method
int main()
{
    ManualCar* mymanualCar=new ManualCar("Suzukki","WagonR");
    mymanualCar->startEngine();
    mymanualCar->shiftGear(1); //specific to manual car
    mymanualCar->accelerate();
    mymanualCar->brake();
    mymanualCar->stopEngine();
    delete mymanualCar;


    cout<<"------------------------------"<<endl;
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery(); //specific to electric car
    myElectricCar->startEngine(); 
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar; 

    return 0;
}