/* Scrivere un metodo in linguaggio C++ che prenda in imput una matrice di puntatori a stringhe 
di dimensioni n x m, e tre short k, r ed s (si assuma r < s e k < n). Il metodo restituisca il 
numero di colonne aventi il seguente requisito: la colonna contiene almeno k stringhe palindrome 
che abbiano lunghezza r <= l <= s. NB: una stringa si dice palindroma quando si legge allo stesso 
modo da destra e da sonostra (esempio: "abckcba" oppure "trert"). */

#include <iostream>

using namespace std;

bool Check_Palindroma(string s){
    string p = "";
    for(int i=0; i<s.length(); i++){
        p = s[i] + p;
    }
    return p == s;
}

int es2(string*** S, int n, int m, short k, short r, short s){
    int colonne = 0;
    int counter_palindroma;
    for(int j=0; j<m; j++){
        counter_palindroma = 0;
        for(int i=0; i<n; i++){
            if(S[i][j]){
                if(Check_Palindroma(*S[i][j]) && r <= (*S[i][j]).length() && (*S[i][j]).length() <= s){
                    counter_palindroma++;
                }
            }
        }
        if(counter_palindroma >= k){
            colonne++;
        }
    }
    return colonne;
}

int main(){
    int n = 3;
    int m = 3;
    short r = 3;
    short s = 12;
    short k = 2;
    string*** M = new string**[n];
    for(int i = 0; i < n; i++){
        M[i] = new string*[m];
    } 
    M[0][0] = new string("casa");
    M[0][1] = new string("oiapprppaio");
    M[0][2] = new string("oo");
    M[1][0] = new string("abekeba");
    M[1][1] = new string("abeiokoieba");
    M[1][2] = new string("piano");
    M[2][0] = new string("ossa");
    M[2][1] = new string("ala");
    M[2][2] = new string("ciao");
    Stampa_Matrice(M, n, m);
    cout << "Il numero di colonne che soddisfano la condizione del testo sono: " << esame2(M, n, m, k, r, s) << endl;
}

