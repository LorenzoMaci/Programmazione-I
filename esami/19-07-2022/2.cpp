/*Scrivere una funziona che prenda in input un Vettore A
di dimensione n di puntatori a caratteri (stringhe di C)
e uno short k e restituisca true se esiste almeno una stringa
in A, che abbiamo almeno k caratteri in comune con una qualsiasi
altra stringa di A. NB si presti attenzione ai puntatori a null!*/

#include <iostream>

using namespace std;

bool es2(char** A, int n, short k){
    for(int i=0; i<n; i++){
        if(A[i]){
            for(int j=0; j<n; j++){
                if(A[j] && i != j){
                    int a = 0;
                    int b = 0;
                    int counter_comuni = 0;
                    while(A[i][a]){
                        b = 0;
                        while(A[j][b]){
                            if(A[i][a] == A[j][b]){
                                counter_comuni++;
                                break;
                            }
                            b++;
                        }
                        a++;
                    }
                    if(counter_comuni >= k){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/*bool es2bis(char** A, int n, short k) {
    for(int i=0; i<n; i++) { //scorre gli elementi di A
        if(A[i]) { //controllo puntatori
            for(int j=0; j<n; j++) { //confronta stringa A[i] con A[j]
                if(A[j] && i!=j) { //controllo puntatori e stringhe distinte
                    int common = 0;
                    for(int a=0; a<strlen(A[i]); a++) { //scorre la stringa A[i]
                        for(int b=0; b<strlen(A[j]; b++)) { //scorer la stringa A[j]
                            if(A[i][a]==A[j][b])
                                common++;   
                        }
                    }
                    if(common>=k) { //se A[i] ha almeno k caratteri in comune con A[j]
                        return true; //ho trovato almeno una stringa che rispetta la condizione
                                     //quindi restituisco true
                    }
                }
            }
        }
    }
    return false;
}*/

int main() {
    char s1[] = "ciao";
    char s2[] = "supercalifragili";

    int a =0;
    int b = 0;
    int count = 0;
    while(s1[a]) {
        b=0;
        while(s2[b]) {
            if(s1[a]==s2[b]) {
                count++;
                break;
            }
            b++;
        }
        a++;
    }

    cout << count; 
}