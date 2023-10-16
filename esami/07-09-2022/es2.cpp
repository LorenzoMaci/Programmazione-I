/* Scrivere una funzione in C++ che prenda in input un array di puntatori a caratteri A di lunghezza n, una stringa s, e uno short k e restituisca un valore booleano che sia uguale a true se l'array A contiene almeno k coppie ordinate di caratteri distinti (a,b) tali che il carattere a appartenga alla stringa s e il carattere b non appartenga alla stringa s. N.B.: si presti attenzione ai puntatori null!*/ 

#include<string>
using namespace std;

bool es2(char **A, int n, string s, short k) {
    int count = 0;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(i!=j && A[i] && A[j]) {
                if (s.find(A[i])!=std::string::npos && s.find(A[j])==std::string::npos)
                    count++;
            }
        }
    }
    return count>=k;
}
