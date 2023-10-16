#include <iostream>

using namespace std;

int func(int a){
    int* arr = new int[a];
    return;
}

int main(){
    int b = 10;
    cout << func(b) << endl;
}