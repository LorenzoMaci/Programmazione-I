/*[Esercizio 5] Scrivere un metodo che prenda in input 
un parametro formale array A di interi di dimensioni n×m
di elementi distinti ed un array B di double di dimensioni
k × n, e restituisca un array di n interi nel quale lo i-esimo 
elemento sia uguale alla media aritmetica degli elementi presenti
sia nella riga i-esima di A che nella colonna i-esima di B. 
NB: per decidere se un elemento int della matrice A `e uguale
ad un elemento double della matrice B si calcoli l’approssimazione all’intero piu vicino di quest’ultimo.*/

#include <iostream>
#include <cmath>

using namespace std;

int* esercizio5(int** A, int n, int m, double** B, int k){
    int* R = new int[n];

    int* AB = new int[n];

    int somma_elementi;
    for(int i=0; i<n; i++){
        somma_elementi = 0;
        for(int j=0; j<m; j++){
            somma_elementi += A[i][j];
        }
        AB[i] = somma_elementi;
    }

    for(int j=0; j<n; j++){
        somma_elementi = 0;
        for(int i=0; i<k; i++){
            somma_elementi += B[i][j];
        }
        AB[j] = somma_elementi;
    }

    for(int i=0; i<n; i++){
        R[i] = round(AB[i]/(n + n));
    }
    return R;
}

void Stampa_Matrice(int** A, int n, int m){
    cout<<"Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << A[i][j] << "    ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4; 
    int m = 4; 
    int k = 4; 

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[m];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            A[i][j] = rand()%15;
        }
    }

    //Stampa Matrice
    cout << "Matrice (A):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << A[i][j] << "      ";
        }
        cout << endl;
    }
    cout << endl;

    double** B = new double*[k];
    for(int i = 0; i<k; i++){
        B[i] = new double[n];
    }

    srand(time(0));
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            B[i][j] = rand()/(double)RAND_MAX*15;
        }
    }

    //Stampa Matrice
    cout << "Matrice (B):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << B[i][j] << "      ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << esercizio5(A, n, m, B, k)[i]<< "      ";
    }
    cout << endl;
}