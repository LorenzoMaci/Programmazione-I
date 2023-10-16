/*Si costruisca un oggetto ContoInBanca che memorizzi i seguenti dati:
Numero di conto;
Giacenza;
Nome del proprietario;
E permetta di eseguire queste operazioni:
Ottenere il nome del proprietario;
Ottenere il numero di conto;
Ottenere la giacenza;
Effettuare un prelievo;
Effettuare un versamento;
Pagare l’imposta di bollo (pari a 34,20 €);
Pagare le spese mensili del conto (pari a 12 €);
L’oggetto deve avere due costruttori:
Un costruttore prende in input il nome del proprietario, il numero del conto e la giacenza;
Un costruttore prende in input il nome del proprietario e il numero del conto, e imposta la giacenza a zero.
Costruire una funzione main che definisca e utilizzi diversi conti correnti intestati a diverse persone.*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class ContoInBanca{
    private: 
    string numerodiconto;
    double giacenza;
    string proprietario;
    public:
    ContoInBanca(string n, double g, string p) : numerodiconto (n), giacenza (g), proprietario (p){}
    ContoInBanca(string x,  string z) : numerodiconto (x), giacenza (0), proprietario (z){}
    
    void OttieniProprietario(){
        cout << "Il proprietario del conto è: " << proprietario;
    }

    void OttieniNumeroConto(){
        cout << "Il numero del conto è: " << numerodiconto << endl;
    }

    void OttieniGiacenza(){
        cout << "La giacenza attuale del conto è: " << giacenza  << " €" << endl;
    }

    void EffettuaPrelievo(double a){
        cout << "Quanti soldi vuoi prelevare: "<<endl;
        cin >> a;
        giacenza = (double)giacenza - a;
        cout << "La giacenza attuale del conto è:: " << giacenza << " €"<< endl;
        }

    void EffettuaVersamento(double v){
        cout << "Versamento in banca: "<<endl;
        cin >> v;
        giacenza = (double)giacenza + v;
        cout << "La giacenza attuale del conto è:: "<< giacenza << " €"<< endl;
    }

    void PagaImpostaBollo(){
        if(giacenza > 5000){
            giacenza -= 34.20 ;
            cout << "La giacenza attuale del conto è: " << numerodiconto << " €"<<endl;
        }
    }

    void PagaSpeseMensiliConto(){
        giacenza -= 12.00;
        cout << "- Spese mensili conto pagate!" << endl;
    }

};

int main(){
    int n = 4;
    ContoInBanca *c[n];

    c[0] = new ContoInBanca("Pinco Pallino", "1111222233334444", 23435.00);
    c[1] = new ContoInBanca("Guido La Vespa", "0123012301230123", 456123.00);
    c[2] = new ContoInBanca("Nello Stradone", "0123321023103201", 1200.00);
    c[3] = new ContoInBanca("Ernesto Sardo", "1234567891234567", 282.64);

    for(int i = 0; i<n; i++){
        c[i]->OttieniProprietario();
        c[i]->OttieniNumeroConto();
        c[i]->OttieniGiacenza();
        c[i]->EffettuaPrelievo(250.00);
        c[i]->OttieniGiacenza();
        c[i]->EffettuaPrelievo(250.00);
        c[i]->OttieniGiacenza();
        c[i]->EffettuaVersamento(1000.00);
        c[i]->OttieniGiacenza();
        c[i]->PagaImpostaBollo();
        c[i]->OttieniGiacenza();
        c[i]->PagaSpeseMensiliConto();
        c[i]->OttieniGiacenza();
        cout << endl;
    }
}