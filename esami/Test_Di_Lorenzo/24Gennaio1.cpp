/* Scrivere un metodo in linguaggio C++ che prenda in imput una matrice di puntatori ad interi 
di dimensione n x m, due interi positivi a e b ed uno short s (si assuma a < b ed s < n). Il 
metodo restituisca una copia della matrice in cui ogni numero di una singola colonna della 
matrice di origine che risulti presente almeno  s volte nella colonna stessa sia sostituito, nella 
corrispondente colonna della matrice copia, con un numero pseudo-casuale negativo appartenente
all'intervallo [-b, -a] (tranne gli elementi che risultano nullptr nella matrice originale!) */

#include <iostream>

using namespace std;

int*** esame1(int*** A, int n, int m, int a, int b, short s){
    int*** R = new int**[n];
    for(int i=0; i<n; i++){
        R[i] = new int*[m];
    }

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            R[i][j] = A[i][j]; 
        }
    }

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            int counter = 0;
            if(A[i][j] && *A[i][j] != 0){
                int temp = *A[i][j];
                for(int k = 0; k<n; k++){
                    if(temp == *A[k][j]){
                        counter++;
                    }
                }
                srand(time(nullptr));
                if(counter >= s){
                    for(int k=0; k<n; k++){
                        if(*R[k][j] == temp){
                            *R[k][j] == (rand()%(b - a + 1) + a)*(-1);
                        }
                    }
                }
            }
        }
    }
    return R;
}

void Stampa_Matrice(int*** A, int n, int m){
    cout << "Matrice: "<<endl << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }else{
                cout << "*\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 5; 
    int m = 4;
    int a = 1;
    int b = 5;
    short s = 3;

    srand(time(0));
    int*** A = new int**[n];
    for(int i = 0; i<n; i++){
        A[i] = new int*[m];
        for(int j = 0; j < m; j++) {
            A[i][j] = new int(rand() % (b - a + 1) + a);
        }
    }

    cout << "Matrice di partenza:" << endl;
    Stampa_Matrice(A, n, m);

    cout << endl << "Matrice risultante:" << endl;
    int*** R = esame1(A, n, m, a, b, s);
    Stampa_Matrice(A, n, m);
}
    