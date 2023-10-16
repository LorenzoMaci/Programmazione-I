/*23.Scrivere un metodo che prenda in input un
parametro formale matrice K di double di dimensioni n
x m e due interi a e b, e restituisca un array A di short
di dimensione m, in cui l'elemento A[i] e calcolato
come il numero di elementi della colonna i-esima di K
tali che, approssimati all'intero più vicino, siano
compresi tra a e b (inclusi). NB: si assuma a < b. */

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

short* esercizio23(double** K, int n, int m, int a, int b){
    short* A = new short[m];
    for(int i=0; i<m; i++){
        A[i]=0;
    }
    for(int i=0; i<m; i++){
        int contatore=0;
        for(int j=0; j<n; j++){
            cout << "---------------------------------------"<<endl;
            cout << "K[" << i << "][" << j << "] = " << K[j][i] << endl;
            cout <<"numero arrotondato: "<<  round(K[j][i]) << endl;
            if(a < round(K[j][i]) && round(K[j][i]) < b){
                contatore++;
            } 
            A[i]= contatore;
        }
    }
    return A;
}

void Stampa_Matrice(double** K, int n, int m){
    cout << "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
                cout << K[i][j]<< " \t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int n = 4;
    int m = 3;
    int a = 4;
    int b = 8;

    double** K = new double*[n];
    for(int i = 0; i<n; i++){
        K[i] = new double[m];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            K[i][j] = rand()/(double)RAND_MAX*10;
        }
    }
    Stampa_Matrice(K, n, m);

    esercizio23(K, n, m, a, b);

    /*cout << "Array:  ";
    for(int i = 0; i<m; i++){
        cout << esercizio23(K, n, m, a, b)[i] << "   \t";
    }
    cout << endl;*/
}