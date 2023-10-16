#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <typeinfo>
#define DIM 10

using namespace std;

class Tank{
    private:
    double capacity; //capienza del serbatoio
    double fuelLevel; //livello carburante
 
    public:
    Tank(double capacity, double fuelLevel){
        this->capacity = capacity;
        this->fuelLevel = fuelLevel;
    }

    double getCapacity(){
        return capacity;
    }

    double fill(double fuel){
        double carburante_in_eccesso = 0;
        if((fuelLevel + fuel ) <= capacity){
            return 0;
        }else{
            carburante_in_eccesso = (fuelLevel + fuel ) - carburante_in_eccesso;
            fuelLevel = capacity;
            return carburante_in_eccesso;
        }
    }

    bool consume(double fuel){
        if((fuelLevel - fuel) > 0){
            return true;
        }
        return false;
    }

    double getTankLevel(){
        return fuelLevel/capacity;
    }

    bool hasFuel(double fuel){
        if(fuelLevel >= fuel){
            return true;
        }
        return false;
    }

    double getFuelLevel(){
        return fuelLevel;
    }

};

class Vehicle{
    protected:
    int wheels;
    Tank tank;
    double chilometers;

    public:
    Vehicle(double wheels, double chilometers, double tankCapacity, double fuelLevel) : tank(tankCapacity ,fuelLevel){
        this->wheels = wheels;
        this->chilometers = chilometers;
    }

    virtual bool drive(double km) = 0;

    double getTankLevel(){
        return tank.getTankLevel();
    }

    virtual ostream& put(ostream& os){
        os << "Class=" << typeid(*this).name() << ", wheels=" << wheels << ", chilometers=" << chilometers << ", tank.getCapacity=" << tank.getCapacity() << ", tank.getFuelLevel=" << tank.getTankLevel();
        return os;
    }

};

ostream& operator<<(ostream& os, Vehicle& obj){
    return obj.put(os);
}

class Car : public Vehicle{
    protected:
    int times;

    public:
    Car(double chilometers) : Vehicle(4, chilometers, 55, 25){
        times = 0;
    }

    bool drive(double km){
        double carburante_necessario = km * 0.075;
        if(Vehicle::getTankLevel() <= 0.5){
            double carburante_attuale = carburante_necessario;
            carburante_necessario -= (double)((carburante_attuale * 5) / 100);
        }

        if(tank.hasFuel(carburante_necessario)){
            tank.consume(carburante_necessario);
            chilometers += km;
            times++;
            return true;
        }else{
            return false;
        }
    }

    int getTime(){
        return times;
    }

    ostream& put(ostream& os){
        Vehicle::put(os);
        os << ", times=" << times;
        return os;
    }

};

class Truck : public Vehicle{
    public:
    Truck(double chilometers) : Vehicle(6, chilometers, 110, 50){}

    bool drive(double km){
        double carburante_necessario = km * 0.4;
        if(chilometers > 200000){
            double carburante = carburante_necessario;
            carburante_necessario = (double)((carburante_necessario *20)/100);
        }

        if(tank.hasFuel(carburante_necessario)){
            tank.consume(carburante_necessario);
            chilometers += km;
            return true;
        }else{
            return false;
        }
    }

    ostream& put(ostream& os){
        Vehicle::put(os);
        return os;
    }

};

int main(){
    srand(424242);
    Vehicle *vec[DIM];
    for(int i=0; i<DIM; i++) {
        int chilometers = rand()%200000;
        if(rand()%2){
            vec[i] = new Car(chilometers);
        } else {
            vec[i] = new Truck(chilometers);
        }
    }
 
    for(int i=0; i<DIM*5; i++) {
        int x = rand()%100;
        vec[x%DIM]->drive(x);
    }

    //Punto 1
    cout << endl << "Punto 1: "<< endl;
    for(int i=0; i<DIM; i++){
        cout << i  << ") "<< *vec[i] << endl;
    }

    //Punto 2
    cout << endl << "PUNTO 2: "<<endl;
    double somma = 0.0;

    for(int i = 0; i<DIM; i++){
        somma += vec[i]->getTankLevel();
    }

    cout << "Media di getTankLevel()= "<< somma/DIM << endl;

    //Punto 3
    cout << endl << "Punto 3: "<< endl;
    int max = 0;
    for(int i=0; i<DIM; i++){
        if(max < ((Car*)(vec[i]))->getTime()){
            max = ((Car*)(vec[i]))->getTime();
        }
    }
    cout << "Massimo di GetTime()=" << max << endl;
}