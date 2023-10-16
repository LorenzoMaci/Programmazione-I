/*.Due stringhe si dicono sorelle se hanno lo stesso
numero di vocali. Scrivere un metodo che prenda in
input una matrice A di puntatori a stringhe, e
restituisca un boolean che indichi se esiste una
colonna di A in cui sono puntate almeno due stringhe
sorelle. */

#include <iostream>

using namespace std;

bool esercizio2(string*** A, int n ,int m){
    int counter;
    int lunghezza; 
    for(int j=0; j<m; j++){
        counter = 0;
        lunghezza = 0;
        for(int i=0; i<n; i++){
            if(A[i][j]){
                lunghezza = (*A[i][j]).length();
                for(int p= i + 1; p<n; p++){
                    int lunghezza2 = (*A[p][j]).length();
                    if(lunghezza == lunghezza2){
                        counter++;
                    }
                }
            }
            if(counter >= 2){
                return true;
            }
        }
    }
    return false;
}

void Stampa_Matrice(string***A, int n, int m){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }else{
                cout << *A[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 3;
    int m = 3;
    string*** A = new string**[n];
    for(int i = 0; i < n; i++){
        A[i] = new string*[m];
    }    
    A[0][0] = new string("casa");
    A[0][1] = new string("oiapprppaio");
    A[0][2] = new string("ooooo");
    A[1][0] = new string("abekeba");
    A[1][1] = new string("abeiokoieba");
    A[1][2] = new string("piano");
    A[2][0] = new string("ossa");
    A[2][1] = new string("ala");
    A[2][2] = new string("ciaoo");

    Stampa_Matrice(A, n, m);

    if(esercizio2(A, n, m)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}