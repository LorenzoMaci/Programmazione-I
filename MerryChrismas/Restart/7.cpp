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

using namespace std;

int esercizio7(int*** A, int n, int m, double d1, double d2, short s){
    int counter_colonne = 0;
    int counter;
    int elemento1;
    int elemento2;
    for(int j=0; j<m; j++){
        elemento1 = 0;
        elemento2 = 0;
        counter = 0;
        for(int i=0; i<n -1; i++){
            if(A[i][j]){
                elemento1 = *A[i][j];
                elemento2 = *A[i + 1][j];
                if(d1 <= (double)elemento1/elemento2 && (double)elemento1/elemento2 <= d2){
                    counter++;
                }
            }
        }
        if(counter >= s){
            counter_colonne++;
        }
    }
    return counter_colonne;
}

void Stampa_Matrice(int*** A, int n, int m){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }else{
                cout << *A[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 3;
    double d1 = 0.2;
    double d2 = 1.2;
    short s = 2;
    int*** A = new int**[n];
    for(int i = 0; i<n; i++){
      A[i] = new int*[m];  
    }

    srand(time(0));
    A[0][0] = new int(rand()%15);
    A[0][1] = new int(rand()%15);
    A[0][2] = new int(rand()%15);
    A[1][0] = new int(rand()%15);
    A[1][1] = new int(rand()%15);
    A[1][2] = new int(rand()%15);
    A[2][0] = new int(rand()%15);
    A[2][1] = new int(rand()%15);
    A[2][2] = new int(rand()%15);
    A[3][0] = new int(rand()%15);
    A[3][1] = new int(rand()%15);
    A[3][2] = new int(rand()%15);

    Stampa_Matrice(A, n, m);

    cout << esercizio7(A, n, m, d1, d2, s) << endl;
}