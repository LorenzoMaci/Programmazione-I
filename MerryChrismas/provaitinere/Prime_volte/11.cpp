/*[Esercizio 11] Scrivere un metodo che preveda un parametro 
formale matrice di char di dimensione n × m ed un ulteriore
parametro intero a, e restituisca il valore booleano true se 
esiste almeno una riga o una colonna che contiene almeno a 
caratteri che siano tutti minuscoli o tutti maiuscoli e che 
abbiano posizioni adiacenti. NB: Si assuma che la matrice 
contenga solo caratteri corrispondenti alle lettere dell’alfabeto.*/

#include <iostream>

using namespace std;

bool esercizio11(char** A, int n, int m, int a){
    int counter_maiuscole;
    int counter_minuscole;
    for(int i=0; i<n; i++){
        counter_maiuscole=0;
        counter_minuscole=0;
        for(int j=0; j<m; j++){
            if(A[i][j] >= 'a' && A[i][j] <= 'z'){
                counter_minuscole++;
                counter_maiuscole=0;
            }
            if(A[i][j] >= 'A' && A[i][j] <= 'Z'){
                counter_maiuscole++;
                counter_minuscole=0;
            }
        }
        if(counter_maiuscole >= a || counter_minuscole >= a){
            return true;
        }
    }

    for(int j = 0; j<m; j++){
        counter_maiuscole = 0;
        counter_minuscole = 0;
        for(int i = 0; i<n; i++){
            if(A[i][j] >= 'A' && A[i][j] <= 'Z'){
                counter_maiuscole++;
                counter_minuscole = 0;
            }
            else{
                counter_minuscole++;
                counter_maiuscole = 0;
            }
            if(counter_maiuscole >= a || counter_minuscole >= a){
                return true;
            }
        }
    }
    return false;
}

void Stampa_Matrice(char** A, int n, int m){
    cout<< "Matrice: "<<endl<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << A[i][j]<< " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4; 
    int m = 4;
    int a = 3;
    char** A = new char*[n];
    for(int i = 0; i<n; i++){
        A[i] = new char[m];
    }
    
    A[0][0] = 'a';
    A[0][1] = 'B';
    A[0][2] = 'C';
    A[0][3] = 'D';
    A[1][0] = 'E';
    A[1][1] = 'f';
    A[1][2] = 'G';
    A[1][3] = 'h';
    A[2][0] = 'i';
    A[2][1] = 'L';
    A[2][2] = 'm';
    A[2][3] = 'N';
    A[3][0] = 'O';
    A[3][1] = 'p';
    A[3][2] = 'Q';
    A[3][3] = 'r';
    Stampa_Matrice(A, n, m);

    if(esercizio11(A, n, m, a)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}