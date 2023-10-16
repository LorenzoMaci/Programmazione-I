/*Si costruisca una classe Cerchio che metta a disposizione metodi per calcolare il perimetro e l’area.*/

#include <iostream>

using namespace std;

class Cerchio{
    public:
    double r;          //raggio

    double area(){
        return r*r*3.14;
    }

    double perimetro(){
        return 2*r*3.14;
    }
};

class Rettangolo{
    public:
    double b;
    double a;
    double perimetro(){return (b+a)*2;}
    double area(){return (b*a);}
};

bool encloses(Rettangolo rettangolo1, Cerchio cerchio1){
     double i = ((rettangolo1.b*rettangolo1.b) + (rettangolo1.a*rettangolo1.a))/2;
     double j = ((cerchio1.r)*3.14);
     if(i >= j){
         return true;
     }
     return false;
}

int main(){
    cout << endl << "La mia classe rettangolo" << endl;
    Rettangolo rettangolo1;

    //imposto valori rettangolo
    rettangolo1.b = 5;
    rettangolo1.a = 7;

    cout << "L'area del mio rettangolo vale: " << rettangolo1.area() << endl;
    cout << "Il perimetro del mio rettangolo vale: " << rettangolo1.perimetro() << endl;
    cout << endl;

    cout << "La mia classe Cerchio" << endl;
    Cerchio cerchio1;

    //imposto valori cerchio
    cerchio1.r = 3;

    cout << "L'area del mio cerchio vale: " << cerchio1.area() << endl;
    cout << "Il perimetro del mio cerchio vale: " << cerchio1.perimetro() << endl;
    cout << endl;

    cout << "Il mio rettangolo è completamente contenuto all'interno del cerchio? ";
    if(encloses(rettangolo1,cerchio1)){
        cout << "Si" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
