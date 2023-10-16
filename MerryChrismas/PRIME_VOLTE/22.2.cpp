/*22.Scrivere un metodo che prenda in input una
matrice quadrata Q di stringhe e restituisca il valore
booleano true se la stringa piu lunga della diagonale
principale di Q contiene un numero di vocali minore
della stringa piu corta della diagonale stessa. NB: Si
assuma che le stringhe della diagonale principale
abbiano lunghezze differenti e sempre maggiori di
zero. */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool esercizio22(string** Q, int n){
    int max = INT_MIN;
    int min = INT_MAX;
    string dmax = "";
    string dmin = "";
    int vocali_max = 0;
    int vocali_min = 0;
    for(int i=0; i<n; i++){
        if(max < Q[i][i].length()){
            dmax = Q[i][i];
        }
        if(min > Q[i][i].length()){
            dmin = Q[i][i];
        }

        for(int k=0; k<dmax.length(); k++){
            if(dmax[k] == 'a' || dmax[k] == 'e' || dmax[k] == 'i' || dmax[k] == 'o' || dmax[k] == 'u'
            || dmax[k] == 'A' || dmax[k] == 'E' || dmax[k] == 'I' || dmax[k] == 'O' || dmax[k] == 'U'){
                vocali_max++;
            } 
        }

        for(int p=0; p<dmin.length(); p++){
            if(dmin[p] == 'a' || dmin[p] == 'e' || dmin[p] == 'i' || dmin[p] == 'o' || dmin[p] == 'u'
            || dmin[p] == 'A' || dmin[p] == 'E' || dmin[p] == 'I' || dmin[p] == 'O' || dmin[p] == 'U'){
                vocali_min++;
            }
        }
    }
    if(vocali_max < vocali_min){
        return true;
    }
    return false;
}

void Stampa_Matrice(string** Q, int n){
    cout << "Matrice: "<< endl<< endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << Q[i][j]<< " \t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){ 
    int n;
    cout << "Inserire dimensione matrice: "; 
    cin >> n;
    cout << endl;
    string** Q = new string*[n];
    for(int i = 0; i<n; i++){
        Q[i] = new string[n]; 
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << "Inserisci Q[" << i << "][" << j << "] " << endl; 
            cin >> Q[i][j]; 
        }
    }
    Stampa_Matrice(Q,n);
    
    cout << endl;
    if(esercizio22(Q,n) == 1){
        cout << "VERO!" << endl;
    }
    else{
        cout << "FALSO!" << endl;
    }
}
