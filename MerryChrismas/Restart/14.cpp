/*14.Scrivere un metodo che prenda come parametri
formali una matrice A di stringhe ed un intero k, e
restituisca in output una copia di A in cui tutte le
stringhe della colonna k-esima siano state epurate
dalle lettere non italiane. */


#include <iostream>

using namespace std;

string** esercizio14(string** A, int n, int m, int k){
    string** B = new string*[n];
    for(int i = 0; i<n; i++){
        B[i] = new string[m];
    }
    string s = "";
    for(int j = 0; j<m; j++){
        for(int i=0; i<n; i++){
            s = A[i][j];
            for(int p = 0; p<s.length(); p++){
                if(j == k-1){
                    if(s[p] == 'j' || s[p] == 'k' || s[p] == 'w' || s[p] == 'y' || s[p] == 'x'
                    || s[p] == 'J' || s[p] == 'K' || s[p] == 'W' || s[p] == 'Y' || s[p] == 'X'){
                        s[p] = '*';
                    }
                }
            }
            B[i][j] = s;
        }
    } 
    cout<< "Matrice Epurata: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << B[i][j] << "    \t"; 
        }
        cout << endl;
    }
    cout << endl;

    return B;
}

void Stampa_Matrice(string** A, int n, int m){
    cout<< "Matrice: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << A[i][j] << "    \t"; 
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 3;
    int m = 4;
    int k = 3;

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }
    A[0][0] = "casale";
    A[0][1] = "portone";
    A[0][2] = "giokco";
    A[0][3] = "orto";
    A[1][0] = "mare";
    A[1][1] = "cappello";
    A[1][2] = "barKcya";
    A[1][3] = "astro";
    A[2][0] = "male";
    A[2][1] = "noialtri";
    A[2][2] = "mWostrxoY";
    A[2][3] = "bastone";
    
    Stampa_Matrice(A, n, m);

    esercizio14(A, n, m, k);
}
