/*29.Scrivere un metodo che prenda in input una
matrice quadrata A di numeri interi ed un double w, e
restituisca il valore booleano true se il rapporto tra il
minimo ed il massimo valore della diagonale
secondaria di A e minore o uguale a w. 
*/

#include <iostream>

using namespace std;

bool esercizio29(int** A, int n, double w){
    int min = 1000;
    int max = 0;
    int diagonale_Secondaria = 0;
    for(int i = 0; i<n; i++){
        diagonale_Secondaria = A[i][n - i -1];
        if(min > diagonale_Secondaria){
            min = A[i][n -i -1];
        }
        if(max < diagonale_Secondaria){
            max = A[i][n -i -1];
        }
        if((double)min/max <= w){
            return true;
        }
    }
    return false;
}
void Stampa_Matrice(int** A, int n){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j]){
                cout << A[i][j] << " \t";
            }else{
                 cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){ 
int n = 3;
    double w = 0.6;
    int** M = new int*[n];
    for(int i = 0; i<n; i++){
      M[i] = new int[n];  
    }
    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            M[i][j] = rand()%15;
        }
    }
    Stampa_Matrice(M, n);

    cout << endl;
    if(esercizio29(M, n, w)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}
