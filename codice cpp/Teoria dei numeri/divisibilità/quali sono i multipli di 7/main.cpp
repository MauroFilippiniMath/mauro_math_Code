/******************************************************************************

Un numero naturale è divisibile per 7 se la differenza in valore assoluto
    tra il numero ottenuto escludendo la cifra delle unità (prenumero) ed il
    doppio della cifra delle unità (coda numerica) è pari o a 0, o a 7 o è a sua
    volta un numero multiplo di 7.

    Scrivere un programma che, implementando in modo algoritmo il criterio di
    divisibilità enunciato, verifichi e comunichi a video se un numero n
    ricevuto in input sia divisibile per 7.
    
    LIMITAZIONI:
    Non è possibile risolvere l’esercizio utilizzando in alcun punto del codice
    l’operatore resto ( % ). Si ricorda inoltre che:
    n > 0 => |n| = n; n < 0 => |n| = -n.

*******************************************************************************/
#include <iostream>
using namespace std;
int main()
{   
    int n; //n = quanti numeri si vogliono analizzare 
    
    cout << "Inserire un numero intero: ";
    cin >> n;
    cout << n;
    while(n > 9){                                //ciclo infinito le condizioni di uscita sono negli if
        unsigned p = n / 10;
        n = p - 2 * (n - p*10);                 //calcolo della differenza 
        n = (n > 0) * n - (n <= 0) * n;         //calcolo del modulo
    }
    if(n != 7 && n) cout << " non";
    cout << " è divisibile per 7";
    return 0;
}