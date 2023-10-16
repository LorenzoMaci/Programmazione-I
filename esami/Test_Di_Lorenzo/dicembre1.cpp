/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice 
di puntatori a interi di dimensioni n x m, un double z ed uno short k 
(si assuma k<n). Il metodo restituisca il numero di colonne che contengono 
almeno k elementi contigui la cui media aritmetica risulti minore di z . */

#include <iostream>

using namespace std;

int esame1(int*** A, int n, int m, double z, short k){
    int counter = 0;
    int contigui;
    int somma;
    int counter_media;
    for(int j=0; j<m; j++){
        contigui = 0;
        for(int i=0; i<n; i++){
            somma = 0;
            counter_media = 0;
            if(A[i][j]){
                for(int x = i; x<n; x++){
                    if(A[x][j] != 0){
                        somma += *A[x][j];
                        counter_media++;
                    }
                    cout << "somma= "<<somma << endl;
                    cout << "counter_elementi_sommati= "<<counter_media << endl;
                }
                
                if(counter_media >= k){
                    double media = (double)somma/counter_media;
                    cout << "media= "<<media << endl;
                    if(media < z){
                        counter++;
                    }else{
                        break;
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
    double z = 6.7;
    short k = 2;

    srand(time(NULL));

    int*** A = new int**[n];
    for(int i = 0; i<n; i++){
        A[i] = new int*[m];
        for(int j = 0; j<m; j++){
            A[i][j] = new int(rand()%15);
        }
    }

    Stampa_Matrice(A, n, m);

    cout << "Il numero di colonne è: " << esame1(A, n, m, z, k) << endl;
}