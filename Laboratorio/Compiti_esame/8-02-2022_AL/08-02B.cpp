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
    A(short w, char c1, char c2){
        this->len = w;
        str = new char[len];
        for(int i=0; i<len; i++){
            str[i] =  rand() % (c2 - c1 + 1) + c1;
        }
    }

    virtual short f(short k) = 0;

    virtual ostream& put(ostream& os) = 0;

    string operator()(int i1, int i2){
        i1 = abs(i1);
        i2 = abs(i2);
        i1 %= len;
        i2 %= len;
        string y = "";
        if(i1 <= i2){
            for(int i= i1; i <= i2; i++){
                y += str[i];
            }
        } else{
            for(int i= i2; i <= i1; i++){
                y += str[i];
            }
        }
        return y;
    }

    protected: 
    /*string extract (short k){
        string r = "";
        if(k >= len){
            k = 0;
        }
        for(int i = len - 1; i >= k; i--){ //Stringa formata dagli ulitmi k caratteri di str
            r = str[i] + r;
        }
        return r;
    }*/

    string extract(short k){
        string r = "";
        for(int i = 0; i < len ; i++){ //Stringa formata dagli ulitmi k caratteri di str
            r += str[i];
        }
        if(k >= len){
            return r;
        }
        return r.substr(len - k, len);
    }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A{
    private:
    char z;
    public:
    B(short m, char c1, char c2) : A(m, c1, c2){
       string s = extract(m/2+1);
       z = s[rand() % s.length()];
    }

    short f(short k){
        short c = 0;
        string l = extract(k);
        for(int i=0; i< l.length(); i++){
            if(l[i] <= z){
                c++;
            }
        }
        return c;
    }

    ostream& put(ostream& os){
        os << "B str=[ "<< extract(1000) << "], z= " << z;
        return os;
    }
};

template<typename T>
class C : public A{
    private:
    T ss;
    public:
    C(short w, char c1, char c2) : A(w, c1 ,c2){
        if(typeid(ss) == typeid(short)){
            ss = w;
        }else{
            string p = extract(w/2+1);
            for(int i = 0; i< p.length(); i++){
                ss += p[i];
            }
        }
    }

    short f (short k){
        string r = extract(k);
        for(int i = 0; i<r.length(); i++){
            if(r[i] >= 'A' && r[i] <= 'Z'){
                return 1;
            }
        }
        return 0;
    }

    T foo(short x){
        T rr = ss;
        for(int i = 1; i< x; i++){ //partiamo da 1 perchè gia il primo c'è ovvero rr classico
            rr += ss;
        }
        return rr;
    }

    ostream& put(ostream& os){
        if(typeid(ss) == typeid(short)){
            os << "C<short> ";
        }else{
            os << "C<string> ";
        }
        os << "str=[ "<< extract(1000) << "], ss= "<< ss;
        return os;
    }
};


int main (){
    srand(12345678);

    A*vec[DIM];

    for(unsigned int i = 0; i< DIM; i++){
        int r = rand();
        if(r % 3 == 0){
            vec[i] = new B(rand() % 10 + 5, '0', '9');
        }
        else if(r % 3 == 1){
            vec[i] = new C<string>(rand() % 10 + 5, 'a', 'z');
        }
        else{
            vec[i] = new C<short>(rand() % 10 + 5, 'A', 'Z');
        }
    }

    //punto 1
    cout << endl << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ") " <<  *vec[i] << endl;
    }

    //PUNTO2    
    cout << endl << "PUNTO 2 "<<endl;
    short count = 0;
    short somma = 0;
    for(int i=0; i<DIM; i++){
        if(vec[i]->f(5) >= 4){
            count++;
        }
        if(typeid(*vec[i]) == typeid(C<short>)){
            somma += ((C<short>*)(vec[i]))->foo(3);
        }
    }
    cout << "f(5) <= 4" << count << endl;
    cout << "foo(3)= "<<somma; 
    //PUNTO 3
    cout << endl << "PUNTO 3" << endl;
    cout << *vec[9] << endl;
    cout << (*vec[9])(3, 5)<<endl; 
}