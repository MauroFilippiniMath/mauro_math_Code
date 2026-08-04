/******************************************************************************

ceil è usata per arrotondare per eccesso 

log10() usata per calcolare il numero di cifre necessarie per codificare il numero decimale
contenuto nelle parentesi usando la codifica binaria 


*******************************************************************************/
#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

#define max ceil (log10(LLONG_MAX))

int main()
{
    long long n;    //numero da decodificare in decimale
    bool b;         //variabile per verificare l'input
    
    do {
        b = false; //se alla fine b = false allora la fase di input è andata a buon fine
        
        cout << "Inserire il numero binario intero che si vuole decodificare in decimale,"
             << "sapendo che il numero massimo inseribile è di : " << max << " cifre" << endl 
             << "Numero inserito : ";
        /*
        se inserito un numero troppo grande si ha un overflow e questo porta la variabile 
        a contenere tutti 1 quindi il massimo valore inseribile in un intero.
         sfruttare
        il valore massimo per individuare se il numero inserito è troppo grande
        */
        cin >> n;       //acquisizione del numero da codificare 
        cout << endl;
        
        if(n < 0){
            cout << "Il numero inserito è negativo quando il binario non prevede il segno, riprovare.\n\n";
            b = true;   //non esce dal ciclo dell'input
            continue;
        }
        if (n >= LLONG_MAX) {   //il numero è troppo grande
            cin.clear();        //resetta cin perchè se va in overflow poi non riesce più a prendere nessun input
            cout << "Il numero inserito è troppo grande, riprovare.\n\n";
            b = true;           //non esce dal ciclo dell'input
            continue;
        }
        long long n2 = n;           //è una coppia di n
        
        while (n2) {                //verifica che ci siano solo 0 e 1
            if ((n2 % 10) > 1)  {   //il numero non è scritto con l'alfabeto binario
                b = true;           //il numero non è accettabile come input 
                cout << "Il numero inserito non è scritto in alfabeto binario (0, 1), riprovare.\n\n";
                break;              //esce dal ciclo perchè non ha senso controllare le altre cifre 
            }
            n2 /= 10;               //scala una cifra alla volta 
        }
    } while (b);
    long long tot = 0;              //contiene il numero decodificato (decimale)
    cout << endl << n << "_(2) = ";
    long long p = 1;                //potenze di 2 ora 2 alle 0
    
    while (n) {
        tot += p * (n % 10);
        p *= 2;
        n /= 10;
    }
    
    cout << tot << "_(10)";
    return 0;
}