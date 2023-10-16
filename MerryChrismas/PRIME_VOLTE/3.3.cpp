/*3.Scrivere un metodo che prenda in input un
parametro formale matrice quadrata Q di interi ed un
double w, e restituisca un valore booleano true se
esiste almeno una colonna della matrice Q tale che il
rapporto tra la somma degli elementi della colonna
stessa e la somma degli elementi della diagonale
secondaria di Q sia maggiore di w.
*/

#include <iostream>

using namespace std;

bool esercizio3(int** Q, int n, int m, double w){
    int colonne;
    int diagonale;
    for(int j=0; j<m; j++){
        colonne = 0;
        diagonale = 0;
        for(int i=0; i<n; i++){
            colonne += *Q[i][j];
            diagonale += *Q[i][n - i -1];
        }
        if(colonne/diagonale >= w){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(int** Q, int n, int m){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << Q[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}