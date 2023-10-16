/* Scrivere una funzione in C++ che prenda in input un array di puntatori a float A
   di dimensione n e un float f e restituisca un valore booleano che sia pari
   a true se l'array A contiene almeno floor(n/2) (leggasi "base" o parte intera) elementi 
   la cui differenza in valore assoluto da ciascun altro elemento di A non sia superiore a 
   f*(b-a)/2, dove a e b sono rispettivamente il minimo e il massimo valore di A. 
   Nota: si presti attenzione ai puntatori nulli!*/

   #include<cmath>
   using namespace std;

   bool es1(float **A, int n, float f) {
        float a, b;

        // Per inizializzare a e b opportunamente
        bool init = false;
        
        // Ricerca minimo e massimo
        for(int i=0; i<n; i++) {
            if(A[i]) {
                if(!init) { //inizializza a e b se non già fatto
                    a=b=*A[i];
                    init = true;
                }
                if(*A[i]<a) //ricerca minimo
                    a=*A[i];
                if(*A[i]>b) //ricerca massimo
                    b=*A[i];
            }
        }

        int count = 0;
        for(int i=0; i<n; i++) { //elementi A[i]
            bool valid = true; //controlla se l'elemento A[i] è valido
            for(int j=0; j<n; j++) {
                if(A[i] && A[j] && i!=j) {
                    if(abs(*A[i]-*A[j])>f*(b-a)/2) {
                        valid = false; //condizione non verificata per A[i]
                        break;
                    }
                }
            }
            if(valid) {
                count++;
                if(count>=n/2)
                    return true;
            }
        }

        return false;
   }