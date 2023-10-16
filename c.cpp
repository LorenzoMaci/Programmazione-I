#include <iostream>
using namespace std;

class Animale {
    public:
        virtual void parla() = 0;
};

class Cane: public Animale {
    public:
        void parla() {cout << "bau"<<endl;}
};

class Gatto: public Animale {
    public:
        void parla() {cout << "miao"<<endl;}
};

int main(){
    Animale *a;
    string animale = "gatto";

    if(animale=="gatto")
        a =  new Gatto();
    else if(animale=="cane")
        a = new Cane();

    a->parla();
}