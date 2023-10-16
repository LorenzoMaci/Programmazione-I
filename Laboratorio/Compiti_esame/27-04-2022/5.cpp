#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <typeinfo>
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
        value = (value + turns)%num_faces;
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
        this->prize = 0;
        this->num_spins = 0;
        this->num_wins = 0;
        this->num_wheels = num_wheels;
        wheels = new Wheel*[num_wheels];
        for(int i=0; i<num_wheels; i++){
            wheels[i] = new Wheel(rand()% num_faces, num_faces);
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
        os << "Class=" << typeid(*this).name() << ", num_wheels=" << num_wheels << ", prize=" << prize;
        os << ", num_spins=" << num_spins << ", num_wins=" << num_wins<< ", winrate=" << getWinRate();
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
        int ThreeWheels[3];
        int max = 0;
        for(int i=0; i<num_wheels; i++){
            wheels[i]->rotate(rand()%(10 -3 + 1) + 3);
            ThreeWheels[i] = wheels[i]->getValue();
            prize += ThreeWheels[i];
            if(max < ThreeWheels[i]){
                max = ThreeWheels[i];
            }
        }
        if(ThreeWheels[0] == ThreeWheels[1] && ThreeWheels[1] == ThreeWheels[2]){
            if(ThreeWheels[0] = max){
                prize *= 2;
                num_max++;
            }
            //tiro vincente
            num_wins++;
            int prezzo_temp = prize;
            prize = 0;
            return prezzo_temp;
        }else{
            return 0;
        }
    }

    int getNumMax(){
        return num_max;
    }

    ostream& put(ostream& os){
        AbstractSlotMachine::put(os);
        os << ", num_max=" << num_max;
        return os;
    }
};

class TenWheelsSlotMachine : public AbstractSlotMachine{
    public:
    TenWheelsSlotMachine() : AbstractSlotMachine(5, 10){}

    int spin(){
        num_spins++;
        int TenWheels[10];
        int spin = 0;
        for(int i=0; i<num_wheels; i++){
            int num_turns = rand()% (10 - 3 + 1) + 3 + round(spin/3);
            spin = num_turns;
            wheels[i]->rotate(spin);
            TenWheels[i] = wheels[i]->getValue();
            prize += TenWheels[i];
        }
        bool duplicate = false;
        for(int i=0; i<num_wheels; i++){
            for(int j = i + 1; j<num_wheels; j++){
                if(TenWheels[i] == TenWheels[j]){
                    duplicate = true;
                }
            }
        }
        if(duplicate){
            return 0;
        }else{
            num_wins++;
            int save_prize = prize;
            prize = 0;
            return save_prize;
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
    cout << endl << "Punto 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") " << *vec[i] << endl;
    }
}

