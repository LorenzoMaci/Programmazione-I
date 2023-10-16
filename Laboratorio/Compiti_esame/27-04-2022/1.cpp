#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
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
    Wheel** wheels;
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
        os << "Class= "<< typeid(*this).name() << ", num_wheels=" << num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins=" << num_wins << ", winrate=" << getWinRate();
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

    int getNumMax(){
        return num_max;
    }

    int spin(){
        num_spins++;
        int vals[3];
        for(int i = 0; i<num_wheels; i++){
            wheels[i]->rotate(rand() % 8 + 3);
            vals[i] = wheels[i]->getValue();
            prize += vals[i];
        }
        if(vals[0] == vals[1] && vals[0] == vals[2]){
            if(vals[0] = 5){
                //VALORE MASSIMO OTTENUTO
                prize *= 2;
                num_max++;
            }
            //IL TIRO È VINCENTE
            num_wins++;
            int tmp_prize = prize;
            prize = 0;
            return tmp_prize;
        }
        else{
            //IL TIRO NON È VINCENTE
            return 0;
        }
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
        int vals[10];
        int last = 0;
        for(int i=0; i<num_wheels; i++){
            int num_turns = rand()% 8 + 3 + round(last/3);
            last = num_turns;
            wheels[i]->rotate(num_turns);
            vals[i] = wheels[i]->getValue();
            prize += vals[i];
        }
        bool duplicates = false;
        for(int i=0; i<num_wheels; i++){
            for(int j = i + 1; j<num_wheels; j++){
                if(vals[i] == vals[j]){
                    duplicates = true;
                }
            }
        }
        if(duplicates){
            //Tiro non vincente
            return 0;
        }else{
            //Tiro vincente
            num_wins++;
            int prize_win = prize;
            prize = 0;
            return prize_win;
        }
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
    cout << endl << "Punto 1: " << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") "<< *vec[i] << endl;
    }

    //Punto 2
    cout << endl << "Punto 2: " << endl;
    double max = 0;
    for(int i=0; i<DIM; i++){
        if(max < vec[i]->getWinRate()){
            max = vec[i]->getWinRate();
        }
    }
    cout << " max win rate = "<< max << endl;

    //Punto 3
    cout << endl << "Punto 3: "<< endl;
    double somma = 0;
    int counter = 0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine)){
            somma += ((ThreeWheelsSlotMachine*)(vec[i]))->getNumMax();
            counter++;
        }
    }
    cout << "mean num max = "<< (double)somma/DIM << endl;;
}