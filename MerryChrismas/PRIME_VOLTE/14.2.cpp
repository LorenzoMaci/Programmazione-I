/*14.Scrivere un metodo che prenda come parametri
formali una matrice A di stringhe ed un intero k, e
restituisca in output una copia di A in cui tutte le
stringhe della colonna k-esima siano state epurate
dalle lettere non italiane. */

#include <iostream>
#include <string>

using namespace std;

string** esercizio14(string** A, int n, int m , int k){
    string** R = new string*[n];
    for(int i=0; i<m; i++){
        R[i] = new string[m];
    }

    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            string a = A[i][j];
            if(j == k-1){
                for(int p=0; p<a.length(); p++){
                    if(a[p] == 'j' || a[p] == 'k' || a[p] == 'w' || a[p] == 'x' || a[p] == 'y' 
                    || a[p] == 'J' || a[p] == 'K' || a[p] == 'W' || a[p] == 'X' || a[p] == 'Y'){
                        a[p] = '*';
                    }
                }
            }
            R[i][j] = a;
        }
    }
       cout<< "Matrice Epurata: " << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << R[i][j] << "    \t"; 
        }
        cout << endl;
    }
    cout << endl;

    return R;
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
    int k = 2;

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }
    A[0][0] = "casale";
    A[0][1] = "portonej";
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
