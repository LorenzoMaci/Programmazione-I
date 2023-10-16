/* Scrivere una funzione che prenda come parametri formali un array tridimensione A
di puntatori a interi di dimensione nxnxn e uno short q. Sia m la media dei valori contenuti
nella diagonale principale del cubo. La funzione restituisca il numero di elementi di A che 
puntano ad un qualche valore a tale che |a - m| <= q. */


#include <iostream>

using namespace std;

int es1(int**** A, int n, short q){
    int somma = 0;
    int counter = 0;
    for(int i = 0; i<n; i++){
        if(A[i][i][i]){
            somma += *A[i][i][i];
            counter++;
        } 
    }
    double m = (double)somma/counter;
    int counter_ritorno = 0;
    for(int x = 0; x<n; x++){
        for(int y = 0; y<n; y++){
            for(int z=0; z<n; z++){
                if(A[x][y][z]){
                    int a = *A[x][y][z];
                    double temp = (double) a - m;
                    if(temp < 0){
                        temp = temp*(-1);
                    }
                    if(temp <= q){
                        counter_ritorno++;
                    }
                }
            }
        }
    }
    return counter_ritorno;
}

void Stampa_Matrice(int**** A, int n){
    cout << "Stampa Matrice:" << endl << endl;
    for(int h = 0; h<n; h++){
        cout << "Matrice [" << h << "]: " << endl << endl;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout << *A[h][i][j] << "      ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(){

    int n = 4;
    short q = 4;

    srand(time(NULL));
    int**** A = new int***[n];
    for(int i =0; i<n; i++){
        A[i] = new int**[n];
        for(int j =0; j<n; j++){
            A[i][j] = new int*[n];
            for(int k = 0; k<n;k++){
                A[i][j][k] = new int(rand()%10);
            }
        }
    }

    Stampa_Matrice(A, n);

    cout << es1(A, n, q) << endl;
}