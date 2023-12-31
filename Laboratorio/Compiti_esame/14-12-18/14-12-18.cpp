#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>
#define DIM 30

using namespace std;

class A{
    protected:
    double* ptr;
    short len;
    public:
    A(short n){
        this->len = n;
        ptr = new double[len];
        for(int i = 0; i<len; i++){
            ptr[i] = 0 + (rand()/(double)RAND_MAX/(1 - 0));
        }
    }

    virtual double const  foo (short a) = 0;

    virtual ostream& put(ostream& os){
        os << typeid(*this).name() << ", ptr=[ ";
        for(int i= 0; i<len; i++){
            os << ptr[i] << " ";
        }
        os << "], ";
        return os;
    } 

    double& operator[](short i){
        return ptr[i % len];
    }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A{
    private:
    double alpha;
    public:
    B(short m, double d) : A(m){
        alpha = d;
    }

    double extract(short s){
        return (double)ptr[s%len]/alpha;
    }

    double const foo(short b){
        return log(1 + extract(b));
    }

    ostream& put(ostream& os){
        A::put(os);
        os << " alpha= "<< alpha << ", foo(5)= " << foo(5);
        return os;
    }
};

template <typename T>
class C : public A{
    private:
    T x;
    public:
    T const g(T k){
        return 3*k;
    }

    C(short n) : A(n){
        if(typeid(x) == typeid(short)){
            x = g(n);
        }else{
            x = log(1 + n);
        }
    }

    double const foo(short r){
        return g(r*x);
    }

    ostream& put(ostream& os){
        A::put(os);
        os << " x= "<< x << ", foo(5)= " << foo(5) << ", g(5)= "<< g(5);
        return os;
    }
};



int main(){
    srand(328832748);

    A* vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 5;
        switch (rand() % 3){
            case 0:
            vett[i] = new B(n, n / 100.0);
            break;
            case 1:
            vett[i] = new C<double>(n);
            break;
            case 2:
            vett[i] = new C<int>(n);
        }
    }

    //PUNTO1
    cout << endl << "PUNTO 1 "<< endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") "<< *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2 "<< endl;
    double max = 0;
    double somma = 0;
    for(int i=0; i<DIM; i++){
        if( max < ((C<double>*)vett[i])->foo(5)){
            max = ((C<double>*)vett[i])->foo(5);
        }
        if(typeid(*vett[i]) == typeid(C<double>)){
            somma += ((C<double>*)vett[i])->g(5);
        }
    }
    cout << "MAX= "<< max <<endl;
    cout << "SUM= "<< somma << endl;
    //PUNTO 3
    cout << endl << "PUNTO 3 "<< endl;
    cout << "vett(10) "<< *vett[10] << endl;
    (*vett[10])[2] = 0.478;
    cout << "(*vett[10])[2]= "<< *vett[10]<< endl;
}