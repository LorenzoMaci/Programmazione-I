/*Scrivere una funzione che prenda in input una matrice di stringhe S di dimensione
n x n in cui ogni stringa è rappresentata da un puntatore a carattere (c-string). La
funzione restituisca un array di Short A di dimensione n, in cui il generico elemento a,
rappresenti il numero di occorrenze del carattere della stringa s (i,i) che compare il
maggior numero di volte nella corrispondente stringa della diagonale secondaria. ES:
s1 = "abcde", s2 = "aabababac", allora il carattere di s1 che compare il maggior numero
di volte in s2 è il carattere 'a', per cui il numero di occorrenze da calcolare è 5. 
NB: Si presti attenzione ai puntatori a null!*/

#include <iostream>

using namespace std;



int main(){
    int n = 4;

    string** S = new string*[n];
    for(int i=0; i<n; i++){
        S[i] = new string[n];
    }

    S[0][0] = "casa";
    S[0][1] = "oiapprppaio";
    S[0][2] = "oo";
    S[1][0] = "abekeba";
    S[1][1] = "abeiokoieba";
    S[1][2] = "piano";
    S[2][0] = "ossa";
    S[2][1] = "ala";
    S[2][2] = "ciao";  
    
    cout << "ARRAY ritorno "<< endl<< endl;
    short* A = new short[n];
    for(int i=0; i<n; i++){
        A[i] = 0;
    }
    A = es2(S, n);
    for(int i=0; i<n; i++){
        cout << A[i] << "  ";
    }
    cout << endl;
}