/******************************************************************************

    Dato un numero intero n, si definisce "prenumero" di n il numero che si
    ottiene rimuovendo dal numerale di n la cifre delle unità e "coda" di n il
    numero pari alla cifra delle unità di n.
    Ex. n = 1579; prenumero = 157; coda = 9.
    
    Un numero naturale n_(0) è divisibile per 13 se il numero n_(1) ottenuto 
    come differenza in valore assoluto tra il prenumero di n_(0) e 9 volte la 
    coda di n_(0) è pari a 13 o è a sua volta un numero divisibile per 13.
    Detto n_(i) l'i-esimo numero della succesione di numeri generati dal
    procedimento iterativo per la verifica della divisibilità di n_(0) per 13,
    se n_(i) = n_(i-3) (i > 2) n_(0) non è divisibile per 13.

    Scrivere un programma che, implementando in modo algoritmo il criterio di
    divisibilità enunciato, verifichi e comunichi a video se un numero n
    ricevuto in input sia divisibile per 13.
    
    LIMITAZIONI:
    Non è possibile risolvere l’esercizio utilizzando in alcun punto del codice
    l’operatore resto ( % ).
    Si ricorda inoltre che:    n > 0 => |n| = n; n < 0 => |n| = -n.
    
    
    
    
    
    
    
    Ho visto che con 39 non funzione.
    lo stesso vale per 65 e 78 perchè si riconduce a 39 e crea una sequenza di 
    pochi numeri che si ripetono 
    
    
    
    
    
    
    
*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{   
    int n; 
    cout << "n = ";
    cin >> n; 
    cout << endl << n;
    
    unsigned a = 0;         //memoria per gli ultimi 4 valori trovati 
    unsigned b = 0;
    unsigned c = 0;
    
    while(n > 13 && n != a){
        n = n / 10 - 9*(n - n / 10 * 10);
        if(n < 0) n *= -1; 
        a = b;                  // n_(i-3)
        b = c;
        c = n;
    }

    if(n != 13 || n ) cout << " non";
    cout << " è divisibile per 13";
    return 0;
}