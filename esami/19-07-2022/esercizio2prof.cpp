/* Si scriva una funzione in C++ che prenda in input un vettore A di dimensione
   n di puntatori a carattere (da interpretarsi come stringhe di C) e 
   uno short k e restituisca true se esiste almeno una stringa in A che 
   abbia almeno k caratteri in comune con una qualsiasi altra stringa di A. 
   NOTA: si presti attenzione ai puntatori nulli!*/

bool es2(char** A, int n, short k) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i] && A[j] && i != j){
                int a = 0;
                int caratteri_comuni = 0;
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
                if(caratteri_comuni >= k){
                    return true;
                }
            }
        }
    }
    return false;
}

#include<iostream>
using namespace std;
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