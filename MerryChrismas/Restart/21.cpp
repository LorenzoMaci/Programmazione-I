/*21.Scrivere un metodo che prenda in input una
matrice di double D ed un intero a, e restituisca il
valore booleano true se esiste almeno una colonna in
D nella quale la somma di una qualsiasi coppia di
elementi adiacenti, approssimata all'intero piu vicino,
sia uguale ad a.*/

#include <iostream>
#include <cmath>


using namespace std;

bool esercizio21(double** D, int n, int m, int a){
    double somma;
    for(int j=0; j<m; j++){
        somma = 0;
        for(int i=0; i<n-1; i++){
            somma += D[i+1][j];
            cout << "somma= "<<somma << endl;
        }
        cout << "arrotondamento somma= "<< round(somma) << endl;
        if(round(somma) == a){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(double** D, int n, int m){
    cout << "Matrice :"<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << D[i][j]<< " \t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int n = 4;
    int m = 4;
    int a = 11;

    double** D = new double*[n];
    for(int i = 0; i<n; i++){
        D[i] = new double[m];
    }

    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            D[i][j] = rand()/(double)RAND_MAX*8;
        }
    }

    Stampa_Matrice(D, n, m);

    if(esercizio21(D, n, m, a)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    } 
}