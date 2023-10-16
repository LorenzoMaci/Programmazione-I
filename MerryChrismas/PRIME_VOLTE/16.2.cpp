/*16.Due stringhe si dicono c-equivalenti se esse
risultano uguali dopo aver eliminato da ambedue tutte
le occorrenze del carattere c. Scrivere un metodo che
prenda in input una matrice A di puntatori a stringhe
ed un carattere c, e restituisca un boolean che indichi
se esistono in A due stringhe c-equivalenti. */

#include <iostream>

using namespace std;

bool esercizio16(string*** A, int n, int m, char c){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]){
                string a = *A[i][j];
                string b = "";
                for(int k=0; k<m; k++){
                    if(A[i][k] && j != k){
                        b = *A[i][k];
                        for(int p=0; p<a.length(); p++){
                            for(int z=0; z<b.length(); z++){
                                if(a[p] == c && b[z] == c){
                                    a[p] = '*';
                                    b[z] = '*';
                                }
                            }
                        }
                    }
                    if(a == b){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Stampa_Matrice(string*** A, int n, int m){
    //Stampa matrice con controllo se la stringa è nulla
    cout << "Matrice: " << endl << endl;
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j]){
                cout << *A[i][j] << "    \t";
            }
            else{
                cout << "*   \t"; 
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    char c = 'x';

    string*** A = new string**[n];
    for(int i = 0; i<n; i++){
        A[i] = new string*[m];
    }

    A[0][0] = new string("por");
    A[0][1] = new string("porxtonex");
    A[0][2] = new string("porxtonex");
    A[0][3] = new string("xcasa");
    A[1][0] = new string("cipxresxso");
    A[1][1] = new string("cesxso");
    A[1][2] = new string("gesxso");
    A[1][3] = new string("xciao");
    A[2][0] = new string("carxta");
    A[2][1] = new string("mxobile");
    A[2][2] = new string("casa");
    A[2][3] = new string("nastxro");
    A[3][0] = new string("pixede");
    A[3][1] = new string("naxso");
    A[3][2] = new string("xciao");
    A[3][3] = new string("asxcxelxla");

    Stampa_Matrice(A, n, m);

    if(esercizio16(A, n, m, c)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}