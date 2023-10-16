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

using namespace std;

bool esercizio22(string** Q, int n){
    int max=0;
    int min=100;
    string s= "";
    string c= "";
    for(int i=0; i<n;i++){
        if(max<Q[i][i].length()){
            max= Q[i][i].length();
            s= Q[i][i];
        }
        if(min>Q[i][i].length()){
            min= Q[i][i].length();
            c = Q[i][i];
        }
        int vocalimax=0;
        int vocalimin=0;
        for(int i =0; i<max; i++){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O'|| s[i] == 'U' || s[i] == 'a' || s[i] == 'e'|| s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'){
                vocalimax++;
            }
            if(c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O'|| c[i] == 'U' || c[i] == 'a' || c[i] == 'e'|| c[i] == 'i'|| c[i] == 'o'|| c[i] == 'u'){
                vocalimin++;
            }
            if(vocalimax < vocalimin){
                return true;
            }   
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
