/*[Esercizio 12] Scrivere un metodo che preveda un parametro 
formale matrice quadrata di stringhe di dimensioni n × n, uno 
short k ed una stringa s, e restituisca un array di n puntatori 
a stringhe in cui il generico elemento di indice i contiene la
i-esima stringa della diagonale secondaria se questa ha lunghezza
maggiore o uguale a k e inizia con la stringa s, altrimenti la
corrispondente stringa della diagonale principale.*/

#include <iostream>

using namespace std;

string** esercizio12(string** S, int n, short k, string s){
    string** R = new string*[n];

    for(int i=0; i<n; i++){
        R[i] = new string("");
    }

    for(int i=0; i<n; i++){
        if(S[i][n - i -1].length() >= k &&  S[i][n - i - 1].find(s) != string::npos){
            *R[i] = S[i][n - i -1];
        }else{
            *R[i] = S[i][i];
        }
    }
    cout << endl << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << *R[i] << "     ";
    }
    cout << endl;

    return R;
}

void Stampa_Matrice(string** S, int n){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< S[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    short k = 5;
    string s = "chi";

    string** S = new string*[n];
    for(int i = 0; i<n; i++){
        S[i] = new string[n];
    }

    S[0][0] = "camion";
    S[0][1] = "barella";
    S[0][2] = "bonucci";
    S[0][3] = "chiellini";
    S[1][0] = "adani";
    S[1][1] = "palla";
    S[1][2] = "orchestra";
    S[1][3] = "molletta";
    S[2][0] = "gioco";
    S[2][1] = "rajang";
    S[2][2] = "teostra";
    S[2][3] = "lunastra";
    S[3][0] = "chimera";
    S[3][1] = "hunter";
    S[3][2] = "picnic";
    S[3][3] = "rick";

    Stampa_Matrice(S, n);

    esercizio12(S, n, k, s);
}