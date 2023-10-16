/*Si implementi delle classi:
Giorno: rappresenta un giorno del mese espresso sia come numero che come giorno della settimana;
Mese: rappresenta un mese;
Anno: rappresenta un anno;
Le classi sopra definite dovranno avere gli opportuni costruttori e dovranno assicurarsi di ricevere 
input corretti (ad esempio Giorno dovrà rappresentare giorni compresi tra 1 e 31); Definire dunque una 
classe Data che abbia come variabili membro tre oggetti di tipo Giorno, Mese e Anno. La classe dovrà avere 
un costruttore opportuno che controlli che la data inserita sia valida, un metodo stampa che mostri la data 
nel formato “Mercoledì 22 dicembre 2021”, e un metodo differenza che prenda in input un altro oggetto di tipo 
Data e calcoli il numero di giorni che intercorrono tra le due date. 
Nota: un anno è bisestile se è divisibile per 4 ma non per 100.*/
#define GENNAIO 1
#define FEBBRAIO 2
#define MARZO 3
#define APRILE 4
#define MAGGIO 5
#define GIUGNO 6
#define LUGLIO 7
#define AGOSTO 8
#define SETTEMBRE 9
#define OTTOBRE 10
#define NOVEMBRE 11
#define DICEMBRE 12

#include <iostream>

using namespace std;

class Giorno{
    public:
    int numero;
    string settimana;
    Giorno(int n, string s): numero (n), settimana (s){}

    void Stampa_Giorno(){
        cout << "Inserisci il giorno e il numero: ";
        cin >> numero;
        cin >> settimana;
        if(numero > 0 && numero < 32){
            cout << settimana << endl;
            cout << numero << endl;
        }
    }
};

class Mese{
    public :
    int mounth;
    Mese( int m): mounth (m){}

    void Stampa_Mese(){
        cout << "Inserisci il mese(numero): ";
        cin >> mounth;
        if(mounth > 0 && mounth < 13){
            switch(mounth){
                case 1:
                cout << " Gennaio ";    
                break;
                case 2:
                cout << " Febbraio ";    
                break;
                case 3:
                cout << " Marzo ";    
                break;
                case 4:
                cout << " Aprile ";    
                break;
                case 5:
                cout << " Maggio ";    
                break;
                case 6:
                cout << " Giugno ";    
                break;
                case 7:
                cout << " Luglio ";
                break;
                case 8:
                cout << " Agosto ";    
                break;
                case 9:
                cout << " Settembre ";    
                break;
                case 10:
                cout << " Ottobre ";    
                break;
                case 11:
                cout << " Novembre ";    
                break;
                case 12:
                cout << " Dicembre ";    
                break;      
            }
            cout << mounth << endl;
        }
    }
};

class Anno{
    public:
    int year;
    Anno(int a) : year(a){}

    void Stampa_Anno(){
        cout << "Anno: ";
        cin >> year;
        if(year > 1000 && year < 9999){
            cout << year << endl;
        }
    }
};

class Data : public Giorno, public Mese, public Anno{
    Giorno numero;
    Giorno settimana;
    Mese mounth;
    Anno year;
    public:
    Data(string s, int n, int m, int a) : Giorno::settimana (s), Giorno::numero (n), Mese::mounth (m), Anno::year (a){}
    void data_Dicembre(){
        cout << s.settimana << " " << n.numero << " "<< m.mounth << " "<< a.year << endl;
    }
};

