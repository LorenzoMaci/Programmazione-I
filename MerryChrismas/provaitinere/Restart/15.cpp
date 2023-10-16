/*[Esercizio 15] Scrivere un metodo che preveda due parametri 
formali:  una matrice A di stringhe ed una matrice B di short, 
entrambe di dimensioni n×m. Il metodo restituisca uno array di 
n puntatori a stringhe nel quale il generico elemento di indice 
i sar`a uguale alla concatenazione delle sole stringhe della riga 
i-esima di A che hanno lunghezza pari o maggiore del corrispondente 
numero in B.*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

string* esercizio15(string** A, short** B, int n, int m){
    string** R = new string*[n];
    for(int i=0; i<n; i++){
        R[i] = new string("");
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j].length() >= B[i][j]){
                (*R[i]).append(A[i][j]);
            }
        }
    }
    cout << "Array:\t";
    for(int i = 0; i<n; i++){
        cout << *R[i] << "\t";
    }
    cout << endl;
    return *R;
}


void Stampa_Array(char* C, int n){
    for(int i = 0; i<n; i++){
        cout << C[i] << "     ";
    }
    cout << endl << endl;
}


int main(){
    int n = 4;
    int m = 4;

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }

    A[0][0] = "camion";
    A[0][1] = "barella";
    A[0][2] = "bonucci";
    A[0][3] = "chiellini";
    A[1][0] = "adani";
    A[1][1] = "palla";
    A[1][2] = "orchestra";
    A[1][3] = "molletta";
    A[2][0] = "gioco";
    A[2][1] = "rajang";
    A[2][2] = "teostra";
    A[2][3] = "lunastra";
    A[3][0] = "chimera";
    A[3][1] = "hunter";
    A[3][2] = "picnic";
    A[3][3] = "rick";

    //Stampa Matrice
    cout << "Matrice (A): " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << A[i][j] << "    \t";
        }
        cout << endl;
    }
    cout << endl;

    short** B = new short*[n];
    for(int i = 0; i<n; i++){
        B[i] = new short[m];
    }

    //inizializzazione matrice con numeri casuali e stampa
    srand(time(0));
    cout << "Matrice (B): " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            B[i][j] = rand()%10;
            cout << B[i][j] << "    \t";
        }
        cout << endl; 
    }
    cout << endl;

    esercizio15(A, B, n, m);
}