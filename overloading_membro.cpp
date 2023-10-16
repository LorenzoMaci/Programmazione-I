//funzione membro
//Overloading dell'operator prevede un paramentro formale 
#include <iostream>

using namespace std;

class Vettore3D{
    float x, y ,z;
    public:
    Vettore3D(float a, float b, float c) : x(a), y(b), z(c){}
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }

    float getZ(){
        return z;
    }

    Vettore3D operator+(Vettore3D f){
        return Vettore3D(f.x + x, f.y+y, f.z+z);
    };
};

int main(){
    Vettore3D a(1,2,3);
    Vettore3D b(3.4, 2.3, 5);

    Vettore3D c = a.operator+(b);
    cout << c.getX() << " " << c.getY() << " "<< c.getZ() << endl;
    Vettore3D d = a + b;    
}