/*Scrivere una funzione che prenda in input una matrice di stringhe S di dimensione
n x n in cui ogni stringa è rappresentata da un puntatore a carattere (c-string). La
funzione restituisca un array di Short A di dimensione n, in cui il generico elemento a,
rappresenti il numero di occorrenze del carattere della stringa s (i,i) che compare il
maggior numero di volte nella corrispondente stringa della diagonale secondaria. ES:
s1 = "abcde", s2 = "aabababac", allora il carattere di s1 che compare il maggior numero
di volte in s2 è il carattere 'a', per cui il numero di occorrenze da calcolare è 5. 
NB: Si presti attenzione ai puntatori a null!*/

#include <iostream>
#include <cstring>

using namespace std;

short* es2(char**** S, int n){
    short* A = new short[n];
    for(int i=0; i<n; i++){
        A[i] = 0;
    }

    for(int i=0; i<n; i++){
        if(S[i][i] && S[i][n - i -1]){
            int a = 0;
            int max = 0;
            int carattere = 0;
            while(S[i][i][a] != '\0'){
                int b = 0;
                while(S[i][n - i- 1][b] != '\0'){
                    if(S[i][i][a] == S[i][n - i- 1][b]){
                        carattere++;
                        b++;
                    }
                }
                if(max < carattere){
                    max = carattere;
                }
                carattere = 0;
                a++;
            }
            A[i] = carattere;
        }
    }
    return A;
}


void Stampa_Matrice(char**** S, int n){
    cout << "Matrice: "<<endl << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
                if(S[i][j]){
                    cout << *S[i][j] << "  ";
                }else{
                    cout << " \t";
                } 
        }
        cout << endl;
    }
    cout << endl; 
}

int main(){
    int n = 4;

    char**** S = new char***[n];
    for(int i=0; i<n; i++){
        if(S[i]){
            S[i] = new char**[n];
            for(int j=0; j<n; j++){
                if(S[i][j]){
                    S[i][j] = new char*[n];
                }
            }
        }
    }

    S[0][0][0] = 'e';
    S[0][1][0] = 'a';
    S[0][2][0] = 'b';
    S[1][0][0] = 'a';
    S[1][1][0] = 'c';
    S[1][2][0] = 'a';
    S[2][0][0] = 'y';
    S[2][1][0] = 'l';
    S[2][2][0] = 'z';  
    
    Stampa_Matrice(S,n);

    cout << "ARRAY ritorno "<< endl<< endl;
    short* R = new short[n];
    for(int i=0; i<n; i++){
        R[i] = 0;
    }
    R = es2(S, n);
    for(int i=0; i<n; i++){
        cout << R[i] << "  ";
    }
    cout << endl;
}