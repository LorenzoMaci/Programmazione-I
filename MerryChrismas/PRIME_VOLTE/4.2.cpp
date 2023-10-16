/*Scrivere un metodo che prenda in input una matrice
di puntatori a stringhe P di dimensioni nm, due short a
e b, ed una stringa s. Il metodo restituisca il valore
booleano true se esiste almeno una colonna in P tale
che la stringa s sia sottostringa di un numero
compreso tra a e b (inclusi) di stringhe della colonna
stessa. PS: Si assuma 0 < a < b < n */

#include <iostream>

using namespace std;

bool esercizio4(string*** P, int n ,int m, short a, short b, string s){
    int colonne;
    for(int j=0; j<m; j++){
        colonne = 0;
        for(int i=0; i<n; i++){
            if(P[i][j]){
                if((*P[i][j]).find(s) != string::npos){
                    colonne++;
                }
                if(a <= colonne && colonne <= b){
                    return true;
                }
            }
        }
    }
    return false;
}

void Stampa_Matrice(string*** P, int n, int m){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(P[i][j]){
                cout << *P[i][j]<<" \t";
            }else{
                cout << *P[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}