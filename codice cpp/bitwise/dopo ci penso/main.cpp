/*
    ****************************************************************************
    Implementare un programma che, ricevuto in input due interi positivi x ed y,
    calcoli e restituisca a video il loro prodotto sfruttando l’algoritmo egizio
    (papiro di Rhind) o algoritmo del contadino russo.
    
    LIMITAZIONI: non è possibile risolvere l'esercizio mediante l'uso di
    operatori aritmetici.
    ****************************************************************************
    
    BITWISE OPERATOR
    ----------------
    NOT (~) ~0 = 1; ~1 = 0
    OR (|)
    AND (&)
    XOR (^)
            x  y    |    &    ^
            0  0    0    0    0
            0  1    1    0    1
            1  0    1    0    1
            1  1    1    1    0
    Left-shift (<< n)  = multiplication by 2^n for positive numbers.
    Right-shift (>> n) = division by 2^n for positive numbers.
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << endl << a << " * " << b << " = ";
    
    int p = 0;                      // t = totale 
    while(b){
        if(b & 1) p += a;           // se è dispari allora salvo il valore 
        a <<= 1;                     // moltiplicazioni e divisioni per 2 
        b >>= 1;
    }
    cout << p;

    return 0;
}