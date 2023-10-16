/* Scrivere una funzione che prenda come parametri formali un array tridimensione A
di puntatori a interi di dimensione nxnxn e uno short q. Sia m la media dei valori contenuti
nella diagonale principale del cubo. La funzione restituisca il numero di elementi di A che 
puntano ad un qualche valore a tale che |a - m| <= q. */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int ex1(int**** A, int n, short q){
    int somma;
    double ma;
    int a;
    int counter=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            somma = 0;
            ma = 0;
            a = 0;
            for(int p= 0; p<n; p++){
                if(A[i][j][p]){
                    somma += *A[i][i][i];
                    cout << "somma = "<< somma << endl;
                    ma = (double) somma/n;
                    cout << "ma = "<< ma << endl;
                    a = *A[i][j][p];
                    cout << "a "<< a << endl;
                    int temp = a - ma;
                    if(temp < 0){
                        temp = temp * (-1);
                        cout << "temp = " << temp << endl;
                        if(temp <= q){
                            counter++;
                            cout << "counter = " << counter << endl;
                        }
                    }
                }
            } 
        }
    }
    return counter;
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

    cout << ex1(A, n, q) << endl;
}