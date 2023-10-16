#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <typeinfo>
#define DIM 50

using namespace std;


class A{
    private:
    char* ptr;
    short len;
    public:
    A(short m, char c){
        int min = 'a';
        int max = c;
        ptr = new char[m];
        for(int i = 0; i<m; i++){
            ptr[i] = (char)(rand() % ( max - min + 1) + min);
        }
        len = m;
    }

    virtual string elab (short a, char c) = 0;

    short getLen() {
        return len;
    }

    virtual ostream& put(ostream& os){
        os << "ptr=[";
        for(int i=0; i<len; i++){
            os << ptr[i] << " ";
        }
        os << "], ";
        return os;
    }

    char& operator[](short i){
        return ptr[i % len];
    }

    protected:
    char get(short i){
        return ptr[i % len];
    }

};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}


class B : public A{
    private: 
    double x;
    public: 
    B(short m, double y, char c) : A(m, c){
        y = x;
    }

    double foo(short s){
        return (double)sin(x+s)/log(x+s);
    }

    string elab(short a, char c){
        string r = "";
        for(int i=0; i<getLen(); i++){
            if(abs(get(i) - c) <= a){
                r += get(i);
            }
        }
        return r;
    }

    ostream& put(ostream& os){
        A::put(os);
        os << "x= "<< x << "elab(5, z)=" << elab(5, 'z');
        return os;
    }
};

template<typename T>
class C : public A{
    private:
    T y;
    public:
    C(short n, double k, char c) : A(n, c){
        if(typeid(y) == typeid(short)){
            y = (100*k) + 0.5;
        }else{
            y = k;
        }
    }

    string elab(short a, char c){
        string r = "";
        if(getLen() >= a){
            for(int i=0; i< a; i++){
                r += c;
            }
        }else{
            for(int i=0; i<getLen(); i++){
                r += c;
            }
        }
        return r;
    }

    double g (short w){
        return sin(w+y);
    }

    ostream& put(ostream& os){
        A::put(os);
        os << "y= "<< y << "elab(5, z)=" << elab(5, 'z');
        return os;
    }
};

int main(){
    srand(111222333);

    A* vett[DIM];

    for(int i=0; i<DIM; i++){
        short n=1+rand()%10;
        switch(rand()%3){
            case 0:
            vett[i] = new B(n, (double) rand()/RAND_MAX, rand()%('z' - 'a' + 1) + 'a');
            break;
            case 1:
            vett[i] = new C<double>(n, (double) rand()/RAND_MAX, rand()%('z' - 'a' + 1) + 'a');
            break;
            case 2:
            vett[i] = new C<short>(n, (double) rand()/RAND_MAX, rand()%('z' - 'a' + 1) + 'a'); 
        }
    }

    //punto 1
    cout << endl << "PUNTO 1 "<<endl;
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(B)){
            cout << "B ";
        }else if(typeid(*vett[i]) == typeid(C<short>)){
            cout << "C<short> ";
        }else{
            cout << "C<double> ";
        }
        cout << *vett[i] << endl;
    }

    //punto 2
    cout << endl << "Punto 2 "<< endl;
    double somma1 = 0;
    double somma2 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(B)){
            somma1 += ((B*)vett[i])->foo(5);
            count1++;
        }
        else if(typeid(*vett[i]) == typeid(C<short>)){
            somma2 += ((C<short>*)vett[i])->g(5);
            count2++;
        }
    }
        cout << " avg(foo(5))= "<< somma1/count1 << " avg(g(5))= " << somma2/count2 << endl;
    
    //punto 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vett[0] << endl;
    (*vett[0])[0] = '*';
    cout << *vett[0] << endl;
}