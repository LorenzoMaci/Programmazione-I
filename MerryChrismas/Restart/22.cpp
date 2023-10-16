/*22.Scrivere un metodo che prenda in input una
matrice quadrata Q di stringhe e restituisca il valore
booleano true se la stringa piu lunga della diagonale
principale di Q contiene un numero di vocali minore
della stringa piu corta della diagonale stessa. NB: Si
assuma che le stringhe della diagonale principale
abbiano lunghezze differenti e sempre maggiori di
zero. */

#include <iostream>

using namespace std;

bool esercizio22(string** Q, int n){
    int min = 1000;
    int max = 0;
    string s = "";
    string r = "";
    for(int i=0; i<n; i++){
        if(max < Q[i][i].length()){
            max= Q[i][i].length();
            s = Q[i][i];
        }
        if(min > Q[i][i].length()){
            min= Q[i][i].length();
            r = Q[i][i];
        }
        int counter_max = 0;
        int counter_min = 0;
        for(int x = 0; x<max;; x++){
            if(s[x] == 'A' || s[x] == 'E' || s[x] == 'I' || s[x] == 'O' || s[x] == 'U'
            || s[x] == 'a' || s[x] == 'e' || s[x] == 'i' || s[x] == 'o' || s[x] == 'u' ){
                counter_max++;
            }
        }
        for(int x = 0; x<min; x++){
            if(r[x] == 'A' || r[x] == 'E' || r[x] == 'I' || r[x] == 'O' || r[x] == 'U'
            || r[x] == 'a' || r[x] == 'e' || r[x] == 'i' || r[x] == 'o' || r[x] == 'u' ){
                counter_min++;
            }
        }
        if(counter_max < counter_min){
            return true;
        }
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
