/*20.Scrivere un metodo che prenda in input una
matrice di puntatori a stringhe S di dimensione nm,
una stringa s1 ed uno short k, e restituisca la
percentuale di stringhe, tra quelle presenti nelle prime
k colonne di S, che siano piu lunghe di s1. NB: si
assuma k<=m. */

#include <iostream>

using namespace std;

int esercizio20(string*** S, int n, int m, string s1, short k){
    int counter_stringhe = 0;
    int percentuale;
    for(int i=0; i<n; i++){
        string s =  "";
        for(int j=0; j<m; j++){
            if(S[i][j]){
                s = *S[i][j];
                if(s.length() > s1.length()){
                    counter_stringhe++;
                }
            }
        }
        int counter_colonne = k*m;
        percentuale = (counter_stringhe*100)/counter_colonne;
    }
    return percentuale;
}

void Stampa_Matrice(string*** S,int n, int m){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(S[i][j]){
            cout << *S[i][j] << " ";
            }else{
                cout << "* ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 3;
    int m = 3;
    short k = 2;
    string s1 = "casa";
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
    cout << "La percentuale di stringhe più lunghe di s1, rispetto al numero di stringhe totali della colonna, è: " << esercizio20(S, n, m, s1, k)  << "%"<< endl;
}