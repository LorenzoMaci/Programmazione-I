/*3.Scrivere un metodo che prenda in input un
parametro formale matrice quadrata Q di interi ed un
double w, e restituisca un valore booleano true se
esiste almeno una colonna della matrice Q tale che il
rapporto tra la somma degli elementi della colonna
stessa e la somma degli elementi della diagonale
secondaria di Q sia maggiore di w.
*/

#include <iostream>
#include<cstdlib>
#include <ctime>


using namespace std;

bool esercizio3(int** Q, int n, double w){
    int somma_colonne;
    for(int j=0; j<n; j++){
        somma_colonne = 0;
        for(int i=0; i<n; i++){
            somma_colonne += Q[i][j];
        }
    }

    int somma_diagonale2 = 0;
    for(int i=0; i<n; i++){
        somma_diagonale2 += Q[i][n - i -1];
    }

    if((double)somma_colonne/somma_diagonale2 >= w){
        return true;
    }
    return false;
}

void matrice(int** Q, int n){
    cout << "Matrice: "<<endl;
    for (int i=0; i<n; i++){
        for( int j=0; j<n; j++){
            if(j!= n-1){
                cout << Q[i][j]<< "\t";
            }
            else{
                cout << Q[i][j]<<endl;
            }
        }
    }
}

int main(){
    int n = 3;
    double w =  0.1;
    
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

    matrice(Q, n);

    cout << endl;
    if(esercizio3(Q, n, w)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}