/*15.Scrivere un metodo che prenda in input tre matrici
A, B e C di boolean con le stesse dimensioni, e
restituisca un boolean che indichi se una diagonale in
A, soprastante la diagonale principale, è presente
anche in B e C (nella stessa posizione e con la stessa
sequenza di valori!).*/

#include <iostream>

using namespace std;

bool esercizio15(bool** A, bool** B, bool** C, int n){
    for(int j=1; j<n; j++){
        bool diagonale = true;
        for(int i=0; i<n - j; i++){
            cout << "A[" << i << "]["<< i + j  << "]=" << A[i][i + j] << endl;
            cout << "B[" << i << "]["<< i + j << "]=" << B[i][i + j] << endl;
            cout << "C[" << i << "]["<< i + j  << "]="  << C[i][i + j] << endl;
            if(A[i][i + j] != B[i][i + j] || B[i][i+ j] != C[i][i + j]){
                diagonale = false;
                break;
            }
        }
        cout << "diagonale = " << diagonale << endl;
        if(diagonale){
            return true;
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
    A[0][2] = 1;
    A[0][3] = 0;
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
    B[0][1] = 0;
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
    C[0][1] = 0;
    C[0][2] = 0;
    C[0][3] = 0;
    C[1][0] = 0;
    C[1][1] = 0;
    C[1][2] = 1;
    C[1][3] = 1;
    C[2][0] = 0;
    C[2][1] = 1;
    C[2][2] = 0;
    C[2][3] = 0;
    C[3][0] = 0;
    C[3][1] = 0;
    C[3][2] = 0;
    C[3][3] = 0;

    cout << "Matrice C: " << endl << endl;
    Stampa_Matrice(C, n);

    if(esercizio15(A, B, C, n)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}