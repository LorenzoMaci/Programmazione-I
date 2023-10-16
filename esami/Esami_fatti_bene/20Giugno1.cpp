/*Scrivere una funzione in C++ che prenda in input una matrice tridimensionale 
di puntatori a booleani A di dimensione m*n*q,  un intero senza segno l e restituisca 
una matrice di interi m*n il cui elemento di indici (i,j) contenga il numero di sottosequenze 
di elementi contigui nel vettore indicizzato da A[i][j] che abbiano valori pari a true e siano 
di lunghezza esattamente pari a l. NB: si presti attenzione ai puntatori null!*/

#include <iostream>

using namespace std;

int** esame1(bool**** A, int m, int n, int q, unsigned int l){
    int** R = new int*[m];
    for(int i=0; i<m; i++){
        R[i] = new int[n];
        for(int j=0; j<n; j++){
            R[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int sottosequenza = 0;
            int elementi_true = 0;
            for(int k=0; k<q; k++){
                if(A[i][j][k]){
                    if(*A[i][j][k] == true){
                        elementi_true++;
                    }
                    if(elementi_true == l){
                        sottosequenza++;
                        elementi_true = 0;
                    }
                }
            }
            R[i][j] = sottosequenza;
        }
    }
    return R;
}

void Stampa_Matrice(bool**** A, int m,int n, int q){
    cout << "Stampa Matrice:" << endl << endl;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            for(int z = 0; z<q; z++){
                cout << *A[i][j][z] << "      ";
            }
            cout << endl;
        }
        cout << endl;
    }
}


int main(){

    int m = 4;
    int n = 4;
    int q = 4;
    unsigned int l  = 2; 

    srand(time(NULL));
    bool**** A = new bool***[m];
    for(int i =0; i<m; i++){
        A[i] = new bool**[n];
        for(int j =0; j<n; j++){
            A[i][j] = new bool*[q];
            for(int z = 0; z<q; z++){
                A[i][j][z] = new bool(rand()%2);
            }
        }
    }

    Stampa_Matrice(A, m, n, q);

    int** R = new int*[m];
    for(int i=0; i<n; i++){
        R[i] = new int[n];
    }
    
    R = esame1(A,m,n,q,l);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << R[i][j] << "  ";
        }
        cout  << endl;
    }
    cout << endl;
}
