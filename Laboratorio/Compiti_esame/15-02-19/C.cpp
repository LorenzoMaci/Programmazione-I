#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <typeinfo>
#define DIM 50

using namespace std;

class A{
    private:
    char* str;
    short len;
    public:
    A(short m){
        this->len = m;
        for(int i=0; i<len; i++){
            str[i] = (char)(rand()%('z' -'a' + 1) + 'a');
        }
    }

    virtual double elab(short a) = 0;
    
    short getLen(){
        return len;
    }

    virtual ostream& put(ostream& os){
        os << typeid(*this).name() << ", w= ";
        for(int i=0; i<len; i++){
            os << str[i] << " ";
        }
        os << ", ";
        return os;
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
    int p;
    protected:
    short* map(){
        short* ritorno = new short[getLen()];
        for(int i=0; i<getLen(); i++){
            if(get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U'
            || get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u'){
                ritorno[i] = 0; 
            }else{
                ritorno[i] = 1;
            }
        }
        return ritorno;
    }
    public:
    B(short m, int x) : A(m){
        p = x;
    }

    double elab (short a){
        short* sum = 0;
        sum += map();
        int temp = p/a;
        return sum/temp;
    }

    ostream& put(ostream& os){
        A :: put(os);
        os << " elab(3)= " << elab(3);
        return os;
    }
};

class C : public A{
    private:
    char x;
    public:
    C(short n, char c) : A(n){
        x = c;
    }

    double elab(short r){
        int temp = 0;
        int lunghezza = (get(r))->length();
        for(int i =0; i >= x; i++){
            temp = get(r);
        }
        return temp/lunghezza;
    }

    string g(char c){
        string s = x;
        string r += s;
        return r;
    }

    ostream& put(ostream& os){
        os << " x= "<< x << ", elab(3)="<< elab(3);
    }
};


int main(){
    srand(111222333);

    A *vett[DIM];

    for(int i=0; i<DIM; i++) {
	    short n=1+rand()%10;
	if(rand()%2==0)
	    vett[i]= new B(n, rand()%10 + 1);
	else
	    vett[i]= new C(n, (char) (rand()%('z' - 'a' + 1) + 'a'));
	}


}