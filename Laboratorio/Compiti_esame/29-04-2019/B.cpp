#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>
#define DIM 50

using namespace std;

class A{
    int *vec;
    short len;
    public:
    A(short m, int a, int b){
        this->len = m;
        vec = new int[len];
        for(int i=0; i<len; i++){
            vec[i] = rand()%(b - a + 1) + a;
        }
    }

    virtual double foo(short a) = 0;

    short getLen(){
        return len;
    }

    virtual ostream& put(ostream& os){
        os << typeid(*this).name() << ", vec=[";
        for(int i=0; i<DIM; i++){
            os << vec[i] << " ";
        }
        os << "], ";
        return os;
    }

    int& operator[](short i){
        return vec[i % len];
    }

    protected:
    int get(short i){
        return vec[i % len];
    }

};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A{
    private:
    int p;

    protected:
    int prod(short s){
        int prodotto = 1;
        for(int i = s; i<getLen(); i++){
            prodotto *= get(i);
        }
        return prodotto;
    }

    public:
    B(short m, int x, int y) : A(m, x, y){
        int rnd = rand()%getLen();
        p = get(rnd);
    }

    double foo(short a){
        return prod(a)/p;
    }    

    ostream& put(ostream& os){
        A::put(os);
        os << " p= "<< p << ", foo(3)= "<< foo(3);
        return os;
    }
};  

template<typename T>
class C : public A{
    private:
    T x;
    public:
    C(short n, int a, int b) : A(n, a, b){
        if(typeid(x) == typeid(short)){
            x = n;
        }else{
            x = log(1 + pow(sin(n), 2));
        }
    }

    T g(T k){
        return 2*x*(k + 1);
    }

   double foo(short r){
        return g(r);
    }

    ostream& put (ostream& os){
        A::put(os);
        os << " x= "<< x << ", foo(3)= " <<foo(3);
        return os;
    }

};

int main(){
    srand(111222333);

    A* vett[DIM];

    for(int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 1:
            vett[i] = new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 2:
            vett[i] = new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
        }
    }

    //Punto 1
    cout << endl << "Punto 1: "<<endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") "<< *vett[i] << endl;
    }

    //Punto 2
    cout << endl << "Punto 2: "<< endl;
    int max = 0;
    int somma = 0;
    int counter = 0;
    for(int i=0; i<DIM; i++){
        if(max < vett[i]->foo(3)){
            max = vett[i]->foo(3);
        }
        if(typeid(*vett[i]) == typeid(C<double>)){
            somma += ((C<double>*)vett[i])->g(5);
            counter++;
        }
    } 
    cout << "Max= "<< max << ", media= "<<(double)somma/counter;

    //Punto 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[32] << endl;
    (*vett[32])[5] = 0;
    cout << *vett[32] << endl;
}
