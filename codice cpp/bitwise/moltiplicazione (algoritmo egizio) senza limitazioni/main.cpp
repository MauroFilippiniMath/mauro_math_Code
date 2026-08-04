/******************************************************************************

calcolare il prodotto tra 2 numeri interi usando l'algoritmo del 
contadino russo

Noi abbiamo trovato questo stesso algoritmo anche su un papiro egizio noto 
come papiro di Rhind che secondo la datazione risale al 1550. E questo papiro 
è anche il papiro egizio più lungo di argomento matematico 

*******************************************************************************/
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
    
    if(a < b){                      // inverto a, b in modo che a >= b
        a += b;
        b = a - b;
        a -= b;
    }
    int t = 0;                      // t = totale 
    while(b){
        if(b % 2) t += a;           // se è dispari allora salvo il valore 
        a *= 2;                     // moltiplicazioni e divisioni per 2 
        b /= 2;
    }
    cout << t;

    return 0;
}