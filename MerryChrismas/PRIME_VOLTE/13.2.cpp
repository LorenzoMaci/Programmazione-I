/*13.Scrivere un metodo che prenda come parametri
formali una matrice quadrata A n×n di puntatori a char
e restituisca in output un bool che indichi se esiste una
colonna in A identica alla diagonale principale di A. */

#include <iostream>

using namespace std;

bool esercizio13 (char*** A, int n){
    for(int j=0; j<n; j++){
        int colonna=0;
        int diagonale=0;
        for(int i=0; i<n; i++){
            colonna += *A[i][j];
            diagonale = *A[i][i];
            if(colonna == diagonale){
                return true;
            }
        }
    }
    return false;
}