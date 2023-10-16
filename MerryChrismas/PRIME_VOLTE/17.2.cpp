/*17.Scrivere un metodo che prenda in input una
matrice A di numeri interi e due double w e v, e
restituisca il valore booleano true se esiste almeno una
colonna di A in cui la media dei suoi elementi e
compresa tra w e v. NB: Si assuma che w <=v. */

#include <iostream> 

using namespace std;

bool esercizio17(int** A, int n, int m, double w, double v){
    for(int j=0; j<m; j++){
        int somma_colonna = 0;
        for(int i=0; i<n; i++){
            somma_colonna += A[i][j];
            double media = (double)somma_colonna/n;
            cout << "media()= "<< media << endl;
             if(w <= media && media <= v){
                return true;
            }
        }
    }
    return false;
}

void Stampa_Matrice (int** A, int n, int m){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j]){
                cout << A[i][j] << " \t";
            }else{
                 cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    int n = 3;
    int m = 4;
    double w = 9.5;
    double v = 12.6;

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
        A[i] = new int[m];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            A[i][j] = rand()%25;
        }
    }

    Stampa_Matrice(A, n, m);

    if(esercizio17(A, n, m, w, v)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}