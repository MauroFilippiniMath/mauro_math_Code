/******************************************************************************

il programma calcola il rapporto tra 2 numeri interi a e b 

Limitazione: il programma può fare uso unicamente dell'operatore
aritmetico di differenza

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int a, b;           //a,b numeri di cui si vuole calcolare il M.C.D.
    do{
        cout << "a = ";
        cin >> a;
    } while (a < 0); 
    do{
        cout << "b = ";
        cin >> b;
    } while (b <= 0);
    
    cout << a << " = " << b << "*";
    
    int q = 0;          // q = quoziente
    while(a >= b){
        a -= b;
        q--;
    }
    q = 0 - q;
    
    cout << q;
    a ? cout << " + " << a : cout << "";
    
    return 0;
}