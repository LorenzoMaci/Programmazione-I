/*[Esercizio 13] Scrivere un metodo che preveda due 
parametri  formali matrici di interi, A e B di dimensioni
k × n ed n × k rispettivamente, e restituisca uno array 
monodimensionale di k elementi double in cui lo i-esimo 
elemento sia uguale alla differenza tra la media aritmetica
degli elementi della riga i-esima di A ed il minimo valore 
degli elementi della colonna i-esima di B.*/

#include <iostream>

using namespace std;

double* esercizio13(int** A, int k, int n, int** B){
    double* C = new double[k];
    for(int i=0; i<k; i++){
        C[i] = 0;
    }
    int somma;
    int minimo;
    int counter_nulli;
    double media;
    //media di A
    for(int i=0; i<k; i++){
        somma = 0;
        counter_nulli = 0;
        for(int j=0; j<n; j++){
           somma += A[i][j];
           counter_nulli++;
        }
        media = (double)somma/counter_nulli;
    }
    //colonna minima B
    for(int i=0; i<n; i++){
        minimo = 5000;
        for(int j=0; j<k; j++){
            if(B[i][j] < minimo){
                minimo = B[i][j];
            }
        }
        cout << "somma = " << somma << endl;
        cout << "min = " << minimo << endl;
        cout << "media = " << ((double)somma/counter_nulli) << endl;
        C[i] = (double)media - minimo;
    }
    cout << "ARRAY "<<endl <<endl;
    for(int i=0; i<n; i++){
        cout << C[i] << " \t";
    }
    cout << endl;
    return C;
}

int main(){
    int k = 4;
    int n = 4;

    int** A = new int*[k];
    for(int i = 0; i<k; i++){
        A[i] = new int[n];
    }

    //Inizializzazione casuale della matrice e stampa
    srand(time(0));
    cout << "Matrice (A):" << endl << endl;
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            A[i][j] = rand()%25;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int** B = new int*[n];
    for(int i = 0; i<n; i++){
        B[i] = new int[k];
    }

    //Inizializzazione casuale della matrice e stampa
    srand(time(0));
    cout << "Matrice (B):" << endl << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k; j++){
            B[i][j] = rand()%25;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    esercizio13(A, k, n, B);

}

