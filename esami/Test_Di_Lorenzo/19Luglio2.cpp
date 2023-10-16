/*Scrivere una funziona che prenda in input un Vettore A
di dimensione n di puntatori a caratteri (stringhe di C)
e uno short k e restituisca true se esiste almeno una stringa
in A, che abbiamo almeno k caratteri in comune con una qualsiasi
altra stringa di A. NB si presti attenzione ai puntatori a null!*/

#include <iostream>

using namespace std;

bool es2(char** A, int n , short k){
    for(int i=0; i<n; i++){
        if(A[i]){
            char* stringa = A[i];
            for(int j=0; j<n; j++){
                if(A[j] && i != j){
                    char* altra_stringa = A[j];
                    int a = 0;
                    int counter_comuni = 0;
                    while(stringa[a]){
                        int b = 0;
                        while(altra_stringa[b]){
                            if(stringa[a] == altra_stringa[b]){
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

    cout << count << endl; 
}