#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>
#include <cfloat>
#define DIM 10

using namespace std;

class Roller{
    private:
    int value;
    int default_value;
    int num_faces;
    public:
    Roller(int initial_value, int num_faces){
        this->value = initial_value;
        this->default_value = initial_value;
        this->num_faces = num_faces;
    }

    void roll(int turns){
        value = (value + turns) % num_faces;
    }

    int getValue(){
        return value;
    }

    void reset(){
        value = default_value;
    }

};

class AbstractBandit{
    protected:
    Roller **rollers;
    int num_rollers;
    int coins;
    int num_times;
    int num_wins;
    public:
    AbstractBandit(int num_rollers, int num_faces){
        this->coins = 0;
        this->num_times = 0;
        this->num_wins = 0;
        this->num_rollers = num_rollers;
        rollers = new Roller*[num_rollers];
        for(int i=0; i<num_rollers; i++){
            rollers[i] = new Roller(rand()% num_faces, num_faces);
        }
    }

    virtual int spin() = 0;

    int getCoin(){
        return coins;
    }

    double getWinRate(){
        return (double)num_wins/num_times;
    }

    void reset(){
        for(int i=0; i<num_rollers; i++){
            rollers[i]->reset();
        }
    }

    virtual ostream& put(ostream& os){
        os << "Class=" << typeid(*this).name() << ", num_rollers=" << num_rollers << ", coins=" << coins;
        os << ", num_times=" << num_times << ", num_wins=" << num_wins << ", winrate()=" << getWinRate();
        return os; 
    }

};

ostream& operator<<(ostream& os, AbstractBandit& obj){
    return obj.put(os);
}

class ThreeArmedBandit : public AbstractBandit{
    private:
    int max;

    public:
    ThreeArmedBandit() : AbstractBandit(3, 5){
        max = 0;
    }

    int spin(){
        num_times++;
        int ThreeArmed[3];
        int somma = 0;
        for(int i=0; i<num_rollers; i++){
            rollers[i]->roll(rand()%(12 - 3 + 1) + 3);
            ThreeArmed[i] = rollers[i]->getValue();
            somma += ThreeArmed[i];
            coins += ThreeArmed[i];
            if(max < somma){
                max = somma;
            }
        }
        if(ThreeArmed[0] == ThreeArmed[1] && ThreeArmed[1] == ThreeArmed[2]){
            //tiro vincente
            num_wins++;
            int temp_coins = coins;
            coins = 0;
            return temp_coins;
        }else{
            return 0;
        }
    }

    int getMax(){
        return max;
    }

    ostream& put(ostream& os){
        AbstractBandit::put(os);
        os << ", max=" << max;
        return os;
    }
};

class FiveArmedBandit : public AbstractBandit{
    public:
    FiveArmedBandit() : AbstractBandit(5, 10) {}

    int spin(){
        num_times++;
        int FiveArmed[10];
        for(int i=0; i<num_rollers; i++){
            int num_turns = rand()%(6 - 3 + 1) + 3;
            rollers[i]->roll(num_turns);
            FiveArmed[i] = rollers[i]->getValue();
            coins += FiveArmed[i];
        }
        bool duplicates = false;
        for(int i=0; i<num_rollers; i++){
            for(int j=i+1; j<num_rollers; j++){
                if(FiveArmed[i] == FiveArmed[j]){
                    duplicates = true;
                }
            }
        }
        if(duplicates){
            return 0;
        }else{
            num_wins++;
            int temp_coins = coins;
            coins = 0;
            return temp_coins;
        }
    }

    ostream& put(ostream& os){
        AbstractBandit::put(os);
        return os;
    }
};

int main(){
    srand(424242);

    AbstractBandit **vec = new AbstractBandit*[DIM];

    for(int i=0; i<DIM; i++) {
        if(rand()%2){
            vec[i] = new ThreeArmedBandit();
        }else{
            vec[i] = new FiveArmedBandit();
        }
    }
 
    for(int i=0; i<DIM*100; i++) {
        vec[rand()%DIM]->spin();
        if(rand()%5==0)
            vec[rand()%DIM]->reset();
    }

    //Punto 1
    cout << endl << "Punto 1 " << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") "<< *vec[i] << endl;
    }

    //Punto 2
    cout << endl << "Punto 2:" << endl;
    double min = DBL_MAX;
    for(int i=0; i<DIM; i++){
        if(min > vec[i]->getWinRate()){
            min = vec[i]->getWinRate();
        }
    }
    cout << "min win rate = " << min << endl;

    //Punto 3
    cout << endl << "Punto 3: "<< endl;
    int somma = 0;
    int elementi = 0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vec[i]) == typeid(ThreeArmedBandit)){
            elementi++;
            somma += ((ThreeArmedBandit*)vec[i])->getMax();
        }
    }
    cout << "mean max= "<< (double)somma/elementi << endl;
}