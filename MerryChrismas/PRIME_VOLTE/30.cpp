/*30.Scrivere un metodo che prenda in input una
matrice di stringhe A e due numeri short senza segno,
k ed s, e restituisca il valore booleano true se esiste
almeno una riga di A contenente almeno k stringhe
ognuna contenente un numero di lettere maiuscole
minore di s. */

#include <iostream>
#include <string>

using namespace std;

bool esercizio30(string** A, int n, int m, unsigned short k, unsigned short s){
    int stringhe;
    int lettere;
    for(int i=0; i<n; i++){
        stringhe=0;
        for(int j=0; j<m; j++){
            cout << "A[" << i << "][" << j << "] = " << A[i][j] << endl;
            lettere=0;
            string w= A[i][j];
            for(int p=0; p<w.length(); p++){
                if(w[p] >= 'A' && w[p] <= 'Z'){
                lettere++;
            }
        }
        cout << "Maiuscole = " << lettere << endl;
            if(lettere < s){
            stringhe++;
        }
    }
    cout << "stringhe = " << stringhe << endl;
    cout << "-----------------------------------------" << endl;
        if(stringhe>= k){
            return true;
        }
    }
    return false;
}


void Stampa_Matrice(string** A, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(j!=m-1){
                cout << A[i][j] << "    \t";
            }
            else{
                cout << A[i][j] << endl;
            }
        }
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    unsigned short k = 2;   //stringhe per riga
    unsigned short s = 3;   //vocali

    string** A = new string*[n];
    for(int i = 0; i<n; i++){
        A[i] = new string[m];
    }

    A[0][0] = "AAAcamion";
    A[0][1] = "AAAbarella";
    A[0][2] = "AAAbonucci";
    A[0][3] = "chiellini";
    A[1][0] = "AAAadani";
    A[1][1] = "AAApalla";
    A[1][2] = "orchestra";
    A[1][3] = "AAAmolletta";
    A[2][0] = "gioco";
    A[2][1] = "AAArajang";
    A[2][2] = "AAAteostra";
    A[2][3] = "AAAlunastra";
    A[3][0] = "AAApane";
    A[3][1] = "hunter";
    A[3][2] = "AAApicnic";
    A[3][3] = "AArick";

    Stampa_Matrice(A, n, m);

    if(esercizio30(A, n, m, k, s)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}