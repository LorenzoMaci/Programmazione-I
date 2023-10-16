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
    //diagonale principale
    int o1 = 0;
    string diagonale = "";
    for(int i = 0; i<n; i++){
        if(A[i][i]){
            diagonale = *A[i][i];
            for(int p = 0; p<diagonale.length(); p++){
                if(diagonale[p] == c1){
                    o1++;
                }   
            }
        }
    }
    //diagonale secondaria
    int o2 = 0;
    string diagonale2 = "";
    for(int i = 0; i<n; i++){
        if(A[i][n -i -1]){
            diagonale2 = *A[i][n -i -1];
            for(int p = 0; p<diagonale2.length(); p++){
                if(diagonale2[p] == c2){
                    o2++;
                }
            }
        }
    }
    double rapporto = (double)o1/o2;
    return rapporto;
}

void Stampa_Matrice(string*** A, int n){
    cout << "Matrice: "<<endl<< endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]){
                cout << *A[i][j] << "    \t";
            }
            else{
                cout << "*    \t" << endl;
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