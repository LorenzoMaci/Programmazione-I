/* Scrivere una funzione che prenda come paramentri formali un array A di puntatori a stringhe 
di lunghezza n e una reference a intero m e restituisca il numero di coppie ordinate (a, b) di
stringhe di uguale lunghezza in a tali che A contenga a almeno m elementi nelle sue posizioni
pari che esistono in b in posizioni dispari. La funzione ponga infine in m la lunghezza media 
delle stringhe in a opportunatamente arrotondata al numero intro più vicino. */

#include <iostream>
#include <cmath>

using namespace std;

int esame2(string** A, int n, int &m){
    int lunghezza[n] = {0};
    int counter_ritorno = 0;

    for(int i=0; i<n; i++){
        if(A[i] && A[i] != nullptr){
            lunghezza[i] = (*A[i]).length();
            counter++;
        }
    }

    int counter_Caratteri;
    for(int i=0; i<n-1; i++){
        for(int j= i + 1; j<n; j++){
            counter_Caratteri = 0;
            if(lunghezza[i] == lunghezza[j]){
                string a = *A[i];
                string b = *A[j];
                for(int p=0; p<a.length(); p+=2){
                    for(int t = 1; t<b.length(); t+=2){
                        if(a[p] == b[t]){
                            counter_Caratteri++;
                        }
                    }
                }
                if(counter_Caratteri >= m){
                    counter_ritorno++;
                }
            }
        }
    }
    double somma = 0;
    for(int i=0; i<n; i++){
        somma += lunghezza[i];
    }
    m = round(somma/counter);

    return counter_ritorno;
}