/*[Esercizio 8] Scrivere un metodo che prenda in input 
un parametro formale matrice A di interi di dimensioni 
n × m, uno short k ed uno short w, e restituisca true se
la matrice contiene almeno w colonne che contengono almeno
una sequenza di interi monotona crescente di lunghezza maggiore o uguale a k.*/

#include <iostream>

using namespace std;

bool esercizio8(int** A, int n, int m, short k, short w){
    int sequenza;
    int counter_Colonne = 0;
    for(int j=0; j<m; j++){
        sequenza = 0;
        for(int i=0; i<n-1; i++){
            if(A[i][j] == A[i+1][j] || (A[i][j] + 1) == A[i+1][j]){
                sequenza++;
            }else{
                sequenza = 1;
            }
            if(sequenza >= k){
                counter_Colonne++;
            }
        }
    }
    if(counter_Colonne >= w){
        return true;
    }
    return false;
}

void Stampa_Matrice(int** A, int n, int m){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << A[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    short k = 2;
    short w = 2;

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[m];
    }

    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 8;
    A[0][3] = 3;
    A[1][0] = 7;
    A[1][1] = 5;
    A[1][2] = 5;
    A[1][3] = 6; 
    A[2][0] = 4;
    A[2][1] = 6;
    A[2][2] = 4;
    A[2][3] = 8;
    A[3][0] = 2;
    A[3][1] = 1;
    A[3][2] = 2;
    A[3][3] = 9;

    Stampa_Matrice(A, n, m);

    if(esercizio8(A, n, m, k, w)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}