/*Scrivere un metodo chre prenda in input una matrice quadrata A di puntatori a double
Il metodo restituisca una Matrice B la cui diagonale secondaria sia costituita dagli 
elementi della colonna A la cui media aritmetica risulti maggiore tra tutte le colonne di
A, inoltre gli elementi di B non appartenti alla diagonale secondaria sono numeri pseudo-casuali
0 <= r <= 1 (tranne gli elementi che risultano nullptr!)
*/


#include <iostream>

using namespace std;

double** f(double*** A, int n){

    double media_max = DBL_MIN;
    int indice = -1;
    for(int i=0; i<n; i++){
        double somma = 0.0;
        int counter_elementi = 0;
        
        for(int j=0; j<n; j++){
            if(A[j][i]){
                somma += *A[j][i];
                counter_elementi++;
            }       
        }
        double media = somma/counter_elementi;
        if(media_max < media){
            media_max = media;
            indice = i;
        }
    }

    double** B = new double*[n];
    for(int i=0; i<n; i++){
        B[i] = new double[n];
        for(int j=0; j<n; j++){
            if( j == (n - i - 1)){
                B[i][j] = *A[i][indice];
            }else{
                B[i][j] = rand()/(RAND_MAX*1.0);
            }
        }
    }

    return B;
}

int main(){
    int n = 3;
    double*** A = new double**[n];
    for(int i=0; i<n; i++){
        A[i] = new double*[n];
        for(int j=0; j<n; j++){
            A[i][j] = new double(rand()/(double)RAND_MAX*1.0);
        }
    }

    double** B = new double*[n];
    for(int i=0; i<n; i++){
        B[i] = new double[n];
    }

    B = f(A,n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << B[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}