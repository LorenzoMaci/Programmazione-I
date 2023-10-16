#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>
#define DIM 50

using namespace std;

class A{
    private:
    double* w;
    short len;
    public:
    A(short m){
        this->len = m;
        w = new double[len];
        for(int i=0; i<len; i++){
            w[i] = 0 + (rand()/(double)RAND_MAX*(1 - 0));
        }
    }
    virtual double foo(short a) = 0;

    short getLen(){
        return len;
    }

    virtual ostream& put(ostream& os){
        os << typeid(*this).name() << ", w=[";
        for(int i = 0; i<len; i++){
            os << w[i] << " ";
        }
        os << "], ";
        return os;
    }

    double& operator[](short i){
        return w[i % len];
    }

    protected:
    double get(short i){
        return w[i % len];
    }
}; 

ostream& operator<<(ostream&os, A& obj){
    return obj.put(os);
}



class B : public A{
    private:
    int p;
    protected:
    double sum(short s){
        double sum = 0;
        for(int i=0; i<getLen(); i++){
            sum += get(s);
        }
        return sum;
    }   
    public:
    B(short m, int x) : A(m){
        p = x;
    }

    double foo (short a){
        return sum(a)/p;
    }

    ostream& put(ostream& os){
        A::put(os);
        os << " p=" << p << ", foo(3)= " << foo(3);
        return os;
    }
};

template<typename T>
class C : public A{
    private:
    T x;
    public:
    C(short n) : A(n){
        if(typeid(x) == typeid(short)){
            x = n;
        }else{
            x = log(1+(sin(n))*(sin(n)));
        }
    }
    
    T g (T k){
        return 2*x*(k+1);
    }

    double foo(short r){
        return g(r);
    }

    ostream& put(ostream& os){
        A::put(os);
        os << " x=" << x << ", foo(3)= " << foo(3);
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
	        vett[i]= new B(n, rand()%10 + 1);
	        break;
	        case 1:
	        vett[i]= new C<double>(n);
	        break;
	        case 2: 
	        vett[i]= new C<short>(n);
	    }
    } 

    //PUNTO 1
    cout << endl << "PUNTO 1 "<<endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") "<< *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2 "<<endl;
    double max = 0;
    double somma = 0;
    int counter = 0;
    for(int i=0; i<DIM; i++){
        if(max < ((C<double>*)vett[i])->foo(3)){
            max = ((C<double>*)vett[i])->foo(3);
        }
        if(typeid(*vett[i]) == typeid(C<double>)){
            somma += ((C<double>*)vett[i])->g(5);
            counter++;
        }
    }
    cout << " MAX = "<<max << endl;
    cout << " media= "<< somma/counter << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3 "<<endl;
    cout << "vett(10) "<< *vett[10] << endl;
    (*vett[10])[2] = 0.478;
    cout << "(*vett[10])[2]= "<< *vett[10]<< endl;
}