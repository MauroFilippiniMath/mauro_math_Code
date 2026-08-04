/******************************************************************************

    Un numero naturale n è divisibile per 8 se, indicati con h la cifra delle
    centinaia, d la cifra delle decine e u la cifra delle unità di n, il numero 
    2*(2*h + d) + u è uguale a 0 o ad 8 o è a sua volta divisibile per 8.
    Scrivere un programma che, implementando in modo algoritmo il criterio di
    divisibilità enunciato, verifichi e comunichi a video se un numero n
    ricevuto in input sia divisibile per 4.

    LIMITAZIONI:
    Non è possibile risolvere l’esercizio utilizzando in alcun punto del codice
    l’operatore resto ( % ).

*******************************************************************************/
#include <iostream>
using namespace std;

//calcola l'espresione 2*[(2*h + d) + u]
int espresione(int n){ 
    unsigned s = 0;
    for(int i = 1; i < 5; i *= 2){ //4*h + 2*d +u
        s += i * (n - (n / 10)*10);
        n /= 10;
    }
    return s;
    
    /*
    unsigned u = n - (n / 10)*10; //n %= 10
    n /= 10;
    unsigned d = n - (n / 10)*10;
    n /= 10;
    unsigned h = n - (n / 10)*10;
    
    return 2*(2*h + d) + u;
    */
}

int main()
{
    int n; 
    cout << "n = ";
    cin >> n; 
    cout << endl << n;
    
    while(n > 9) n = espresione(n);

    if(n != 8 && n) cout << " non";
    cout << " è divisibile per 8";

    return 0;
}