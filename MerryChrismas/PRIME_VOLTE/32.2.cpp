/*32.Scrivere un metodo che prenda in input una
matrice quadrata di puntatori a stringhe e due caratteri
c1 e c2. Calcolare O1 come numero di occorrenze del
carattere c1 che figurano nella diagonale principale.
CalcolareO2 come numero di occorrenze del carattere
c2 che che figurano nella secondaria. Restituire il
rapportoO1/O2. NB: si faccia attenzione alle stringhe
mancante*/

#include <iostream>

using namespace std;

double esercizio32(string*** A, int n, char c1, char c2){
    int O1 = 0;
    int O2 = 0;

    for(int i=0; i<n; i++){
        if(A[i][i] && A[n - i - 1]){
            string diagonale_principale = *A[i][i];
            string diagonale_secondaria = *A[i][n - i -1];
            for(int p=0; p<diagonale_principale.length(); p++){
                if(diagonale_principale[p] == c1){
                    O1++;
                }
            }
            for(int p=0; p<diagonale_secondaria.length(); p++){
                if(diagonale_secondaria[p] == c2){
                    O2++;
                }
            }
        }
    }
    return (double)O1/O2;
}

void Stampa_Matrice(string*** A, int n){
    cout << "Matrice:  "<< endl << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }else{
                cout << "*  \t"<<endl;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    char c1 = 'a';
    char c2 = 'l';

    string*** M = new string**[n];
    for(int i = 0; i<n; i++){
        M[i] = new string*[m];
    }

    M[0][0] = new string("casa");
    M[0][1] = new string("porta");
    M[0][2] = new string("canale");
    M[0][3] = new string("portatile");
    M[1][0] = new string("nonna");
    M[1][1] = new string("cacciagione");
    M[1][2] = new string("corsale");
    M[1][3] = new string("cacca");
    M[2][0] = new string("padrino");
    M[2][1] = new string("cortile");
    M[2][2] = new string("montagna");
    M[2][3] = new string("ginepro");
    M[3][0] = new string("arancia");
    M[3][1] = new string("partire");
    M[3][2] = new string("arto");
    M[3][3] = new string("casale");

    Stampa_Matrice(M, n);

    cout << "Il rapporto tra le occorrenze è: " << esercizio32(M, n, c1, c2) << endl;
}