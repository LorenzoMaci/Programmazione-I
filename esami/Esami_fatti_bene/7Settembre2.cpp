/*scrivere una funzione che prenda in input un array di puntatori a caratteri A
di lunghezza n, una stringa s, e uno short k e restituisca un valore booleano pari
a true se l'Array A contiene almeno k coppie ordinate di caratteri distinti (a, b)
tali che il carattere a appartenga alla stringa s e il carattere b non appartenga 
alla stringa s. N.B si presti attenzione ai puntatori a null! */

#include <iostream>

using namespace std;

bool esame2(char** A, int n, string s, short k){
    int counter_coppie_distine = 0;
    for(int i=0; i<n; i++){
        if(A[i] && *A[i] != 0){
            for(int j=0; j<n; j++){
                if(A[j] && *A[j] != 0){
                    if(s.find(*A[i]) != string::npos && s.find(*A[j]) == string::npos){
                        counter_coppie_distine++;
                    }
                }
            }
        }
    }
    if(counter_coppie_distine >= k){
        return true;
    }
    return false;
}

void Stampa_Matrice(char** A, int n){
    cout << "ARRAY: "<<endl<<endl;
    for(int i=0; i<n; i++){
        if(A[i]){
            cout << *A[i]<< " ";
        }
    }
    cout << endl;
}

int main(){
    int n = 4;
    string s = "bello"; 
    short k = 2;

    char** A = new char*[n];
    for(int i=0; i<n; i++){
        A[i] = new char[n];
    }

    //*A[0] = 'm'; //Nel caso non ci sia
    *A[0] = 'b';
    *A[1] = 'a' ;
    *A[2] = 'w';
    *A[3] = 'z';

    

    Stampa_Matrice(A, n);

    if(esame2(A, n, s, k)){
        cout << "Vero" << endl;
    }
    else{
        cout << "False" << endl;
    }

}