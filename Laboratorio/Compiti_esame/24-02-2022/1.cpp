#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <typeinfo>

#define DIM 10

using namespace std;

template <typename T>
class AbstractVec{
    private:
    T** data;

    protected:
    int max_size;
    int read_index;
    int write_index;

    T* get(int index){
        return data[index];
    }

    bool exists(int index){
        if(data[index] != nullptr){
            return true;
        }
        return false;
    }

    void set(int i, T x){
        if(data[i]){
            *data[i] = x;
        }
        else{
            data[i] = new T(x);
        }
    }

    public:
    AbstractVec(int max_size){
        this->max_size = max_size;
        read_index, write_index = 0;
        data = new T*[max_size];
        for(int i=0; i<max_size; i++){
            data[i] = nullptr;
        }
    }

    virtual T* next() = 0;

    virtual bool insert(T x) = 0;

    int len(){
        int counter = 0;
        for(int i=0; i<max_size; i++){
            if(data[i]){
                counter++;
            }
        }
        return counter;
    }

    void shuffle(){
        for(int i=0; i<max_size; i++){
            if(data[i]){
                T* temp = nullptr;
                int index = 0;
                while(temp == nullptr || temp == data[i]){
                    index = rand()%max_size;
                    temp = data[index];
                }
                data[index] = data[i];
                data[i] = temp;
            }
        }
    }

    double mean(){
        double somma = 0;
        int counter = 0;
        for(int i=0; i<max_size; i++){
            if(data[i]){
                somma += *data[i];
                counter++;
            }
        }
        return (double)somma/counter;
    }

    virtual ostream& put(ostream& os){
        os << "Class=" << typeid(*this).name() << ", max_size= "<< max_size << ", vec=[";
        for(int i=0; i<max_size; i++){
            if(data[i]){
                os << *data[i] << " ";
            }
            else{
                os << '\0';
            }
        }
        os << "], len()= "<< len() << ", mean()= " << mean();
        return os;
    }
};

template<typename T>
ostream& operator<<(ostream& os, AbstractVec<T>& obj){
    return obj.put(os);
}

template<typename T>
class PlainVec : public AbstractVec<T>{
    public:
    PlainVec(int max_size) : AbstractVec<T>(max_size){}

    T* next(){
        if(AbstractVec<T>::read_index <= AbstractVec<T>::max_size - 1){
            return AbstractVec<T>::get(AbstractVec<T>::read_index++);
        }
        return nullptr;
    }

    bool insert(T x){
        if(AbstractVec<T>::write_index <= AbstractVec<T>::max_size - 1){
            AbstractVec<T>::set(AbstractVec<T>::write_index++, x);
            return true;
        }
        return false;
    }

    ostream& put(ostream& os){
        AbstractVec<T>::put(os);
        return os;
    }
};

template<typename T>
class CircularVec : public AbstractVec<T>{
    public:
    int cycles;

    CircularVec(int max_size) : AbstractVec<T>(max_size){
        cycles = 0;
    }

    T* next(){
        T* temp = AbstractVec<T>::get(AbstractVec<T>::read_index++);
        if(AbstractVec<T>::read_index == AbstractVec<T>::max_size){
            AbstractVec<T>::read_index = 0;
            cycles++;
        }
        return temp;
    }

    bool insert(T x){
        AbstractVec<T>::set(AbstractVec<T>::write_index++, x);
        if(AbstractVec<T>::write_index == AbstractVec<T>::max_size){
            AbstractVec<T>::write_index = 0;
            cycles++;
        }
        return true;
    }

    int getCycles(){
        return cycles;
    }

    ostream& put(ostream& os){
        AbstractVec<T>::put(os);
        os << "cycles="<<cycles << endl; 
        return os;
    }
};

int main(){
    srand(424242);

    AbstractVec<int>* vec[DIM];

    for(int i = 0; i<DIM; i++){
        int size = rand()% 16 + 5;
        if(rand() % 2){
            vec[i] = new PlainVec<int>(size);
        }
        else {
            vec[i] = new CircularVec<int>(size);
        }
    }

    for(int i = 0; i<DIM * 5; i++){
        int x = rand() % 100;
        vec[x % DIM]->insert(x);
    }

    for(int i = 0; i<DIM; i++){
        vec[i]->shuffle();
    }

    //Punto 1
    cout << endl << "Punto 1: "<< endl;
    for(int i=0; i<DIM; i++){
        cout << i << "), " << *vec[i] << endl;
    }

    //Punto 2
    cout << endl << "Punto 2: " << endl;
    int min = 999999;
    for(int i=0; i<DIM; i++){
        if(min > vec[i]->len()){
            min = vec[i]->len();
        }
    }
    cout << "MINIMO= "<< min << endl;

    //Punto 3
    cout << endl << "Punto 3: "<< endl;
    double max = 0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vec[i]) == typeid(PlainVec<int>)){
            if(((PlainVec<int>*)vec[i])->mean() > max){
                max = dynamic_cast<PlainVec*>
            }
        }
    }
    cout << "MAX= "<< max << endl;
}



