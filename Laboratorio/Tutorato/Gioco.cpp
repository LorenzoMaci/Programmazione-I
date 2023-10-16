#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <typeinfo>

using namespace std;

template<typename T>    
class Character{
    private:
    T ***power;
    protected:
    int rows;
    int columns;
    
    T** getColum(int index){
        T** arr = new T*[columns];
        for(int i=0; i<rows; i++){
            power[i] = power[i][index];
        }
    }

    public:
    Character(int rows, int columns){
        this->columns = columns;
        this->rows = rows;
        power = new T**[rows];
        for(int i=0; i<rows; i++){
            power[i] = new T*[columns];
            for(int j=0; j<columns; j++){
                power[i][j] = new T((T)(rand()) / RAND_MAX);
            }
        }
    }

    void traspose(){
        T pt[rows][columns];
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
              
            }
        }
    }

}