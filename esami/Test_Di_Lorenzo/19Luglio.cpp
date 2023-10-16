/*Scrivere una funzione che prende in input un array di puntatori 
a float A di dimensione n e un flaot f e restituisca un valore booleano
che sia pari a true se l'Array A contine almeno [n/2] elementi la cui
differenza in valore assoluto da ciascun altro elemento di A non sia superiore
a fx(b - a)/2, dove a e b sono rispettivamente il minimo e il massimo valore di A.
NB: si presenti attenzione ai puntatori null!.*/

#include <iostream>
#include <cfloat>
#include <cmath>

using namespace std;

bool es1(float** A, int n, float f){
    float a = DBL_MAX;
    float b = DBL_MIN;

    for(int i=0; i<n; i++){
        if(A[i]){
            if(*A[i] < a){
                a = *A[i];
            }
            if(*A[i] > b){
                b = *A[i];
            }
        }
    }

    int counter_condizione=0;
    for(int i=0; i<n; i++){
        int counter_valore_assoluto = 0;
        int counter_nulli = 0;
        for(int j= 0; j<n; j++){
            if(A[i] && A[j] && i != j){
                counter_nulli++;
                if(fabs(*A[i] - *A[j]) <= (f*(b - a)/2)){
                    counter_valore_assoluto++;
                }
            }
        }
        if(counter_valore_assoluto == counter_nulli){
            counter_condizione++;
        }
    }
    if(counter_condizione >= n/2){
        return true;
    }
    return false;
}

void Stampa_Matrice(float** A, int n){
    cout << "MATRICE: "<<endl << endl;
    for(int i=0; i<n; i++){
        if(A[i]){
            cout << *A[i] << " \t";
        }else{
            cout << " \t";
        }
    }
    cout << endl;
}


int main(){
    int n= 4;
    float f = 5.7;
    
    float** A = new float*[n];
    for(int i = 0; i<n; i++){
        A[i] = new float[n];
    }

    srand(time(NULL));
    for(int i = 0; i<n; i++){
        *A[i] = rand() / static_cast<float>(RAND_MAX);
    }


    Stampa_Matrice(A, n);

    if(es1(A,n,f)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}