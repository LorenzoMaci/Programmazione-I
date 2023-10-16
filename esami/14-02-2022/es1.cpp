/* Scrivere una funzione che prenda in input una matrice A di dimensione m x n
(si assuma m > n) di puntatori a double, uno short k e un double q e restituisca 
il numero di sequenze di lunghezza k di media superiore a q che si trovano sulle 
diagonali principali delle matrici quadrate di dimensione n x n contenute in A. */

#include <iostream>

using namespace std;

int es1(double*** A, int m, int n, short k, double q){
    int ritorno = 0;
    double somma;
    int counter;
    for(int i=0; i<=m-n; i++){
        for(int j=0; j<n-1; j++){
            somma = 0;
            counter = 0;
            if(A[i][j]){
                for(int z=j; z<k+j; z++){
                    if(A[z][z]){
                        somma += *A[z+i][z];
                        counter++;
                    }
                }
                double media = somma/k;
                 if(media >= q){
                    ritorno++;
                }
            }
        }
    }
    return ritorno;
}

void Stampa_Matrice(double*** A, int m, int n){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j]){
                cout << *A[i][j] << "     \t";
            }
            else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    int m = 4;
    int n = 3;
    short k = 2;
    double q = 4.3;
    double*** A = new double**[m];
    for(int i = 0; i < m; i++){
        A[i] = new double*[n];
    }       

    srand(time(0));

    A[0][0] = new double(rand()/(double)RAND_MAX * 10);
    A[0][1] = new double(rand()/(double)RAND_MAX * 10);
    A[0][2] = new double(rand()/(double)RAND_MAX * 10);
    A[1][0] = new double(rand()/(double)RAND_MAX * 10);
    A[1][1] = new double(rand()/(double)RAND_MAX * 10);
    A[1][2] = new double(rand()/(double)RAND_MAX * 10);
    A[2][0] = new double(rand()/(double)RAND_MAX * 10);
    A[2][1] = new double(rand()/(double)RAND_MAX * 10);
    A[2][2] = new double(rand()/(double)RAND_MAX * 10);
    A[3][0] = new double(rand()/(double)RAND_MAX * 10);
    A[3][1] = new double(rand()/(double)RAND_MAX * 10);
    A[3][2] = new double(rand()/(double)RAND_MAX * 10);

    Stampa_Matrice(A, m, n);

    cout << es1(A, m, n, k, q) << endl;
}