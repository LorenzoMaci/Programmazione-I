#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>
#define DIM 10

using namespace std;

class AbstractRandomVec{
    protected:
    int* vec;
    int num;
    public:
    AbstractRandomVec(int n, int min, int max){
        this->num = n;
        vec = new int[num];
        for(int i=0; i<num; i++){
            vec[i] = rand()%(max - min + 1) + min;
        }
    }

    virtual int count() = 0;

    int* get(int i){
        if(i >= num || i < 0){
            return nullptr;
        }
        return (vec + i);
    }

    int numel(){
        return num;
    }

    float mean(){
        float somma = 0.0;
        for(int i=0; i<num; i++){
            somma += vec[i];
        }
        return somma/num;
    }

    virtual ostream& put(ostream& os){
        os << "Class=" << typeid(*this).name() << ", num=" << num << ", vec=[";
        for(int i=0; i<num; i++){
            os << vec[i] << " ";
        }
        os << "]";
        return os;
    }

};

ostream& operator<<(ostream& os, AbstractRandomVec& obj){
    return obj.put(os);
}

class TernaryVec : public AbstractRandomVec{
    public:
    TernaryVec(int n) : AbstractRandomVec(n, 0, 2){}

    int count(){
        int counter = 0;
        for(int i=0; i<num; i++){
            if(vec[i] != 0){
                counter++;
            } 
        }
        return counter;
    }

    ostream& put(ostream& os){
        AbstractRandomVec::put(os);
        return os;
    }
};

class MultVec : public AbstractRandomVec{
    private:
    double midpoint;
    public:
    MultVec(int n, int min, int max, int mul) : AbstractRandomVec(n, min, max){
        this->num = n;
        midpoint = (max + min) / 2;
        for(int i=0; i<num; i++){
            int temp = rand()%(max - min + 1) + min;
            if(temp % mul == 0){
                vec[i] = temp;
            }
        }
    }

    int count(){
        int elementi = 0;
        for(int i=0; i<num; i++){
            if(vec[i] > midpoint){
                elementi++;
            }
        }
        return elementi;
    }

    int countEven(){
        int elementi_pari = 0;
        for(int i=0; i<num; i++){
            if(vec[i] % 2 == 0){
                elementi_pari++;
            }
        }
        return elementi_pari;
    }

    ostream& put(ostream& os){
        AbstractRandomVec::put(os);
        os << ", midpoint=" << midpoint;
        return os;
    }

};

int main(){
        srand(424242);

    AbstractRandomVec* vett[DIM];

    for(int i=0; i<DIM; i++) {
	    int n=5+rand()%5;
	    int m=5+rand()%5;
	    int min = rand()%10 + 5;
	    int max = min + rand()%20;

	    switch(rand()%2) {
		    case 0: 
            vett[i]= new TernaryVec(n);
			break;
            case 1:
			vett[i]= new MultVec(n, min, max, m);
	    }
    }

    //Punto 1
    cout << endl << "PUNTO 1: "<< endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //Punto 2
    cout << endl << "PUNTO 2: "<<endl;
    int max = INT_MIN;
    for(int i=0; i<DIM; i++){
        if(max < vett[i]->count()){
            max = vett[i]->count();
        }
    }
    cout << "Massimo valore di count()= "<< max << endl;

    //Punto 3
    cout << endl << "Punto 3: "<< endl;
    double somma = 0.0;
    int elementi = 0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(MultVec)){
            somma += ((MultVec*)vett[i])->countEven();
            elementi++;
        }
    }
    cout << "media dei valori CountEven()= "<< (double)somma/elementi << endl;
}
