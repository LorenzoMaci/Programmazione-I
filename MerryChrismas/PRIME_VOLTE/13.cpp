/*13.Scrivere un metodo che prenda come parametri
formali una matrice quadrata A n×n di puntatori a char
e restituisca in output un bool che indichi se esiste una
colonna in A identica alla diagonale principale di A. */

#include <iostream>

using namespace std;

bool esercizio13(char*** A, int n){
    const char * diagonale = "";
    for(int i=0; i<n; i++){
        if(A[i][i]){
            diagonale = A[i][i];
            cout << "diagonale = " << diagonale << endl;
        }
    }

    for(int j=0; j<n; j++){
        const char * colonne = "";
        for(int i=0; i<n; i++){
            if(A[i][j]){
                colonne = A[i][j];
                cout << "colonne= "<< colonne << endl;
            }
        }
        if(colonne == diagonale){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(char*** A, int n){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }else{
                 cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    int n = 3;

    char*** A = new char**[n];
    for(int i = 0; i < n; i++){
        A[i] = new char*[n];
    }    
    A[0][0] = new char('a');
    A[0][1] = new char('b');
    A[0][2] = new char('b');
    A[1][0] = new char('d');
    A[1][1] = new char('d');
    A[1][2] = new char('d');
    A[2][0] = new char('k');
    A[2][1] = new char('z');
    A[2][2] = new char('z');
    
    Stampa_Matrice(A, n);

    if(esercizio13(A, n)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}