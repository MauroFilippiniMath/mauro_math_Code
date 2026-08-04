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
    int n; //n = numero da analizzare 
    
    cout << "Inserire un numero intero: ";
    cin >> n;
    cout << "Il numero " << n;
    if (!n) cout << " non è divisibile per 7";
    else{
        while(true){                                //ciclo infinito le condizioni di uscita sono negli if
            n = n/10 - 2 * (n - n/10*10);           //calcolo della differenza 
            n = (n > 0) * n - (n <= 0) * n;         //calcolo del modulo
            
            if(n == 7 || !n){                       //il numero è multiplo di 7 
                cout << " è divisibile per 7";
                break;
            }
            if(n == 1 || n == 3 || n == 9){         //questi 3 numeri sono sempre presenti 
                cout << " non è divisibile per 7";  //nella sequenza di un n non divisibile
                break;
            }
        }
    }
    return 0;
}