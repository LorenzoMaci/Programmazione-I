/*3.Scrivere un metodo che prenda in input un
parametro formale matrice quadrata Q di interi ed un
double w, e restituisca un valore booleano true se
esiste almeno una colonna della matrice Q tale che il
rapporto tra la somma degli elementi della colonna
stessa e la somma degli elementi della diagonale
secondaria di Q sia maggiore di w.*/

#include <iostream>

using namespace std;

bool esercizio3(int** Q, int n, double w){
    for(int j=0; j<n; j++){
        int somma = 0;
        int diagonale = 0;
        for(int i=0; i<n; i++){
            somma += Q[i][j];
            diagonale += Q[i][n - i -1];
        }
        if((double)somma/diagonale >= w){
            cout << (double)somma/diagonale << endl;
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(int** Q, int n){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << Q[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}  

int main(){
    int n = 3;
    double w =  1.3;
    
    int** Q = new int*[n];
    for(int i = 0; i<n; i++){
      Q[i] = new int[n];  
    }
    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            Q[i][j] = rand()%15;
        }
    }

    Stampa_Matrice(Q, n);

    cout << endl;
    if(esercizio3(Q, n, w)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}