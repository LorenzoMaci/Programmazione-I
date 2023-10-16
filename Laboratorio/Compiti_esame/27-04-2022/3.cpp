#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <typeinfo>
#include <cfloat>
#define DIM 15

using namespace std;

class Wheel{
    private:
    int value;
    int default_value;
    int num_faces;
    public:
    Wheel(int initial_value, int num_faces){
        this->value = initial_value;
        this->default_value = initial_value;
        this->num_faces = num_faces;
    }

    void rotate(int turns){
        value = (value + turns) % num_faces;
    }

    int getValue(){
        return value;
    }

    void reset(){
        value = default_value;
    }

};

class AbstractSlotMachine{
    protected:
    Wheel **wheels;
    int num_wheels;
    int prize;
    int num_spins;
    int num_wins;
    public:
    AbstractSlotMachine(int num_wheels, int num_faces){
        prize = 0;
        num_spins = 0;
        num_wins = 0;
        this->num_wheels = num_wheels;
        wheels = new Wheel*[num_wheels];
        for(int i=0; i<num_wheels; i++){
            wheels[i] = new Wheel(rand()% num_faces - 1, num_faces);
        }
    }

    virtual int spin() = 0;

    int getPrize(){
        return prize;
    }
    
    double getWinRate(){
        return (double)num_wins/num_spins;
    }

    void reset(){
        for(int i=0; i<num_wheels; i++){
            wheels[i]->reset();
        }
    }

    virtual ostream& put(ostream& os){
        os << "Class=" << typeid(*this).name() << ", num_wheels=" << num_wheels << ", prize=" << prize << ", num_spins=" << num_spins;
        os << ", num_wins=" << num_wins << ", winrate=" << getWinRate(); 
        return os;
    }

};

ostream& operator<<(ostream& os, AbstractSlotMachine& obj){
    return obj.put(os);
}

class ThreeWheelsSlotMachine : public AbstractSlotMachine{
    private:
    int num_max;
    public:
    ThreeWheelsSlotMachine() : AbstractSlotMachine(3, 6){
        num_max = 0;
    }

    int spin(){
        num_spins++;
        int vals[3];
        int max = 0;
        for(int i=0; i<num_wheels; i++){
            wheels[i]->rotate(rand()% (10 - 3 + 1) + 3);
            vals[i] = wheels[i]->getValue();
            prize += vals[i];
            if(max < vals[i]){
                max = vals[i];
            }
        }
        if(vals[0] == vals[1] && vals[1] == vals[2]){
            if(vals[0] = max){
                prize *= 2;
                num_max++;
            }
            //Tiro vincente
            num_wins++;
            int prize_save = prize;
            prize = 0;
            return prize_save;
        }
        else{
            return 0;
        }
    }


    int getNumMax(){
        return num_max;
    }

    ostream& put(ostream& os){
        AbstractSlotMachine::put(os);
        os << ", num_max= "<< num_max;
        return os;
    }
};


class TenWheelsSlotMachine : public AbstractSlotMachine{
    public:
    TenWheelsSlotMachine() : AbstractSlotMachine(5, 10){}

    int spin(){
        num_spins++;
        int vals[10];
        int last = 0;
        for(int i=0; i<num_wheels; i++){
            int num_turns = rand()%(10 - 3 + 1) + 3 + round(last/3);
            last = num_turns;
            wheels[i]->rotate(num_turns);
            vals[i] = wheels[i]->getValue();
            prize += vals[i];
        }
        bool duplicates = false;
        for(int i=0; i<num_wheels; i++){
            for(int j= i + 1; j<num_wheels; j++){
                if(vals[i] == vals[j]){
                    duplicates = true;
                }
            }
        }

        if(duplicates){
            return 0;
        }else{
            num_wins++;
            return prize;
            prize = 0;
        }
    }

    ostream& put(ostream& os){
        AbstractSlotMachine::put(os);
        return os;
    }

};      

int main(){
    srand(424242);

    AbstractSlotMachine **vec = new AbstractSlotMachine*[DIM];

    for(int i=0; i<DIM; i++){
        if(rand()%2){
            vec[i] = new ThreeWheelsSlotMachine();
        } else{
            vec[i] = new TenWheelsSlotMachine();
        }
    }

    for(int i=0; i<DIM*100; i++){
        vec[rand()%DIM]->spin();
        if(rand()%5==0){
            vec[rand()%DIM]->reset();
        }
    }

    //Punto 1
    cout << endl << "Punto 1: "<< endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") "<< *vec[i] << endl;
    }

    //Punto 2
    double max = DBL_MIN;
    for(int i=0; i<DIM;  i++){
        if(max < vec[i]->getWinRate()){
            max = vec[i]->getWinRate();
        }
    }
    cout << "massimo valore=" << max << endl;

    //Punto 3
    cout << endl << "PUNTO 3: "<< endl;
    double somma = 0.0;
    int elementi_ThreeWheels = 0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine)){
            somma += ((ThreeWheelsSlotMachine*)(vec[i]))->getNumMax();
        }
    }
    cout << "Mean num vax=" << somma/DIM << endl;
}