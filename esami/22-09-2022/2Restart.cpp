/*Scrivere una funzione che prenda in input una matrice di stringhe S di dimensione
n x n in cui ogni stringa è rappresentata da un puntatore a carattere (c-string). La
funzione restituisca un array di Short A di dimensione n, in cui il generico elemento a,
rappresenti il numero di occorrenze del carattere della stringa s (i,i) che compare il
maggior numero di volte nella corrispondente stringa della diagonale secondaria. ES:
s1 = "abcde", s2 = "aabababac", allora il carattere di s1 che compare il maggior numero
di volte in s2 è il carattere 'a', per cui il numero di occorrenze da calcolare è 5. 
NB: Si presti attenzione ai puntatori a null!*/


#include <iostream>
#include <cmath>

using namespace std;

short* es2(char*** S, int n){
    short* A = new short[n];
    for(int i=0; i<n; i++){
        A[i] = 0;
    }

    for(int i=0; i<n; i++){
        if(S[i][i] && S[i][n - i -1]){
            int carattere = 0;
            int max = 0;
            int x = 0; // dichiaro questa variabile per il while così va avanti
            while((*S[i][i][x]) != '\0'){
                int y = 0;
                while((*S[i][n - i -1][y]) != '\0'){
                    if((*S[i][i][x]) == (*S[i][n - i - 1][y])){
                        carattere++;
                        y++;
                    }
                }
                if(carattere > max){
                    max = carattere;
                }
                carattere = 0;
                x++;
            }
            A[i] = max;
        }else{
            A[i] = 0;
        }
    }
    return A;
}

int main(){
    
}