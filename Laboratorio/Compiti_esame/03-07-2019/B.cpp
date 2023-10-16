#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<typeinfo>

#define DIM 50  

using namespace std;

class A {
    private:
        char* s;
        short len;

    public:
        A(short m){
            this->len = m;
            s = new char[len];
            for(int i = 0; i<len; i++){
                s[i] = rand() % ('z' - 'a' + 1) + 'a';
            }
        }

        virtual double elab(short a) = 0;

        short getLen(){
            return len;
        }

        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", s= ";
            for(int i = 0; i<len; i++){
                os << s[i];
            }
            os << ", ";
            return os;
        }

    protected:
        char get(short i){
            return s[i % len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
    private:
        int p;

    public:
        B(short m, int x) : A(m){
            p = x;
        }

        double elab(short a){
            int V = 0;      //contatore vocali
            int C = 0;      //contatore consonanti
            for(int i = 0; i<getLen(); i++){
                if(get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u' || get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U'){
                    V++;
                }
                else{
                    C++;
                }
            }
            return (double)V/(C + 1);
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "p=" << p << ", elab(3)=" << elab(3);
            return os;
        }

        B* operator++(int){
            p++;
            return this;
        }

    protected:
        bool test(){
            for(int i = 0; i<4; i++){
                if(get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u'){
                    return true;
                }
            }
            return false;
        }
};

class C : public A {
    private:
        char x;

    public:
        C(short n, char c) : A(n){
            x = c;
        }

        double elab(short r){
            int counter = 0;
            for(int i = (r % getLen()); i<getLen(); i++){
                if(get(i) >= x){
                    counter++;
                }
            }
            return (double)counter/getLen();
        }

        string g(char c){
            string xc = "";
            xc += x;
            xc += c;
            return xc;
        }

        ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", elab(3)=" << elab(3);
            return os;
        }
};


int main(){
    srand(111222333);
    A *vett[DIM];
    for(int i=0; i<DIM; i++) {
        short n=1+rand()%10;
        if(rand()%2==0){
            vett[i]= new B(n, rand()%10 + 1);
        }else{
            vett[i]= new C (n, (char) (rand()%((int) 'z' - (int) 'a' + 1) + (int) 'a'));
        }
	}

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i<DIM; i++){
        cout << i << ") " << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double somma = 0;
    string concat = "";
    for(int i = 0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(C)){
            concat += ((C*)(vett[i]))->g('h');
        }
        somma += vett[i]->elab(3);
    }
    cout << "Avg(elab(3))=" << (double)somma/DIM << ", concat=" << concat << endl;

    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << "5): " << *vett[5] << endl;
    cout << "5): " << *((*(dynamic_cast<B*>(vett[5])))++) << endl;
}
