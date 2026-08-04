/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************

    Dato un numero intero n, si definisce "prenumero" di n il numero che si
    ottiene rimuovendo dal numerale di n la cifre delle unità e "coda" di n il
    numero pari alla cifra delle unità di n.
    Ex. n = 1579; prenumero = 157; coda = 9.
    
    Scrivere un programma che, implementando in modo algoritmo il criterio di
    divisibilità enunciato, verifichi e comunichi a video se un numero n
    ricevuto in input sia divisibile per 13.
    
    LIMITAZIONI:
    Non è possibile risolvere l’esercizio utilizzando in alcun punto del codice
    l’operatore resto ( % ).
    Si ricorda inoltre che:    n > 0 => |n| = n; n < 0 => |n| = -n.
    
    Nella divisibilità per 13 puoi usare anche il criterio per cui un numero è 
    divisibile per 13 se la somma del prenumero e 4 volte la cifra delle unità 
    è 13 oppure un multiplo di 13 oppure il numero ottenuto applicando 
    l'algoritmo è uguale al precedente numero a cui si è applicato l'algoritmo 
    cioè n_i = n_(i-1).
*******************************************************************************/
#include <iostream>
using namespace std;

//calcola l'espresione la differenza in modulo tra il prenumero e la coda
int espresione(int n){ 
    
    unsigned pren = n / 10;
    unsigned coda = n - (n / 10)*10;

    n = pren + 4 * coda;
    n = (n >= 0) * n - (n < 0) * n;
    return n;
}

int main()
{   
    int n; 
    cout << "n = ";
    cin >> n; 
    cout << endl << n;
    
    unsigned prec = 0;
    
    while(n > 13){
        n = espresione(n);
        if(prec == n) break;       //è divisibile 
        prec = n; 
    }

    if(n != 13 && n) cout << " non";
    cout << " è divisibile per 13";
    return 0;
}