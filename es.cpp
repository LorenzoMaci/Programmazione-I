#include <iostream>
#define DIM 10

namespace geometric{
    class Quadrato{
        private:
        double lato;
        public:
        Quadrato(double l){
            this->lato = l;
        }

        double area(){ return lato*lato; }
    };

    class Rettangolo{
        private:
        double base;
        double altezza;
        public:
        Rettangolo(double b, double h){
            this->base = b;
            this->altezza = h;
        }
        double area(){return base*altezza;}
    }
}

using namespace std;

class B{
    private:
    int p;
    int *vett;
    short len;
    public:
    B* operator++(int){
        p++;
        return this;
    }

    B* operator++(){
        ++p;
        return this;
    }

    int operator()(int i1, int i2){
        int somma = 0;
        for(int i=i1; i<=i2; i++){
            somma += vett[i];
        }
        return somma; 
    }

    int& operator[](short i){
        return vett[i % len];
    }
};

int main(){
    B* vec = new B[DIM];

    //postfissa
    cout << *vec[5] << endl;
    cout << *((*(dynamic_cast<B*>(vec[5])))++);

    //prefissa 
    cout << *vec[5] << endl;
    cout << *(++(*((B*)vec[5])));

    //operatore funcion call ()
    cout << (*vec[5])(2, 3)

    //operatore []
    cout << *vec[5] << endl;
    (*vec[5])[2] = 3;
    cout << *vec[5] << endl;

    geometric::Quadrato s(2);
    s.area();

    using geometric::Quadrato s1(2);
    s1.area();

    using namespace geometric; //permette di accedere a tutti gli altri simboli del namespace
    Quadrato s2(2);
    s2.area();

    //dynamic cast
    class A{};
    class B{void a()};
    class C{void d()};
    B b;
    C c;
    A* ptr = &b;
    C* ptr_c = dynamic_cast<C*>(ptr)->d();
    if(ptr_c){
        ptr_c->d()
    }

    if(typeid(ptr) == typeid(C)){
        ((C*)ptr)->d();
    }
}

int main(){
    int x;
    bool finito = false;
    int somma = 0;

    while(!finito){
        cout << "inserisci un numero intero oppure premi CTRL + Z: "<< endl;
        cin >> x;
        if(cin.eof()){
            finito = true;
        }else{
            somma += x;
        }
    }
    cout << somma << endl;
}