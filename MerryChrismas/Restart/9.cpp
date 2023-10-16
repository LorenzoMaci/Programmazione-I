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
    int somma_colonne;
    int somma_diagonale = 0;
    for(int i=0; i<n; i++){
        somma_diagonale += A[i][i];
    }
    for(int j = 0; j < n; j++){
        somma_colonne = 0;
        for(int i=0; i<n; i++){
            somma_colonne += A[i][j];
        }
        if((double)somma_colonne/somma_diagonale >= w){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(int** A, int n){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << A[i][j] << endl;
        }
        cout << endl;
    }
    cout << endl;
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