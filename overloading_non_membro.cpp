//overloading operator + non membro
#include<iostream>
using namespace std;

class Point2D {
    double x, y;
    public:
        Point2D(double a, double b) : x(a), y(b) {}
        double getX() {return x;}
        double getY() {return y;}
};

Point2D operator+(Point2D a, Point2D b){
    return Point2D(a.getX()+b.getX(), a.getY()+b.getY());
}

int main() {
    Point2D p1(2,3);
    Point2D p2(3,3);

    Point2D p3 = p1+p2;
    cout << "("<<p3.getX() << "," << p3.getY() << ")" << endl;
}

