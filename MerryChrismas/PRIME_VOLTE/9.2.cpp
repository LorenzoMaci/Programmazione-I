/*Scrivere un metodo che prenda in input un
parametro formale matrice A di interi di dimensioni
nxn ed un double w, e restituisca un valore booleano
true se esiste almeno una colonna della matrice A per
cui il rapporto tra la somma degli elementi della
colonna stessa e la somma degli elementi della
diagonale principale di A sia maggiore di w. */ 

#include <iostream>

using namespace std;

bool esercizio9(int** A, int n, double w){
    double colonna;
    double diagonale;
    double rapporto = 0;
    for(int j=0; j<n; j++){
        colonna = 0; 
        diagonale = 0;
        for(int i=0; i<n; i++){
            colonna += A[i][j];
            diagonale += A[i][i];
            rapporto = (double)colonna/diagonale;
        }
        if(rapporto >= w){
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
    int n = 4;
    double w = 1.2;

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[n];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            A[i][j] = rand()%25;
        }
    }
    Stampa_Matrice(A, n);

    if(esercizio9(A, n, w)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}