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

int esame2(string*** S, int n, int m, short k, short r, short s){
    int counter = 0;
    int palindroma;
    for(int j=0; j<m; j++){
        palindroma = 0;
        for(int i=0; i<n; i++){
            if(S[i][j]){
                if(Check_Palindroma(*S[i][j]) && r <= (*S[i][j]).length() && (*S[i][j]).length() <= s){
                    palindroma++;
                }
            }
        }
        if(palindroma >= k){
            counter++;
        }
    }
    return counter;
}

void Stampa_Matrice(string*** S, int n, int m){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(S[i][j]){
                cout << *S[i][j] << " \t";
            }
            else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    int n = 3;
    int m = 3;
    short r = 3;
    short s = 12;
    short k = 2;
    string*** S = new string**[n];
    for(int i = 0; i < n; i++){
        S[i] = new string*[m];
    } 
    S[0][0] = new string("casa");
    S[0][1] = new string("oiapprppaio");
    S[0][2] = new string("oo");
    S[1][0] = new string("abekeba");
    S[1][1] = new string("abeiokoieba");
    S[1][2] = new string("piano");
    S[2][0] = new string("ossa");
    S[2][1] = new string("ala");
    S[2][2] = new string("ciao");
    Stampa_Matrice(S, n, m);
    cout << "Il numero di colonne che soddisfano la condizione del testo sono: " << esame2(S, n, m, k, r, s) << endl;
}

