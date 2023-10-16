/*36.Scrivere un metodo che prenda in input una
matrice di stringhe di dimensioni n×m, due stringhe x
e y e due short k e w; il metodo restituisca la
percentuale di colonne della matrice che contengono
almeno k stringhe contenenti almeno w caratteri
presenti sia in x che in y. NB: si assuma, per
semplicità, che ognuna delle stringhe della matrice non
che le stringhe x e y non contengano lo stesso
carattere più di una volta.*/

#include <iostream>

using namespace std;

int esercizio36(string** M, int n, int m, string x, string y, short k, short w){
    int counter_caratterix;
    int counter_caratteriy;
    int counter_stringhe;
    int colonne = 0;
    for(int j = 0; j<m; j++){
        counter_stringhe = 0;
        for(int i=0; i<n; i++){
            counter_caratterix = 0;
            counter_caratteriy = 0;
            for(int p = 0; p<M[i][j].length(); p++){
                for(int t = 0; t<x.length(); t++){
                    if(M[i][j][p] == x[t]){
                        counter_caratterix++;
                    }
                }
                for(int v = 0; v<y.length(); v++){
                    if(M[i][j][p] == y[v]){
                        counter_caratteriy++;
                    }
                }
            }
            if(counter_caratterix >= w && counter_caratteriy >= w){
                counter_stringhe++;
            } 
        }
        if(counter_stringhe >= k){
            colonne++;
        }
    }
    return (colonne/m)*100;
}

void Stampa_Matrice(string** M,int n , int m){
    cout<< "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << M[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    string x = "abc";
    string y = "def";
    short k = 2;        //stringhe
    short w = 1;        //caratteri

    string** M = new string*[n];
    for(int i = 0; i<n; i++){
        M[i] = new string[m];
    }

    M[0][0] = "ghilmae";
    M[0][1] = "ghilcdm";
    M[0][2] = "ghiaelm";
    M[0][3] = "ghilm";
    M[1][0] = "ghibflm";
    M[1][1] = "ghilm";
    M[1][2] = "ghibflm";
    M[1][3] = "ghilm";
    M[2][0] = "ghilm";
    M[2][1] = "ghicdlm";
    M[2][2] = "ghilm";
    M[2][3] = "ghiaelm";
    M[3][0] = "ghilm";
    M[3][1] = "ghilm";
    M[3][2] = "ghilm";
    M[3][3] = "ghilbfm";

    Stampa_Matrice(M, n, m);

    cout << "La percentuale è = " << esercizio36(M, n, m, x, y, k, w) << "%" << endl;
}