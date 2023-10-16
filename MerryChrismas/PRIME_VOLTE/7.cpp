/*7.Scrivere un metodo che prenda in input un
parametro formale matrice A di puntatori ad interi di
dimensione nxm, due double d1 e d2 ed uno short s, e
restituisca il numero di colonne di A nelle quali
esistano almeno s coppie di elementi contigui (ES:
A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il
secondo elemento sia compreso tra d1 e d2. NB: Si
assuma a priori che s<=n-1 e che d1 < d2. Si presti
attenzione ai numeri "mancanti"nella matrice A.
*/

#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int esercizio7 (int** A, int n, int m, double d1, double d2, short s){
     int temp1=0;
     int temp2=0;
     double rapporto=0;
     for(int j=0; j<m; j++){
         int colonne=0;
         for(int i=0; i<n-1; i++){
             temp1= A[i][j];
             temp2= A[i+1][j];
             cout << "-------------------------"<< endl;
             cout<< "temp1 = "<< temp1 << endl;
             cout<< "temp2 = "<< temp2 << endl;
             if(temp2 != 0){
                 rapporto= (double)temp1/temp2;
                 cout << "Il rapporto è "<< rapporto << endl;
                 if (d1 < rapporto || rapporto < d2){
                     colonne++;
                     cout<< "le colonne sono: "<<colonne << endl;
                 }
             }
        
         }
         if(d1<d2){
             return true;
         }
         return colonne;
     }
     return false;
}

void matrice(int** A, int n, int m){
    cout << "Matrice: "<<endl;
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            if(j!=m-1){
                cout << A[i][j]<< "\t";
            }
            else{
                cout << A[i][j]<< endl;
            }
        }
    }
}

int main(){
    int n = 3;
    int m = 3;
    double d1= 2.3;
    double d2= 3.4;
    short s;

    int** A = new int*[n];
    for(int i = 0; i<n; i++){
     A[i] = new int[n];  
    }
    srand(time(0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            A[i][j] = rand()%15;
        }
    }

    matrice( A, n, m);

    cout << endl;
    if(esercizio7(A, n, m, d1, d2, s)){
        cout << "VERO" << endl;
    }
    else{
        cout << "FALSO" << endl;
    }
}