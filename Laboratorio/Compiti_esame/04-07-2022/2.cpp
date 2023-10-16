#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cfloat>
#include <typeinfo>
#define DIM 7

using namespace std;

template<typename T>
class AbstractRandomGenerator{
    protected:
    int num_values;
    int tossed;
    T accumulated_value;
    T value;
    T* values;
    
    public:
    AbstractRandomGenerator(T value, int num_values, T* input_values){
        this->value = value;
        this->num_values = num_values;
        values = new T[num_values];
        for(int i=0; i<num_values; i++){
            values[i] = input_values[i];
        }
        this->accumulated_value = value;
        this->tossed = 0;
    }

    virtual T toss(){
        value = values[rand()%num_values];
        tossed++;
        accumulated_value += value;
        return value;
    }

    T getValue(){
        return value;
    }

    int getTossed(){
        return tossed;
    }

    virtual void nudge() = 0;

    virtual ostream& put(ostream& os){
        os << "Class="<< typeid(*this).name() << ", value={";
        for(int i=0; i<num_values; i++){
            os << values[i] << " ";
        }
        os << "}, value=" << value << ", accumulated_value=" << accumulated_value << ", tossed= "<< tossed;
        return os;
    }

};  

template<typename T>
ostream& operator<<(ostream& os, AbstractRandomGenerator<T>& obj){
    return obj.put(os);
}

class Dice : public AbstractRandomGenerator<int>{
    private:
    int doubles;

    public:
    Dice() : AbstractRandomGenerator(1, 6, new int[6]{1, 2, 3, 4, 5, 6}){
        doubles = 0;
    }

    void nudge(){
        value += rand()% 3 - 1;
        if(value > 6){
            value = 6;
        }else if(value < 1){
            value = 1;
        }
    }

    int toss(){
        int primo_valore = AbstractRandomGenerator<int>::getValue();
        int ultimo_valore = AbstractRandomGenerator<int>::toss();
        if(primo_valore == ultimo_valore){
            this->doubles++;
        }
        return AbstractRandomGenerator<int>::getValue();
    }

    double getDoubleRate(){
        return (double)doubles/tossed;
    }

    ostream& put(ostream& os){
        AbstractRandomGenerator<int>::put(os);
        return os;
    }

};

class Coin : public AbstractRandomGenerator<string>{
    private:
    int nudge_prob;

    public:
    Coin(int nudge_prob) : AbstractRandomGenerator<string>("H", 2 , new string[2]{"H" , "T"}){
        this->nudge_prob = nudge_prob;
    }

    void nudge(){
        if(rand()%nudge_prob == 0){
            if(AbstractRandomGenerator<string>::value == "H"){
                AbstractRandomGenerator<string>::value == "T";
            }else{
                AbstractRandomGenerator<string>::value == "H";
            }
        }
    }

    ostream& put(ostream& os){
        AbstractRandomGenerator<string>::put(os);
        return os;
    }
};

int main(){
    srand(424242);
 
    AbstractRandomGenerator<int>** vec1 = new AbstractRandomGenerator<int>*[DIM];
    AbstractRandomGenerator<string>** vec2 = new AbstractRandomGenerator<string>*[DIM];

	for(int i=0; i<DIM; i++) {
		vec1[i] = new Dice();
		vec2[i] = new Coin(rand()%10+1);
	}
 
    for(int i=0; i<100; i++) {
         vec1[rand()%DIM]->toss();
		 vec2[rand()%DIM]->toss();
         if(rand()%5==0) {
            vec1[rand()%DIM]->nudge();
			vec2[rand()%DIM]->nudge();
		 }
    }

    //PUNTO 1
    cout << endl << "Punto 1: "<< endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") "<< *vec1[i] << endl;
        cout << i << ") "<< *vec2[i] << endl;
    }

    //Punto 2
    cout << endl << "Punto 2: "<< endl;
    int min = 99999;
    for(int i=0; i<DIM; i++){
        if(min > vec2[i]->getTossed()){
            min = vec2[i]->getTossed();
        }
    }

    cout << "min tossed= "<< min << endl;

    //Punto 3
    cout << endl << "Punto 3: "<< endl;
    double max = DBL_MIN;
    for(int i=0; i<DIM; i++){
        if(max < ((Dice*)(vec1[i]))->getDoubleRate()){
            max = ((Dice*)(vec1[i]))->getDoubleRate();
        }
    }
    cout << "max getDoubleRate= " << max << endl;
}