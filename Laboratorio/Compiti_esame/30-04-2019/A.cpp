#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>
#define DIM 50  

using namespace std;

class A{
    private:
    char *str;
    short len;
    public:
    A(short m, string source){
        this->len = m;
        str = new char[len];
        for(int i=0; i<len; i++){
            str[i] = source[rand()%source.length()];
        }
    }

    virtual char func(short i) = 0;

    short getLen(){
        return len;
    }

    virtual ostream& put(ostream& os){
        os << typeid(*this).name() << ", str= ";
        for(int i=0; i<len; i++){
            os << str[i];
        }
        os << " , ";
        return os;
    }

    string operator()(int i1, int i2){
        string temp = "";
        for(int i= i1; i<=i2; i++){
            temp += str[i];
        }
        return temp;
    }

    protected: 
    char get(short i){
        return str[i % len]; 
    }

};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A{
    private:
    short p;
    public:
    B(short m, string source) : A(m, source){
        int vocali = 0;
        for(int i=0; i<getLen(); i++){
            if(get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u'
            || get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U'){
                vocali++;
            }
        }
       p = ++vocali;
    }

    char func(short i){
        char temp = 'X';
        for(int j=i; j<getLen(); j++){
            if(get(j) != 'a' || get(j) != 'e' || get(j) != 'i' || get(j) != 'o' || get(j) != 'u'
            || get(j) != 'A' || get(j) != 'E' || get(j) != 'I' || get(j) != 'O' || get(j) != 'U'){
                temp = get(j);
                return temp;
            }
        }
        return temp;
    }

    ostream& put(ostream& os){
        A::put(os);
        os << "p=" << p << ", func(3)="<<func(3);
        return os;
    }

};

class C : public A{
    private:
    char x;
    public:
    C(short n, string source, char y) : A(n, source){
        x = y;
    }

    char func(short i){
        for(int j = i; j < getLen(); j++){
            if(get(j) > x){
                return get(j);
            }
        } 
        return x;
    }

    string g(char c){
        string r = "";
        r += x;
        for(int i=0; i<getLen(); i++){
            r += get(i);
        }
        r += c;
        return r;
    }

    ostream& put(ostream& os){
        A::put(os);
        os << "x=" << x << ", func(3)=" << func(3);
        return os;
    }

};

int main(){
    srand(111222333);

    A* vett[DIM];

    string S = "supercalifragilistichespiralidoso";
    for(int i = 0; i < DIM; i++){
        short n = 3 + rand() % 10;
        if(rand() % 2 == 0)
            vett[i] = new B(n, S);
        else
            vett[i] = new C(n, S, (char)(rand() % ( 'z' - 'a' + 1) + 'a'));
        }

    //Punto 1
    cout << endl << "Punto 1: "<<endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //Punto 2
    cout << endl << "Punto 2: " << endl;
    string concat = "";
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(C)){
            concat += ((C*)vett[i])->g('h');        
        }
    }
    cout << "concat= "<< concat << endl;

    //Punto 3
    cout << endl << "Punto 3: "<< endl;
    cout << "vett[10]= " <<  *vett[10] << endl;
    cout << "vett[10](2, 3)=" << (*vett[10])(2, 3) << endl;
}
