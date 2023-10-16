/*7.Scrivere un metodo che prenda in input un
parametro formale matrice A di puntatori ad interi di
dimensione nxm, due double d1 e d2 ed uno short s, e
restituisca il numero di colonne di A nelle quali
esistano almeno s coppie di elementi contigui (ES:
A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il
secondo elemento sia compreso tra d1 e d2. NB: Si
assuma a priori che s<=n-1 e che d1 < d2. Si presti
attenzione ai numeri "mancanti"nella matrice A.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int esercizio7(int*** A,int n,int m, double d1, double d2, short s){
    int elemento1 = 0;
    int elemento2 = 0;
    double rapporto = 0;
    int colonne;
    int counter = 0;
    for(int j=0; j<m; j++){
        colonne  = 0;
        for(int i=0; i<n-1; i++){
            if(A[i][j]){
                elemento1 = *A[i][j];
                elemento2 = *A[i+1][j];
                if(elemento2 != 0){
                    rapporto = (double)elemento1/elemento2;
                    if(d1 <= rapporto && rapporto <= d2){
                        colonne++;
                    }
                }
            }
        }
        if(colonne >= s){
            counter++;
        }
    }
    return counter;
}

void Stampa_Matrice(int*** A, int n, int m){
    cout << "Matrice: "<<endl;
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            if(j!=m-1){
                cout << *A[i][j]<< "\t";
            }
            else{
                cout << *A[i][j]<< endl;
            }
        }
    }
}

int main(){
    int n = 4;
    int m = 3;
    double d1 = 0.2;
    double d2 = 1.2;
    short s = 2;
    int*** M = new int**[n];
    for(int i = 0; i<n; i++){
      M[i] = new int*[m];  
    }

    srand(time(0));
    M[0][0] = new int(rand()%15);
    M[0][1] = new int(rand()%15);
    M[0][2] = new int(rand()%15);
    M[1][0] = new int(rand()%15);
    M[1][1] = new int(rand()%15);
    M[1][2] = new int(rand()%15);
    M[2][0] = new int(rand()%15);
    M[2][1] = new int(rand()%15);
    M[2][2] = new int(rand()%15);
    M[3][0] = new int(rand()%15);
    M[3][1] = new int(rand()%15);
    M[3][2] = new int(rand()%15);

    Stampa_Matrice(M, n, m);

    cout << esercizio7(M, n, m, d1, d2, s) << endl;
}
