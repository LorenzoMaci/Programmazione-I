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
            int caratteri_comuni;
            for(int j=0; j<n; j++){
                if(A[j] && i != j){ //stringhe differenti
                    int a = 0;
                    caratteri_comuni = 0;
                    while(A[i][a]){
                        int b = 0;
                        while(A[j][b]){
                            if(A[i][a] == A[j][b]){
                                caratteri_comuni++;
                                break;
                            }
                            b++;
                        }
                        a++;
                    }
                }
            }
             if(caratteri_comuni >= k){
                        return true;
                    }
        }
    }
    return false;
}

int main() {
    char s1[] = "ciao";
    char s2[] = "supercalifragili";

    int n = 4;
    short k = 2;

    char** A = new char*[n];

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
    if(es2(A, n, k)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}