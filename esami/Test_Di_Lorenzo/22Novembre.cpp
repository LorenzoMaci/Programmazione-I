/*Scrivere una funzione che prenda in input una matrice A di puntatori a interi
di dimensione n x m, un array D di double di dimensione m ed un array P di short
di dimensione m. Siano a di (i,j), d (j) e p (j) gli elementi rispettivamente della
matrice A e degli array D e P. Si assuma che p(j) < n, ∀j  =  1 ... m. La funzione 
restituisca un array di booleani B di dimensione m tale che (sia b(j) il suo generico
elemento di indice j):

    b(j) = {TRUE <=> (Σ di (pj), base i = 0)* a(i,j)/p(j) < d(j);
           {False    altrimenti
*/


#include <iostream>

using namespace std;

bool* es1(int*** A, int n, int m, double* D, short* P){
    bool* R = new bool[m];
    for(int i=0; i<m; i++){
        R[i] = 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] && *A[i][j] != 0){
                double somma = 0;
                if(D[j] != 0 && P[j] != 0){
                    for(int k=0; k<m; k++){
                        if(k != j){
                            somma += *A[k][j];
                        }
                    }
                    double temp = (double)somma/P[j];
                    if(temp < D[j]){
                        R[j] = 1;
                    }
                }
            }
        }
    }
    return R;
}


void Stampa_Matrice(int*** A, int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(A[i][j]){
                cout << *A[i][j] << "\t";
            }
            else{
                cout << "*\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main (){
    int n = 4;
    int m = 3;

    srand(time(NULL));
    int*** A = new int**[n];
    for(int i=0; i<n; i++){
        A[i] = new int*[m];
        for(int j=0; j<m; j++){
            A[i][j] = new int(rand()%10);
        }
    }

    Stampa_Matrice(A, n, m);

    double* D = new double[m];
    for(int i=0; i<m; i++){
        D[i] = rand()/(double)RAND_MAX *10;
        cout << D[i] << "  ";
    }
    cout << endl;

    short* P = new short[m];
    for(int i=0; i<m; i++){
        P[i] = rand()%10;
        cout << P[i] << "  ";
    }
    cout << endl;

    cout << "ARRAY BOOL: "<<endl;
    bool* B = new bool[m];
    for(int i=0; i<m; i++){
        cout << es1(A, n, m, D, P)[i] << "  \t";
    }
}