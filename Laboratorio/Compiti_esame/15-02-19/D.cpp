#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>
#define DIM 50

using namespace std;

class A{
    private:
    int* ptr;
    short len;
    public:
    A(short m, short k){
        this->len = m;
        ptr = new int[m];
        for(int i=0; i<len; i++){
            ptr[i] = rand()%(k - 1 + 1) + 1;
        }
    }

    virtual const double f()= 0;


    int const get(short i){
        return ptr[i%len];
    }


    short const getLen(){
        return len;
    }

    virtual ostream& put(ostream& os){
        os << typeid(*this).name() << ", ptr=[";
        for(int i=0; i<len; i++){
            os << ptr[i] << " ";
        }
        os << "], ";
        return os;
    }

    int& operator[](short i){
        return ptr[i % len];
    }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A{
    private: 
    double p;
    public:
    B(short m, short k, double y) : A(m, k){
        p = y;
    }

    double const f(){
        double somma = 0;
        for(int i=0; i<A::getLen(); i+=2){
            somma += A::get(i);
        }
        return (double)somma/p;
    }

    ostream& put(ostream& os){
        A :: put(os);
        os << " p=" << p << " f()=" << f();
        return os; 
    }
};


class C : public A{
    private:
    char x;
    public:
    C(short n, short k, char c) : A(n, k){
        x = c;
    }

    double const f(){
        int counter_Dispari = 0;
        double dispari = 0;
        for(int i = 1; i<A::getLen(); i+=2){
            dispari += A::get(i);
            counter_Dispari++;
        }
        if(counter_Dispari > 0){
        return dispari/counter_Dispari;
        }else{
            return 0;
        }
    }

    string const g (char c){
        string temp = "";
        temp += x;
        temp += c;
        return temp;
    }

    ostream& put(ostream& os){
        A::put(os);
        os << " x=" << x << ", f()=" << f();
        return os;
    }
};

int main(){
    srand(111222333);
    A *vett[DIM];

    for(int i=0; i<DIM; i++){
	    short n=1+rand()%10;
	    short m = 1+rand()%8;
	if(rand()%2==0)
	    vett[i]= new B(n, m, rand()/(double) RAND_MAX+0.05);
	else
	    vett[i]= new C(n, m, (char) (rand()%('z' - 'a' + 1) + 'a'));
    }

    //PUNTO1
    cout << "PUNTO 1" <<endl <<endl;
    for(int i=0; i<DIM; i++){
        cout << i << "), " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << "PUNTO 2" << endl << endl;
    double somma = 0;
    string concatenazione = "";
    for(int i=0; i<DIM; i++){
        somma += vett[i]->f();
        if(typeid(*vett[i]) == typeid(C)){
            concatenazione += ((C*)(vett[i]))->g('h');
        }
    }
    cout << "Avg(f())=" << somma/DIM << ", concatenazione=" << concatenazione << endl;

    //PUNTO 3
    cout << "PUNTO 3 " << endl << endl;
    cout << *vett[5] << endl;
    (*vett[5])[0] = -1;
    cout << *vett[5] << endl;
}