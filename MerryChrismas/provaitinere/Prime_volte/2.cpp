/* [Esercizio 2] Scrivere un metodo che prenda in input un parametro formale matrice M di dimensioni n × m di puntatori
a stringhe, e che restituisca true se esiste almeno una colonna in M che abbia un egual numero di stringhe palindrome di una
delle righe di M. */

#include<iostream>

using namespace std;

bool Check_Palindroma(string s){
    string p = "";
    for(int i = 0; i < s.length(); i++){
        p = s[i] + p;
    }
    return p == s;
}

bool esercizio2(string*** M, int n, int m){
    int righe_palindrome;
    for(int i=0; i<n; i++){
        righe_palindrome = 0;
        for(int j=0; j<m; j++){
            if(M[i][j]){
                if(Check_Palindroma(*M[i][j])){
                    righe_palindrome++;
                }
            }
        }
    }

    int colonne_palindrome;
    for(int j=0; j<m; j++){
        colonne_palindrome = 0;
        for(int i=0; i<n; i++){
            if(M[i][j]){
                if(Check_Palindroma(*M[i][j])){
                    colonne_palindrome++;
                }
                cout << "colonne = "<< colonne_palindrome << endl;
            }
        }
    }
    if(colonne_palindrome == righe_palindrome){
        return true;
    }
    return false;
}

void Stampa_Matrice(string*** M, int n, int m){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(M[i][j]){
                cout << *M[i][j] << " \t";
            }
            else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main() {
    int n = 3;
    int m = 3;
    string*** M = new string**[n];
    for(int i = 0; i < n; i++) M[i] = new string*[m];
    M[0][0] = new string("casa");
    M[0][1] = new string("oro");
    M[0][2] = new string("oo");
    M[1][0] = new string("ciao");
    M[1][1] = new string("oro");
    M[1][2] = new string("piano");
    M[2][0] = new string("ossa");
    M[2][1] = new string("ala");
    M[2][2] = new string("ciao");
    Stampa_Matrice(M, n, m);
    cout << esercizio2(M, n, m) << endl;
}
