#include<iostream>
#include<typeinfo>
#include<climits>
#include<cmath>
#include<cstdlib>
#define DIM 50

using namespace std;

class A{
    private:
        char *base;
        short len;

    public:
    A(short m){
        len = m;
        base = new char[len];
        for(int i=0; i<len; i++){
            base[i] = rand()%('z' - 'a' + 1 )+ 'a';
        }
    }

    virtual string extract(short x) = 0;

    short getLen(){
        return len;
    }

    ostream& put(ostream& os){
        os << typeid(*this).name() << ", base[";
        for(int i=0; i<len; i++){
            os << base[i] << " ";
        }
        os << "], ";
        return os;
    }

    protected:
    char get(short i){
        return base[i % len];
    }

};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A{
    private:
    string str;
    double k;
    public:
    B(short m, double p) : A(m){
        k = p;
        string r = "";
        for(int i=0; i<getLen(); i++){
            if(get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u'
            || get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U'){
                r += get(i);
            }
        }
        str = r;
    }

    double foo(short s){
        return sin(k+s)/log(s+1);
    }

    string extract(short x){
        string r = "";
        for(int i= 0; i<x; i++){
            r += get(rand()%getLen());
        }
        return r;
    }

    ostream& put(ostream& os){
        A::put(os);
        os << "str= "<< str << ", k= "<< k << " ,extract(3)= " << extract(3);
        return os;
    }
};

class C : public A{
    private:
    int y;
    public:
    C(short n, int k) : A(n){
        y = k;
    }

    string extract(short x){
        string r = "";
        int counter = 0;
        for(int i=0; i<getLen(); i++){
            if(counter < x && get(i) != 'a' || get(i) != 'e' || get(i) != 'i' || get(i) != 'o' || get(i) != 'u' 
            || get(i) != 'A' || get(i) != 'E' || get(i) != 'I' || get(i) != 'O' || get(i) != 'U'){
                r += get(i);
                counter++;
            }
        }
        return r;
    }

    short g(short w){
        return sin(w + y);
    }


    ostream& put(ostream& os){
        A::put(os);
        os << "y= " << y << " ,extract(3)= "<< extract(3);
        return os;
    }

    C* operator++(int){
        y++;
        return this;
    }
};

int main(){
    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 10 + rand() % 10;
        switch (rand() % 2){
        case 0:
            vett[i] = new C(n, rand() % 20 + 1);
            break;
        case 1:
            vett[i] = new B(n, rand() / (double)RAND_MAX);
            break;
        }
    }

    //PUNTO 1
    cout << endl <<  "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //Punto 2
    cout << endl << "Punto 2" << endl;
    double somma = 0;
    int counter = 0;
    for(int i=0; i<DIM; i++){
        somma += ((B*)(vett[i]))->foo(5);
        somma += ((C*)(vett[i]))->g(5);
    }
    cout << "avg(g() + foo())= "<< somma/DIM <<endl;

    //Punto 3
    cout << endl << "Punto 3: "<< endl;
    cout << "8): "<< *vett[8] << endl;
    *((*(dynamic_cast<C*>(vett[8])))++);
    cout << "vett[8]=" << *vett[8] << endl;

}