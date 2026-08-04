/******************************************************************************

Calcola il M.C.D. di 2 numeri interi applicando il teorema di Euclide 
utilizzando tra i 4 operatori matematici classici (+ - * /) solo la somma

*******************************************************************************/
#include <iostream>
using namespace std;

int resto (int a, int b){
    int i = 0;
    while(i + b < a) i += b;
    for(b = 0; i + b < a; b += 1);
    return b;
}

int main()
{
    int a, b;   //a,b numeri di cui si vuole calcolare il M.C.D.
    int c;      //variabile contenente la parte del numero maggiore già "sottratta"
    int r = 1;      //ciò che rimane del numero meggiore ancora da "sottrarre"
    
    do{
        cout << "Inserire i 2 numeri interi diversi da 0 di cui si vuole calcolare il M.C.D." << endl;
        cin >> a;
        cin >> b;
    } while (!a || !b); //controlla che i numeri siano diversi da 0
    cout << "Il M.C.D. tra " << a << " e " << b << " corrisponde a: ";
    
    if(a < b){      //si riordiano in ordine crescente a e b
        a = a + b;
        b = a - b;
        a = a - b;
    }
    while (r){              //calcolo del M.C.D.
        r = resto(a, b);
        a = b;                          // si riascegnano i valori che dovranno essere ancora utilizzati
        b = r;
    }
    cout << a;          //stampa il M.C.D.

    return 0;
}