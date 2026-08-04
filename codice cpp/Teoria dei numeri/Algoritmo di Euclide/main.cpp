/******************************************************************************

Calcola il M.C.D. di 2 numeri interi applicando il teorema di Euclide 
utilizzando tra i 4 operatori matematici classici (+ - * /) solo la differenza

*******************************************************************************/
#include <iostream>
using namespace std;

int main(){
    int a, b;       //a,b numeri di cui si vuole calcolare il M.C.D.
    
    do{
        cout << "Inserire i 2 numeri interi diversi da 0 di cui si vuole calcolare il M.C.D." << endl;
        cin >> a;
        cin >> b;
    } while (!a || !b);     //controlla che i numeri siano diversi da 0
    cout << "MCD(" << a << ", " << b << ") = ";
    
    while (a != b){         //calcolo del M.C.D.
        if(a < b){          //ordina a e b : a > b
            a = a + b;
            b = a - b;
            a = a - b;
        }
        a = a - b;          //calcola la differenza 
    }
    cout << a;              //stama il M.C.D.

    return 0;
}