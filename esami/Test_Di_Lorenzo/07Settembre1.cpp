/*Scrivere una funzione che prenda in input un array tridimensionale A
di puntatori a interi di dimensione nxnxn (A è un cubo) e restituisca
un array di puntatori a interi di dimensione n il cui i-esimo elemento
punti al valore puntato dall'i-esimo elemento della diagonale principale
di A, se questo è superiore al corrispondente elemento della diagonale 
secondaria, mentre punti a null altrimenti. N.B si presti attenzione ai puntatori a null!*/

#include <iostream>

using namespace std;

int** esame1(int**** A, int n){
    int** R = new int*[n];
    for(int i=0; i<n; i++){
        R[i] = 0;
    }

    for(int i=0; i<n; i++){
        if(A[i][i][i] && A[i][i][i] != 0 && A[i][n - i -1][n - i - 1] != 0 && A[i][i][i] > A[i][n - i - 1][n - i - 1]){
            R[i] = A[i][i][i];
        }
    }
    return R;
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

    int** R = new int*[n];
    for(int i=0; i<n; i++){
        R[i] = new int[n];
    }

    R = esame1(A,n);

    for(int i=0; i<n; i++){
        cout << R[i] << "  ";
    }
    cout << endl;
}
