/******************************************************************************

Dato un numero naturale stampare a video la cifra richiesta dall'Utente 
tramite la sua posizione

*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int cifra (int a, int b); //estrae la cifra richiesta
int cifre_massime (int a); //calcolo delle cifre di un numero
int potenza (int a, int b); //calcolo della potenza data la base ed esponente

int main()
{
    int n;          //n = numero 
    int p;          //p = posizione della cifra da estrarre 
    bool c;         //c = variabile di controllo per l'input 
    
    do {
        c = false;              //può uscire dal ciclo
        cout << "Inserire un numero naturale n (0 < n < " << INT_MAX << "). n = ";
        cin >> n; 
        cin.clear();
        
        if(n < 1 || n == INT_MAX){
            cout << "WARNING! Il valore inserito non è accettabile" << endl;
            c = true;           //non può uscire dal ciclo
        }
    } while (c);
    
    int c_max = cifre_massime (n); //c_max = massimo numero di cifre a disposizione
    
    do {
        c = false;              //può uscire dal ciclo
        cout << "Inserire un numero naturale p (0 < p < " << c_max + 1 << "). p = ";
        cin >> p; 
        cin.clear();
        
        if(p < 1 || p > c_max){
            cout << "WARNING! Il valore inserito non è accettabile" << endl;
            c = true;           //non può uscire dal ciclo
        }
    } while (c);
    
    cout << endl << "Nel numero " << n << " la cifra in posizione " << p << " è uguale a: ";
    cout << cifra(n, p-1);
    
    return 0;
}
    int cifre_massime (int a){  //funzione per calcolare il numero di cifre di un numero
        int t = 0;              //t = contatore
        while(a){ 
            t++;
            a /= 10;
        }
        return t;
    } 
    int cifra (int a, int b){   //calcola la cifra richiesta
        int po;                 //po = potenza di 10 corrispondente alla posizione della cifra - 1
        po = potenza(10, b); 
        a = (a / po) % 10;      //calcolo della cifra
                                //elimina tutte le cifre meno significative e ne estrae 
        return a;               //quella che diventa la meno significativa
    }
    int potenza (int a, int b){         //calcolo della potenza 
        int t = 1;                      //t = potenza
        for(int i = 0; i < b; i++) t *= a;
        return t;
    }