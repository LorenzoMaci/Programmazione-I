/*13.Scrivere un metodo che prenda come parametri
formali una matrice quadrata A n×n di puntatori a char
e restituisca in output un bool che indichi se esiste una
colonna in A identica alla diagonale principale di A. */

#include <iostream>

using namespace std;


bool esercizio13(char*** A, int n){
    char colonna;
    bool counter = false;
    for(int j =0; j<n; j++){
        colonna = 0;
        for(int i=0; i<n; i++){
            if(A[i][j]){
                colonna += *A[i][j];
                cout << colonna << endl;
                if( colonna == *A[i][i]){
                    counter = true;
                }
            }
        }
    }
    return counter;
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
    int n = 4;

    char*** A = new char**[n];
    for(int i = 0; i < n; i++){
        A[i] = new char*[n];
    }    
    A[0][0] = new char('a');
    A[0][1] = new char('b');
    A[0][2] = new char('a');
    A[0][3] = new char('c');
    A[1][0] = new char('d');
    A[1][1] = new char('d');
    A[1][2] = new char('d');
    A[1][3] = new char('q');
    A[2][0] = new char('k');
    A[2][1] = new char('z');
    A[2][2] = new char('k');
    A[2][3] = new char('7');
    A[3][0] = new char('4');
    A[3][1] = new char('o');
    A[3][2] = new char('1');
    A[3][3] = new char('3');

    Stampa_Matrice(A, n);

    if(esercizio13(A, n)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}