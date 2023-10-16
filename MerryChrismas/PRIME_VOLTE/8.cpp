/*Scrivere un metodo che prenda in input una matrice
quadrata di puntatori a stringhe Q ed una stringa s. Il
metodo restituisca il valore booleano true se e solo se
il numero di stringhe che contengono s, presenti nella
diagonale principale di Q, e maggiore del numero di
stringhe che contengono s presenti nella diagonale
secondaria di Q. */ 

#include <iostream>
#include <string>

using namespace std;

bool esercizio8(string*** Q, int n, string s){
    int stringhe_diagonale1 = 0;
    for(int i=0; i<n; i++){
        if(Q[i][i]){
            string diagonale = *Q[i][i];
            if(diagonale.find(s) != string::npos){
                stringhe_diagonale1++;
            }
        }
    }

    int stringhe_diagonale2 = 0;
    for(int i=0; i<n; i++){
        if(Q[i][n - i -1]){
            string diagonale = *Q[i][n - i - 1];
            if(diagonale.find(s) != string::npos){
                stringhe_diagonale2++;
            }
        }
    }

    if(stringhe_diagonale1 > stringhe_diagonale2){
        return true;
    }
    return false;
}


void Stampa_Matrice(string*** Q, int n){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Q[i][j]){
                cout << *Q[i][j] << " \t";
            }else{
                 cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    /*int n = 3;
    string s = "ia";

    string*** Q = new string**[n];
    for(int i = 0; i < n; i++){
        Q[i] = new string*[n];
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
    }*/
}