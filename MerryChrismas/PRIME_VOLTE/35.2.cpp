/*35.Scrivere un metodo che prenda in input una
matrice Q di puntatori a int di dimensione n × m e due
float a e b e restituisca un array di float di dimensione
m tale che lo i-esimo elemento dello array contiene la
media dei soli elementi della colonna i-esima compresi
tra a e b (estremi inclusi). Nel confronto tra interi e
numeri in virgola mobile si consideri l’arrotondamento
di questi ultimi al numero intero più prossimo ad essi.
NB: Si presti attenzione ai numeri mancanti! */

#include <iostream>
#include <cmath>

using namespace std;

float* esercizio35(int*** Q, int n, int m, float a, float b){
    float* R = new float[m];
    for(int i=0; i<m; i++){
        R[i] = 0;
    }

    for(int i=0; i<m; i++){
        int somma = 0;
        int elementi_non_nulli = 0;
        for(int j=0; j<n; j++){
            if(Q[j][i]){
                if(round(a) <= *Q[j][i] && *Q[j][i] <= round(b)){
                    somma += *Q[j][i];
                    elementi_non_nulli++;
                }
            }
        }
        if(elementi_non_nulli == 0){
            R[i] = 0;
        }else{
            R[i] = (float)somma/elementi_non_nulli;
        }
    }
    return R;
}

void Stampa_Matrice(int*** Q, int n, int m){
    cout << "Matrice: " << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(Q[i][j]){
                cout << *Q[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    float a = 1.4;
    float b = 4.6;

    int*** Q = new int**[n];
    for(int i = 0; i<n; i++){
        Q[i] = new int*[m];
    }

    srand(time(0));
    Q[0][0] = new int(rand()%15);
    Q[0][1] = new int(rand()%15);
    Q[0][2] = new int(rand()%15);
    Q[0][3] = new int(rand()%15);
    Q[1][0] = new int(rand()%15);
    Q[1][1] = new int(rand()%15);
    Q[1][2] = new int(rand()%15);
    Q[1][3] = new int(rand()%15);
    Q[2][0] = new int(rand()%15);
    Q[2][1] = new int(rand()%15);
    Q[2][2] = new int(rand()%15);
    Q[2][3] = new int(rand()%15);
    Q[3][0] = new int(rand()%15);
    Q[3][1] = new int(rand()%15);
    Q[3][2] = new int(rand()%15);
    Q[3][3] = new int(rand()%15);

    Stampa_Matrice(Q, n, m);

    cout << "Array:    ";
    for(int i = 0; i<m; i++){
        cout << esercizio35(Q, n, m, a, b)[i] << "    ";
    }
    cout << endl;
}