/*26.Scrivere un metodo che prenda in input una
matrice quadrata Q di dimensioni n x n di puntatori a
stringhe e due short m e k e restituisca il valore
booleano true se la diagonale secondaria di Q contiene
almeno m stringhe con un numero di vocali minore o
uguale a k. NB: Si assuma m<=n. */

#include <iostream>

using namespace std;

bool esercizio26(string*** Q, int n, short m, short k){
    string s = "";
    int counter_vocali = 0;
    int counter_Stringhe = 0;
    for(int i=0; i<n; i++){
        if(Q[i][n - i - 1]){
            s = *Q[i][n -i -1];
            for(int p = 0; p<s.length(); p++){
                if(s[p] == 'A' || s[p] == 'E' || s[p] == 'I' || s[p] == 'O'|| s[p] == 'U'
                || s[p] == 'a' || s[p] == 'e' || s[p] == 'i' || s[p] == 'o'|| s[p] == 'u'){
                    counter_vocali++;
                }
                if(counter_vocali <= k){
                    counter_Stringhe++;
                }
            }
        }
    }
    if(counter_Stringhe >= m){
        return true;
    }
    return false;
}

void Stampa_Matrice(string*** Q, int n){
    cout << "Matrice: " << endl << endl;
     for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Q[i][j]){
                cout << *Q[i][j] << "     \t";
            }
            else{
                cout << "*    \t"; 
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    short m = 3;
    short k = 4;

    string*** Q = new string**[n];
    for(int i = 0; i<n; i++){
        Q[i] = new string*[n];
    }

    Q[0][0] = new string("casa");
    Q[0][1] = new string("safi");
    Q[0][2] = new string("brakidi");
    Q[0][3] = new string("abekeba");
    Q[1][0] = new string("kulve");
    Q[1][1] = new string("piano");
    Q[1][2] = new string("ossa");
    Q[1][3] = new string("ala");
    Q[2][0] = new string("ciao");
    Q[2][1] = new string("castoro");
    Q[2][2] = new string("mandrillo");
    Q[2][3] = new string("oca");
    Q[3][0] = new string("finestra");
    Q[3][1] = new string("tastiera");
    Q[3][2] = new string("mouse");
    Q[3][3] = new string("rajang");

    Stampa_Matrice(Q, n);

    if(esercizio26(Q, n, m, k)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}