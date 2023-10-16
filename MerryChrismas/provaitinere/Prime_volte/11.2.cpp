/*[Esercizio 11] Scrivere un metodo che preveda un parametro 
formale matrice di char di dimensione n × m ed un ulteriore
parametro intero a, e restituisca il valore booleano true se 
esiste almeno una riga o una colonna che contiene almeno a 
caratteri che siano tutti minuscoli o tutti maiuscoli e che 
abbiano posizioni adiacenti. NB: Si assuma che la matrice 
contenga solo caratteri corrispondenti alle lettere dell’alfabeto.*/

#include <iostream>

using namespace std;

bool esercizio11(char** C, int n, int m, int a){
    int counter_Maiuscole;
    int counter_minuscole;
    //controllo riga
    for(int i=0; i<n; i++){
        counter_Maiuscole = 0;
        counter_minuscole = 0;
        for(int j=0; j<m; j++){
            if(C[i][j] >= 'A' && C[i][j] <= 'Z'){
                counter_Maiuscole++;
                counter_minuscole = 0; //Questo perchè deve essere una riga solamente di Maiuscole
            }
            if(C[i][j] >= 'a' && C[i][j] <= 'z'){
                counter_minuscole++;
                counter_Maiuscole = 0; //Questo perchè deve essere una riga solamente di minuscole
            }
        }
        if(counter_Maiuscole >= a || counter_minuscole >= a){
            return true;
        }
    }
    //controllo colonne
    for(int j=0; j<m; j++){
        counter_Maiuscole = 0;
        counter_minuscole = 0;
        for(int i=0; i<n; i++){
            if(C[i][j] >= 'A' && C[i][j] <= 'Z'){
                counter_Maiuscole++;
                counter_minuscole = 0;
            }
            if(C[i][j] >= 'a' && C[i][j] <= 'z'){
                counter_minuscole++;
                counter_Maiuscole = 0;
            }
        }
        if(counter_Maiuscole >= a && counter_minuscole >= a){
            return true;
        }
    }
    return false;
}

void Stampa_Matrice(char** C, int n, int m){
    cout << "MATRICE: "<<endl << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << C[i][j] << " \t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int n = 4; 
    int m = 4;
    int a = 3;
    char** C = new char*[n];
    for(int i = 0; i<n; i++){
        C[i] = new char[m];
    }
    
    C[0][0] = 'a';
    C[0][1] = 'B';
    C[0][2] = 'C';
    C[0][3] = 'D';
    C[1][0] = 'E';
    C[1][1] = 'f';
    C[1][2] = 'G';
    C[1][3] = 'h';
    C[2][0] = 'i';
    C[2][1] = 'L';
    C[2][2] = 'm';
    C[2][3] = 'N';
    C[3][0] = 'O';
    C[3][1] = 'p';
    C[3][2] = 'Q';
    C[3][3] = 'r';
    Stampa_Matrice(C, n, m);

    if(esercizio11(C, n, m, a)){
        cout << "Vero" << endl;
    }
    else{
        cout << "Falso" << endl;
    }
}