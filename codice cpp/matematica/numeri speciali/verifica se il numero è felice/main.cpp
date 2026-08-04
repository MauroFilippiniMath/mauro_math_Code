/******************************************************************************

un numero è felice se nella sua sequenza si raggiunge lo 0 
al contrario è infelice se nella sua sequenza si trova anche solo uno di questi numeri: 
58, 89, 145, 42, 20, 4, 16, 37


*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
    long long n; //numero di cui si vogliono determinare i divisori
    bool b; //variabile di controllo per il ciclo di input
    
    do {
        b = false; //se i controlli vanno a buon fine esce dal ciclo 
        cout << "Isnerire un numero naturale minore di " << LLONG_MAX - 1 << "\nNumero inserito : " ;
        cin.clear ();
        cin >> n; 
        
        if (n == LLONG_MAX) { //il numero è troppo grande 
            cout << "Il numero inserito è troppo grande! riprovare" << endl;
            b = true; //così rimane nel ciclo 
            continue;//in questo modo riparte dall'inizio della fase di inpu
            }
        if (n < 0) {
            cout << "Il numero inserito è troppo piccolo quindi minore di 0! riprovare" << endl;
            b = true; //così rimane nel ciclo 
            }
    } while (b); 
    
    cout << endl << "La sequenza è: " << endl << n;
    
    //n = uno di questi valori allora o è felice per n = 1 oppure è triste
    while (n != 1 && n != 4) { 
        unsigned t = 0;                         //t = totale
        while (n) {                             //procede fino a quando non ha sommato tutti i quadrati di ogni cifra
            unsigned c = n % 10;                // c = cifra                         
            t += c*c;                           //quadrato della cifra 
            n /= 10;                            //aggiorna la cifra
        }
        n = t;                                  //n diventa = al nuovo numero trovato 
        cout << " >> " << n;
    }
    cout << " => " << (n == 1 ? "felice" : "infelice");
    return 0;
}
    
    