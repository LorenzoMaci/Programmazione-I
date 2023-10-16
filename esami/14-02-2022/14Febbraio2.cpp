/* Scrivere una funzione che prenda in input una matrice di stringhe S di dimensione n x n, 
una matrice B di boleani di dimensione n x n e restituisca una stringa ottenuta
concatenando i caratteri di indice pari delle stringhe di S che si trovano in 
corrispondenza di valori di B che sono identici nella corrispettiva trasposta B(T). */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

string es2(string** S, int n, bool** B){
    string concat = "";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(B[i][j] == B[j][i]){
                for(int k=0; k<S[i][j].length(); k++){
                    concat += S[i][j][k];
                }
            }
        }
    }
    return concat;
}

int main(){
    int n = 3;
    string** A = new string*[n];
    for(int i = 0; i < n; i++){
        A[i] = new string[n];
    }    
    A[0][0] = "casa";
    A[0][1] = "oiapprppaio";
    A[0][2] = "oo";
    A[1][0] = "abekeba";
    A[1][1] = "abeiokoieba";
    A[1][2] = "piano";
    A[2][0] = "ossa";
    A[2][1] = "ala";
    A[2][2] = "ciao";

    cout << "Matrice A: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << A[i][j] << "      \t";
        }
        cout << endl;
    }
    cout << endl;

    bool** B = new bool*[n];
    for(int i = 0; i<n; i++){
      B[i] = new bool[n];  
    }

    //Inizializzazione casuale della matrice di boleani
    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            B[i][j] = rand()%2;
        }
    }

    cout << "Matrice B: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << B[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrice B (Trasposta): " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << B[j][i] << " \t";
        }
        cout << endl;
    }
    cout << endl;

    cout << es2(A, n, B) << endl;
}