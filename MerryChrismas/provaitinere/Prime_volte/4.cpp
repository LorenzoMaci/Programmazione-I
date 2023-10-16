/*[Esercizio 4] Scrivere un metodo che prenda
in input due parametri formali: una matrice
A di dimensioni n × m ed una matrice B di
dimensioni k × n entrambe di interi positivi.
Il metodo restituisca un array C di double di
dimensione n nel quale lo i-esimo elemento
dello array C sia uguale al rapporto tra la
somma degli elementi della riga i-esima di A
e il prodotto degli elementi della colonna i-esima di B.*/

#include <iostream>
#include <string>

using namespace std;

double* esercizio4(int** A, int n, int m, int** B, int k){
    double* C = new double[n];
    for(int i=0; i<n; i++){
        C[i]=0;
    }
    //Array temporaneo somma per evitare errori
    double* A1 = new double[n];
    for(int i = 0; i<n; i++){
        A1[i] = 0;
    }
    //Array temporaneo prodotto per evitare errori
    double* B1= new double[n];
    for(int i=0; i<n; i++){
        B1[i] = 0;
    }
    int sommariga;
    for(int i=0; i<n; i++){
        sommariga=0;
        for(int j=0; j<m; j++){
            sommariga += A[i][j];
        }
        A1[i] = sommariga;
    }
    int prodottocolonna;
    for(int i=0; i<k; i++){
        prodottocolonna=1;
        for(int j=0; j<n; j++){
            prodottocolonna *= B[j][i];
        }
        B1[i] = prodottocolonna;
    }
    for(int i=0; i<n; i++){
        if(B1[i] != 0){             //evitare che spunti inf nel main che senza i due double A1 e B1 può capitare
            C[i]= (double)A1[i]/B1[i];
        }else{
            C[i] = 0;
        }
    }
    return C;
}

void Stampa_Matrice(int** A, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]){
                cout << A[i][j] << " \t";
            }else{
                cout << A[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4; 
    int m = 4; 
    int k = 4; 

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[m];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            A[i][j] = rand()%15;
        }
    }
    cout << "Matrice (A):" << endl << endl;
    Stampa_Matrice(A, n, m);

    int** B = new int*[k];
    for(int i = 0; i<k; i++){
        B[i] = new int[n];
    }

    srand(time(0));
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++){
            B[i][j] = rand()%15;
        }
    }
    cout << "Matrice (B):" << endl << endl;
    Stampa_Matrice(B, k, n);

    cout << "Array:     ";
    for(int i = 0; i<n; i++){
        cout << esercizio4(A, n, m, B, k)[i] << "      ";
    }
    cout << endl;
}