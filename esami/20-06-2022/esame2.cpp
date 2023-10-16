/*Scrivere una funzione in C++ che prenda in input una matrice di puntatori 
a stringa A di dimensione n*m e un intero senza segno s, e restituisca un 
vettore di interi di lunghezza n il cui i-esimo elemento conti il numero di 
stringhe della riga i-esima di A che siano di lunghezza al più pari ad s e 
non siano duplicate nella stessa riga.
NB: si presti attenzione ai puntatori null*/

#include <iostream>

using namespace std;

int* es2(string*** A, int n, int m, unsigned int s){
    int* R = new int[n];
    for(int i=0; i<n; i++){
        R[i] = 0;
    }

    int counter = 0;
    int counter_duplicati;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]){
                int lunghezza = (*A[i][j]).length();
                if((*A[i][j]).length() == lunghezza){
                    if(lunghezza <= s){
                        counter_duplicati = 0;
                        for( int k = 0; k<m; k++){ // inizializzo k come variabile della colonna per il controllo della duplicazione
                            if(j != k){ //per evitare che siano dupicate faccio questo controllo per controllare
                            // se la colonna di j è diversa dalla variabile k del confronto
                            cout << "*A[i][j]= "  <<  *A[i][j] << " ," << endl;
                            cout << "*A[i][k]= " << *A[i][k] <<"  , " <<endl;
                                if((*A[i][j]) == (*A[i][k])){
                                    counter_duplicati++;
                                }
                            }
                        }
                        if(counter_duplicati == 0){
                            counter++;
                        }
                    }
                }
            }
        }
        R[i] = counter;
    }
    return R;
}

void Stampa_Matrice(string*** A, int n, int m){
    cout << "MATRICE: " << endl << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j]){
                cout << *A[i][j] << " \t";
            }else{
                cout << "* \t"; 
            }
        }
        cout << endl;
    }
}

int main(){
    int n = 4;
    int m = 4;   
    unsigned int s = 4;

    string*** A = new string**[n];
    for(int i=0; i<n; i++){
        A[i] = new string*[m];
    }

    A[0][0] = new string("casa");
    A[0][1] = new string("chiosco");
    A[0][2] = new string("chiesa");
    A[0][3] = new string("ciao");
    A[1][0] = new string("giardino");
    A[1][1] = new string("penisola");
    A[1][2] = new string("catacombe");
    A[1][3] = new string("albero");
    A[2][0] = new string("dita");
    A[2][1] = new string("saladin");
    A[2][2] = new string("rutilia");
    A[2][3] = new string("salute");
    A[3][0] = new string("intelletto");
    A[3][1] = new string("fede");
    A[3][2] = new string("magia");
    A[3][3] = new string("cane");

    Stampa_Matrice(A,n,m);

    cout <<"array: "<<endl <<endl;
    int* R = new int[n];
    for(int i=0; i<n; i++){
        R[i] = 0;
    }
    R = es2(A, n, m, s);
    for(int i=0; i<n; i++){
        cout << R[i] << " ";
    }
    cout << endl;
}