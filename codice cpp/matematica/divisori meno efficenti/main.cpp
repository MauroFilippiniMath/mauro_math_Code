/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
    long long n; //numero di cui si vogliono determinare i divisori
    bool b; //variabile di controllo per il ciclo di input
    
    do {
        b = false; //se i controlli vanno a buon fine esce dal ciclo 
        cout << "Inserire un numero naturale minore di " << LLONG_MAX - 1 << "\nNumero inserito : " ;
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
    
    for(long long i = n / 2; i > 1; i--){ //non stampa 1 finale perchè non si sa se il numero è primo o no
        if(n % i < 1) {             //controlla che sia un divisori verficando se il resto è uguale a 0
            cout << i << endl;       //stampa a video il divisore trovato 
            b = true;               //b viene usata per indicare se sono stati trovati divisori e quindi indica se primo o no
        }
    }
    if (b) cout << "1";                 //se non è primo stampa l'ultimo uno 
    else cout << "Il numero è primo";   //se è primo lo scrive 
    return 0;
}