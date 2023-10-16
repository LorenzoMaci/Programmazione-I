/*18.Scrivere un metodo che prenda in input una
matrice di puntatori a stringhe M e due numeri short
senza segno, k ed s, e restituisca il numero di colonne
contenenti almeno k stringhe con un numero di lettere
vocali minore di s.  */

#include <iostream>

using namespace std;

int esercizio18(string*** M , int n, int m, unsigned short k, unsigned short s){
    int colonne = 0;
    for(int j=0; j<m; j++){
        int stringhe = 0;
        for(int i=0; i<n; i++){
            if(M[i][j]){
                string a = *M[i][j];
                int counter_vocali = 0;
                for(int p=0; p<a.length(); p++){
                    if(a[p] == 'a' || a[p] == 'e' || a[p] == 'i' || a[p] == 'o' || a[p] == 'u'
                    || a[p] == 'A' || a[p] == 'E' || a[p] == 'I' || a[p] == 'O' || a[p] == 'U'){
                        counter_vocali++;
                    }
                }
                if(counter_vocali < s){
                    stringhe++;
                }
            }
        }
        if(stringhe >= k){
            colonne++;
        }
    }
    return colonne;
}

void Stampa_Matrice(string*** M, int n, int m){
    cout << "Matrice: " << endl<< endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
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

int main(){
    int n = 3;
    int m = 3;
    unsigned short k = 2;
    unsigned short s = 6;
    string*** M = new string**[n];
    for(int i = 0; i < n; i++){
        M[i] = new string*[m];
    }    
    M[0][0] = new string("casa");
    M[0][1] = new string("aereo");
    M[0][2] = new string("bghtl");
    M[1][0] = new string("be");
    M[1][1] = new string("abeiokoieba");
    M[1][2] = new string("piano");
    M[2][0] = new string("ossa");
    M[2][1] = new string("ala");
    M[2][2] = new string("ciaoo");

    Stampa_Matrice(M, n, m);

    cout << endl << "Il numero di colonne che soddisfano la condizione è: " << esercizio18(M, n, m, k, s) << endl;
}