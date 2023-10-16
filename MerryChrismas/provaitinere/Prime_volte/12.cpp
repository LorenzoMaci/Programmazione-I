/*[Esercizio 12] Scrivere un metodo che preveda un parametro 
formale matrice quadrata di stringhe di dimensioni n × n, uno 
short k ed una stringa s, e restituisca un array di n puntatori 
a stringhe in cui il generico elemento di indice i contiene la
i-esima stringa della diagonale secondaria se questa ha lunghezza
maggiore o uguale a k e inizia con la stringa s, altrimenti la
corrispondente stringa della diagonale principale.*/

#include <iostream>
#include <string>

using namespace std;

string* esercizio12(string** B,int n,short k, string s){
    string** A= new string*[n];

    A[0] = new string("");
    A[1] = new string("");
    A[2] = new string("");
    A[3] = new string("");

    int counter;
    string diagonale="";
    string diagonale2="";
    for(int i=0; i<n; i++){
        counter=0;
        diagonale = B[i][i];
        diagonale2 = B[i][n - i -1];
        for(int p=0; p<s.length(); p++){
            if(diagonale2[p] == s[p]){
                counter++;
            }
            if(diagonale2.length() >= k && counter == s.length()){
                *A[i]= diagonale2;
            }else{
                *A[i]= diagonale;
            }
        }
    }
    cout << endl << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << *A[i] << "     ";
    }
    cout << endl;

   return *A;
}

void Stampa_Matrice(string** B, int n){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<< B[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    short k = 5;
    string s = "chi";

    string** B = new string*[n];
    for(int i = 0; i<n; i++){
        B[i] = new string[n];
    }

    B[0][0] = "camion";
    B[0][1] = "barella";
    B[0][2] = "bonucci";
    B[0][3] = "chiellini";
    B[1][0] = "adani";
    B[1][1] = "palla";
    B[1][2] = "orchestra";
    B[1][3] = "molletta";
    B[2][0] = "gioco";
    B[2][1] = "rajang";
    B[2][2] = "teostra";
    B[2][3] = "lunastra";
    B[3][0] = "chimera";
    B[3][1] = "hunter";
    B[3][2] = "picnic";
    B[3][3] = "rick";

    Stampa_Matrice(B, n);

    esercizio12(B, n, k, s);
}