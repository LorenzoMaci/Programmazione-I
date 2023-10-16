/* .Scrivere un metodo che prenda come parametro 
formale un array A di stringhe (tutte di lunghezza 
dispari), e restituisca in output la massima lunghezza 
delle stringhe palindrome contenute al centro delle 
stringhe di A. */

#include <iostream>

using namespace std;


int esercizio28(string* A, int n){
    int max = 0;
    for(int i = 0; i<n; i++){
        string s = A[i];
        int centro = s.length();
        int destra  = centro + 1;
        int sinistra = centro - 1;
        string pal = "";
        pal += s[centro];
        while(sinistra > 0){
            if(s[sinistra] == s[destra]){
                pal = s[sinistra] + pal + s[destra];
            }else{
                break;
            }
            sinistra--;
            destra++;
        }
        if(max < pal.length()){
            max = pal.length();
        }
    }
    return max;
}

void Stampa_Array(string* A, int n){
    cout << "A: ";
    for(int i = 0; i<n; i++){
        cout << A[i] << "  ";
    }
    cout << endl << endl;
}

int main(){
    int n = 5;
    string* A = new string[n];
    A[0] = "cassa";
    A[1] = "ciaoalolaciao";
    A[2] = "cioroci";
    A[3] = "ebekeba";
    A[4] = "aaeiokoieba";

    Stampa_Array(A, n);

    cout << "La massima lunghezza delle stringhe palindrome contenute al centro delle stringhe di A è: " << esercizio28(A, n) << endl;
    
}