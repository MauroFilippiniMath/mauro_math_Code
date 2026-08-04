/******************************************************************************

Calcola ilrapporto tra 2 numeri interi  
utilizzando tra i 4 operatori matematici classici (+ - * /) solo la somma

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int a, b;               //a,b numeri di cui si vuole calcolare il M.C.D.
    int q = 0;              //variabile contenente la somma tra i 2 numeri 
    int r = 0;              //r = resto del rapporto
    int c;                  //c = variabile usata da contatore
    do{
        cout << "Inserire i 2 numeri interi di cui il secondo diverso 0 dei quali si vuole calolare il rapporto" << endl;
        cin >> a;
        cin >> b;
    } while (!b);                           //controllo numeri diversi da 0
    cout << a << " : " << b << " = ";
    
    for(c = 0; c + b <= a; c += b) q++;     //calcolo del rapporto
    for(c; c < a; c++) r++;                 //calcolo del resto 
    cout << q << endl;                      //output
    if (r) cout << "Inoltre è presente un resto pari a: " << r;
    else cout << "I 2 numeri sono divisibili quindi non è presente il resto";
    
    return 0;
}