/* Si scriva una funzione in C++ che prenda in input un vettore A di dimensione
   n di puntatori a carattere (da interpretarsi come stringhe di C) e 
   uno short k e restituisca true se esiste almeno una stringa in A che 
   abbia almeno k caratteri in comune con una qualsiasi altra stringa di A. 
   NOTA: si presti attenzione ai puntatori nulli!*/

bool es2(char** A, int n, short k) {
    for(int i=0; i<n; i++) { //scorre gli elementi di A
        if(A[i]) { //controllo puntatori
            for(int j=0; j<n; j++) { //confronta stringa A[i] con A[j]
                if(A[j] && i!=j) { //controllo puntatori e stringhe distinte
                    int a = 0; //a e b indicizzano A[i] e A[j]
                    int b = 0; //rispettivamente
                    int common = 0; //conta il numero di caratteri in comune tra A[i] e A[j]
                    while(A[i][a]) { //scorre A[i] finché non trova il carattere di terminazione
                        b = 0; //resetta b
                        while(A[j][b]) { //scorre A[j] finché non trova il carattere di terminazione
                            if(A[i][a]==A[j][b]) { //se il carattere è in comune
                                common++; //incrementa caratteri in comune
                                break; //esce per evitare di contare un carattere due volte
                            }
                            b++; //incrementa indice di A[j]
                        }
                        a++; //incrementa indice di A[i]
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
}

// versione alternativa con uso di strlen
bool es2bis(char** A, int n, short k) {
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

    cout << count; 
}