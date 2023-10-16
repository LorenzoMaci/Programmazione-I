/*Scrivere un metodo che prenda in input una matrice
quadrata di puntatori a stringhe Q ed una stringa s. Il
metodo restituisca il valore booleano true se e solo se
il numero di stringhe che contengono s, presenti nella
diagonale principale di Q, e maggiore del numero di
stringhe che contengono s presenti nella diagonale
secondaria di Q. */ 

#include <iostream>

using namespace std;

bool esercizio8(string*** Q, int n, string s){
    string diagonale = "";
    string diagonale2 = "";
    int s1 = 0;
    int s2 = 0;
    for(int i=0; i<n; i++){
        diagonale = *Q[i][i];
        diagonale2 = *Q[i][n - i - 1];
        if(diagonale.find(s) != string::npos){
            s1++;
        }
        if(diagonale2.find(s) != string::npos){
            s2++;
        }
    }
    if(s1 > s2){
        return true;
    }
    return false;
}

void Stampa_Matrice(string*** Q, int n){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(Q[i][j]){
                cout << *Q[i][j] << " \t";
            }else{
                cout << *Q[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 3;
    string s = "ia";

    string*** Q = new string**[n];
    for(int i = 0; i < n; i++){
        *Q[i] = new string*[n];
    }    
    Q[0][0] = new string("casa");
    Q[0][1] = new string("oiapprppaio");
    Q[0][2] = new string("oo");
   // Q[0][3] = new string("abekeba");
    Q[1][0] = new string("abeiokoieba");
    Q[1][1] = new string("piano");
    Q[1][2] = new string("ossa");
    //Q[1][3] = new string("ala");
    Q[2][0] = new string("ciao");
    Q[2][1] = new string("oo");
    Q[2][2] = new string("abekeba");
    //Q[2][3] = new string("abeiokoieba");
    Q[3][0] = new string("piano");
    Q[3][1] = new string("ossa");
    Q[3][2] = new string("ala");
    //Q[3][3] = new string("ciao");
    Stampa_Matrice(Q, n);

    if(esercizio8(Q, n,s)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}