/******************************************************************************


se inserito un numero troppo grande si ha un overflow e questo porta la variabile 
a contenere tutti 1 quindi il massimo valore inseribile 

*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int n; //numero da codificare in binario
    bool b; //variabile per verificare l'input
    
    do {
        b = false; //se alla fine b = false allora la fase di input è andata a buon fine
        cout << "Inserire il numero decimale intero non negativo che si vuole codificare in binario,"
             << "sapendo che il numero massimo inseribile è : " << INT_MAX - 1 << endl 
             << "Numero inserito : ";
        /*
        se inserito un numero troppo grande si ha un overflow e questo porta la variabile 
        a contenere tutti 1 quindi il massimo valore inseribile in un intero.
        Per questo il massimo valore viene decrementato di 1 in modo da poter sfruttare
        il valore massimo per individuare se il numero inserito è troppo grande
        */
        cin >> n; //acquisizione del numero da codificare 
        cout << endl;
    
        if (n == INT_MAX) {     //il numero è troppo grande
            cout << "Il numero inserito è troppo grande riprovare.";
            b = true;           //non esce dal ciclo
            cin.clear();        //resetta cin perchè se va in overflow poi non riesce più a prendere nessun input 
        }
    
        if (n < 0) {                //il numero inserito è negativo
            cout << "Il numero inserito è negativo riprovare.";
            b = true;               //non esce dal ciclo
        }
        //non c'è il problema della virgola perchè il numero viene memorizzato in un intero
    } while (b);
    
    int max = 1;            //contiene la massima potenn 
    cout << endl << n << "_(10) = "; 
    while (max * 2 <= n) max *= 2;
    
    while (max) {
        if (n >= max){      //la potenza è minore quindi si stampa un 1
            cout << "1";
            n -= max;
        }
        else cout << "0";   //in questo modo prima deve stampare un 1 e poi comincerà a stampare gli 0
        max /= 2;           //aggiorna la potenza di 2 diminuendo di 1 tutte le volte l'esponente 
    } 
    
    cout << "_(2)";
    return 0;
}