/*Definire una classe Punto2D che permetta di rappresentare punti bidimensionali con 
coordinate di tipo double. Si costruisca dunque una classe Scatter che abbia come variabile 
un array di puntatori a oggetti Punto2D. La classe Scatter deve avere i seguenti metodi:
1-Un costruttore che prenda in input un intero N che rappresenta il numero di punti dell’array 
e inizializzi l’array inserendo floor(N/2) punti con coordinate casuali comprese tra −2.2 e 2.2;
2-Un metodo estrai che prenda in input un intero i e restituisca il puntatore al Punto2D di indice 
i nell’array. Il metodo deve inoltre impostare a nullptr l’elemento nella posizionei dell’array;
3-Un metodo inserisci che prende in input un Punto2D e lo inserisce alla prima posizione libera 
dell’array se essa esiste;
4-Un metodo conta che restituisce il numero di puntatori che non sono nullptr nell’array;
5-Un metodo centroide che restituisce un puntatore a oggetto Punto2D che rappresenta il punto 
medio tra tutti i punti contenuti;
Si costruisca un programma che dichiari e inizializzi un oggetto di tipo Scatter con N=100 e poi 
effettui per 50 volte la seguente operazione. Calcolo del punto medio, e inserimento di questo punto 
nell’oggetto Scatter.*/

#include <iostream>

using namespace std;

class Punto2D {
    double x, y;
    public:
    Punto2D( double _x, double _y) : x(_x), y (_y) {}
    double* array(double ar [], int N){
        double a = -2.2;
        double b = 2.2;
        cout << "inserisci dimenzione dell'array "<< endl;
        cin >> N;
        srand(time(0));
        double ar[N] = {rand()/(double)RAND_MAX * (b - a) + a;}
        return ar;
    }
}