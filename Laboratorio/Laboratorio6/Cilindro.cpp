#include <iostream>
#include <cmath>
using namespace std;

class Cilindro {
    private: 
    double raggio;
    double altezza;
    public:
        Cilindro(double a, double b) : raggio(a), altezza(b){}
        double getraggio(){return raggio;}
        double getaltezza(){return altezza;}
        void setraggio(double a) {raggio = a;}
        void setaltezza(double b) {altezza = b;}
        double volume(){return ((raggio*raggio) *3.14)*altezza;}
};

int main(){
    Cilindro r(1.2, 2.2);
    cout << r.volume() << endl;
    r.setraggio(5.8);
    cout << r.volume()<< endl;
}