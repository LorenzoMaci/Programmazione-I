/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice 
di puntatori a interi di dimensioni n x m, un double z ed uno short k 
(si assuma k<n). Il metodo restituisca il numero di colonne che contengono 
almeno k elementi contigui la cui media aritmetica risulti minore di z . */

#include <iostream>

using namespace std;

int es1(int*** M, int n, int m, double z, short k){
    int counter_colonne = 0;
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            double somma = 0;
            int counter_contigui = 0;
            double media = 0;
            if(M[i][j]){
                for(int k=i; k<n; k++){
                    if(M[k][j]){
                        somma += *M[k][j];
                        counter_contigui++;                        
                    }
                }
                if(counter_contigui >= k){
                        media = (double) somma/counter_contigui;
                    }
            }
            if(media > z){
                counter_colonne++;
            }
        }
    }
    return counter_colonne;
}

void Stampa_Matrice(int*** A, int n, int m){
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
    int n = 4;
    int m = 4;
    double z = 4.3;
    short k = 2;

    srand(time(0));

    int*** M = new int**[n];
    for(int i = 0; i<n; i++){
        M[i] = new int*[m];
        for(int j = 0; j<m; j++){
            M[i][j] = new int(rand()%15);
        }
    }

    Stampa_Matrice(M, n, m);

    cout << "Il numero di colonne è: " << es1(M, n, m, z, k) << endl;
}

