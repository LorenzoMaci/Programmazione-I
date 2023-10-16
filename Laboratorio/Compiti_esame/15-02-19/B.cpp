#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>
#define DIM 50

using namespace std;

class A{
    private:
    int x;
    public:
    A(int m){
        x = m;
    }

    virtual double v(int a)= 0;

    virtual ostream& put(ostream& os){
        os << typeid(*this).name() << ", x=" << x << ", ";
        return os;
    }
};

class B: public A{
    private:
    int* ptr;
    int l;
    public:
    B(int z, int y) : A(z){
        this->l = y;
        ptr = new int[l];
        for(int i =0; i < l; i++){
            ptr[i] = rand()%(100 - 1) + 1; 
        }
    }

    double v(int a){
        return 1*1000/(sum(a)+1);
    }

    ostream& put(ostream& os){
        A::put(os);
        os << " ptr=[ ";
        for(int i= 0; i<l; i++){
            os << ptr[i] << " ";
        }
        os << "], v(50)= "<< v(50);
        return os;
    }

    int& operator[](short i){
        return ptr[i % l];
    }

    protected:
    int sum(int t){
        int sum = 0;
        for(int i=0; i<l; i++){
            if(ptr[i]<= t){
                sum += ptr[i];
            }
        }
        return sum;
    }
};

template<typename T>
class C : public A{
    private:
    T k;
    public:
    C(int n) : A(n){
        if(typeid(k) == typeid(int)){
            k = 2*n;
        }else{
            k = log( 1 + (sin(n))*(sin(n)));
        }
    }

    T g(T w){
        return k*(w+1);
    }

    double v (int r){
        return g(r);
    }

    ostream& put(ostream& os){
        A::put(os);
        os << " k=" << k << ", v(50)= "<< v(50);
        return os;
    }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for(int i=0; i<DIM; i++) {
        int n= 1+rand()%10;
	    switch(rand()%3) {
            case 0: 
	        vett[i]= new B(n, rand()%10 + 1);
	        break;
	        case 1:
	        vett[i]= new C<int>(n);
	        break;
	        case 2: 
	        vett[i]= new C<double>(n);
	    }
    }

    //PUNTO 1
    cout << endl << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << "), "<< *vett[i]<< endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    int min = 1000;
    int max = 0;
    double somma = 0;
    int counter;
    for(int i=0; i<DIM; i++){
        if(max < ((C<double>*)vett[i])->v(50)){
            max = ((C<double>*)vett[i])->v(50);
        }
        if(min > ((C<double>*)vett[i])->v(50)){
            min = ((C<double>*)vett[i])->v(50);
        }
        if(typeid(*vett[i])== typeid(C<double>)){
            somma += ((C<double>*)vett[i])->g(5);
            counter++;
        }
    }
    cout << " max V(50)= " << max << endl;
    cout << " min V(50)= " << min << endl;
    cout << " media = "<< somma/counter;

    //PUNTO 3
    cout << endl<< "PUNTO 3" <<endl;
    cout << (*vett[5]) << endl;
    for(int i=0; i<DIM; i++){
        ((B*)vett[i])->operator[](10) = 1000;
    }
    cout << (*vett[5]) << endl;

}