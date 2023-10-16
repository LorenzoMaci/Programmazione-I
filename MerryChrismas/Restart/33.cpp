/*33.Scrivere un metodo che prenda in input una
matrice quadrata A di puntatori ad interi e restituisca
un double calcolato come il rapporto tra la somma
degli elementi della diagonale principale di A e la
somma degli elementi della diagonale secondaria diA
stessa. NB: Si presti attenzione ai numeri mancanti! 
*/

#include <iostream>

using namespace std;

double esercizio33(int*** A, int n){
    int principale[n];
    for(int i = 0; i<n; i++){
        principale[i] = 0;
    }

    int secondaria[n];
    for(int i = 0; i<n; i++){
        secondaria[i] = 0;
    }
    double somma_Diagonale = 0;
    //diagonale principale
    for(int i =0; i<n; i++){
        if(A[i][i]){
            principale[i] += *A[i][i];
            somma_Diagonale += principale[i];
        }
    }
    //Diagonale secondaria
    double Somma_Diagonale2 = 0;
    for(int i=0; i<n; i++){
        if(A[i][n -i -1]){
            secondaria[i] = *A[i][n -i -1];
            Somma_Diagonale2 += secondaria[i];
        }
    }
    double rapporto = (double)somma_Diagonale/Somma_Diagonale2;
    return rapporto;
}

void Stampa_Matrice(int*** A, int n){
    cout << "Matrice: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j!=n-1){
                cout << *A[i][j] << "\t";
            }
            else{
                cout << *A[i][j] << endl;
            }
        }
    }
}

int main(){
    int n = 3;
    int*** A = new int**[n];
    for(int i = 0; i<n; i++){
      A[i] = new int*[n];  
    }

    srand(time(0));

    A[0][0] = new int(rand()%15);
    A[0][1] = new int(rand()%15);
    A[0][2] = new int(rand()%15);
    A[1][0] = new int(rand()%15);
    A[1][1] = new int(rand()%15);
    A[1][2] = new int(rand()%15);
    A[2][0] = new int(rand()%15);
    A[2][1] = new int(rand()%15);
    A[2][2] = new int(rand()%15);
    
    Stampa_Matrice(A, n);

    cout << "Il rapporto tra la somma degli elementi della diagonale principale e della secondaria è: " << esercizio33(A, n) << endl;
}
