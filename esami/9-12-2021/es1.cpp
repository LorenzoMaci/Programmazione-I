/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice 
di puntatori a interi di dimensioni n x m, un double z ed uno short k 
(si assuma k<n). Il metodo restituisca il numero di colonne che contengono 
almeno k elementi contigui la cui media aritmetica risulti minore di z . */

#include <iostream>

using namespace std;

int es1(int*** A, int n, int m, double z, short k){
    int counter = 0; //ritrono
    int elementi_contigui;
    double somma;
    for(int j = 0; j<m; j++){
        for(int i = 0; i<n; i++){
            elementi_contigui = 0;
            somma = 0;
            if(A[i][j]){
                for(int p = 0; p<n-1; p++){
                    somma += *A[i][j];
                    elementi_contigui++;
                    if(elementi_contigui >= k){
                        double media = somma/elementi_contigui;
                        if(media < z){
                            counter++;
                        }else{
                            break;
                        }
                    }
                }
            }
        }
    }
    return counter;
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

