/* Scrivere una funzione in C++ che prenda in input un array tridimensionale A di puntatori a interi di dimensione n x n x n (A è un cubo) e restituisca un array di puntatori a interi di dimensione n il cui i-esimo elemento punti al valore puntato dall'i-esimo elemento della diagonale principale di A, se questo è superiore al corrispondente elemento della diagonale secondari, mentre punti a null altrimenti. N.B.: si presti attenzione ai puntatori null! */

int** es1(int ****A, int n) {
    int **out = new int*[n];
    for(int i=0; i<n; i++) {
        if(A[i][i][i] && A[i][n-i-1][n-i-1] && *A[i][i][i] > *A[i][n-i-1][n-i-1])
            out[i] = A[i][i][i];
        else
            out[i] = nullptr;
    }
    return out;
}