/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice 
di puntatori a interi di dimensioni n x m, un double z ed uno short k 
(si assuma k<n). Il metodo restituisca il numero di colonne che contengono 
almeno k elementi contigui la cui media aritmetica risulti minore di z . */

/* Più corretto dell' 1.cpp */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int itinere1(int*** A, int n, int m, double z , short k){
    int colonne = 0;
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            double somma = 0;
            int contigui = 0;
            bool condizione = false;
            for(int p=i; p<n; p++){
                if(A[p][j]){
                    somma += *A[p][j];
                    contigui++;
                    if(contigui >= k){
                        double media = somma/contigui;
                        if(media < z){
                            condizione = true;
                            break;
                        }
                    }
                }else{
                    somma = 0;
                    contigui = 0;
                }
            }
            if(condizione){
                colonne++;
            }
        }
    }
    return colonne;
}

void Stampa_Matrice(int*** M, int n, int m){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(M[i][j]){
                cout << *M[i][j] << "    \t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4;
    int m = 4;
    double z = 6.7;
    short k = 2;

    srand(time(NULL));

    int*** M = new int**[n];
    for(int i = 0; i<n; i++){
        M[i] = new int*[m];
        for(int j = 0; j<m; j++){
            M[i][j] = new int(rand()%15);
        }
    }

    Stampa_Matrice(M, n, m);

    cout << "Il numero di colonne è: " << itinere1(M, n, m, z, k) << endl;
}