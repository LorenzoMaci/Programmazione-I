/*15.Scrivere un metodo che prenda in input tre matrici
A, B e C di boolean con le stesse dimensioni, e
restituisca un boolean che indichi se una diagonale in
A, soprastante la diagonale principale, è presente
anche in B e C (nella stessa posizione e con la stessa
sequenza di valori!).*/

#include <iostream>
#include <ctime>
#include<cstdlib>

using namespace std;

bool esercizio15(bool** A, bool** B, bool** C, int n){
    int diagonaleA;
    int diagonaleB;
    int diagonaleC;
    for(int i = 0; i< n-1; i++){
        diagonaleA = 0;
        diagonaleB = 0;
        diagonaleC = 0;
        for(int j = i +1; j<n; j++){
            diagonaleA = A[i][j];
            diagonaleB = A[i][j];
            diagonaleC = A[i][j];
            if(diagonaleA == diagonaleB && diagonaleB == diagonaleC){
                return true;
            }
        }
    }
    return false;
}

void Stampa_Matrice(bool** A, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
                cout << A[i][j] << "\t";
        }
        cout<<endl;
    }
    cout << endl;
}



int main(){
    int n = 4;

    bool** A = new bool*[n];
    for(int i = 0; i<n; i++){
        A[i] = new bool[n];
    }

    A[0][0] = 0;
    A[0][1] = 0;
    A[0][2] = 0;
    A[0][3] = 1;
    A[1][0] = 0;
    A[1][1] = 0;
    A[1][2] = 1;
    A[1][3] = 1;
    A[2][0] = 0;
    A[2][1] = 1;
    A[2][2] = 0;
    A[2][3] = 1;
    A[3][0] = 0;
    A[3][1] = 0;
    A[3][2] = 0;
    A[3][3] = 1;

    cout << "Matrice A: " << endl << endl;
    Stampa_Matrice(A, n);

    bool** B = new bool*[n];
    for(int i = 0; i<n; i++){
        B[i] = new bool[n];
    }
    
    B[0][0] = 0;
    B[0][1] = 1;
    B[0][2] = 0;
    B[0][3] = 0;
    B[1][0] = 0;
    B[1][1] = 0;
    B[1][2] = 1;
    B[1][3] = 1;
    B[2][0] = 0;
    B[2][1] = 1;
    B[2][2] = 0;
    B[2][3] = 1;
    B[3][0] = 0;
    B[3][1] = 0;
    B[3][2] = 0;
    B[3][3] = 1;

    cout << "Matrice B: " << endl << endl;
    Stampa_Matrice(B, n);

    bool** C = new bool*[n];
    for(int i = 0; i<n; i++){
        C[i] = new bool[n];
    }
    
    C[0][0] = 0;
    C[0][1] = 1;
    C[0][2] = 0;
    C[0][3] = 1;
    C[1][0] = 0;
    C[1][1] = 0;
    C[1][2] = 1;
    C[1][3] = 1;
    C[2][0] = 0;
    C[2][1] = 1;
    C[2][2] = 0;
    C[2][3] = 1;
    C[3][0] = 0;
    C[3][1] = 0;
    C[3][2] = 0;
    C[3][3] = 1;

    cout << "Matrice C: " << endl << endl;
    Stampa_Matrice(C, n);

    if(esercizio15(A, B, C, n)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}