/* Scrivere una funzione che prenda come paramentri formali un array A di puntatori a stringhe 
di lunghezza n e una reference a intero m e restituisca il numero di coppie ordinate (a, b) di
stringhe di uguale lunghezza in a tali che A contenga a almeno m elementi nelle sue posizioni
pari che esistono in b in posizioni dispari. La funzione ponga infine in m la lunghezza media 
delle stringhe in a opportunatamente arrotondata al numero intro più vicino. */

#include<iostream>
#include <cmath>

using namespace std;

int es2(string** A, int n, int& m){
    int coppie_ordinate = 0;
    for(int i=0; i<n; i++){
        if(A[i]){
            string a = *A[i];
            for(int j=0; j<n; j++){
                if(A[j]){
                    string b = *A[j];
                    int counter_uguali = 0;
                    if(a.length() == b.length()){
                        for(int k=0; k<a.length(); k+=2){
                            for(int p=1; p<b.length(); p+=2){
                                if(a[k] == b[p]){
                                    counter_uguali++;
                                    break;
                                }
                            }
                        }
                        if(counter_uguali >= m){
                            coppie_ordinate++;
                        }
                    }
                }
            }
        }
    }

    int somma_lunghezze = 0;

    for(int i=0; i<n; i++){
        if(A[i]){
            somma_lunghezze += A[i]->length();
        }
    }
    m = ceil(somma_lunghezze / n);

    return coppie_ordinate;
}

void Stampa_Array(string** A, int n){
    cout << "Array:    ";
    for(int i = 0; i<n; i++){
        if(A[i]){
            cout << *A[i] << "    ";
        }
    }
    cout << endl;
}

int main(){

    int n = 4;
    int m = 2;

    string** A = new string*[n];

    A[0] = new string("casa");
    A[1] = new string("acas");
    A[2] = new string("divano");
    A[3] = new string("bcks");

    Stampa_Array(A, n);

    cout << es2(A, n, m) << endl;
}