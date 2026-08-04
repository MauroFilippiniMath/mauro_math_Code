/******************************************************************************

calcolare la somma tra 2 numeri interi usando i bitwise

per ogni cifra il nuovo valore della cifra è dato dall'operazione XOR tra 
le 2 cifre.
invece siccome il riporto lo si calcola con l'operatore AND ogni volta 
questo lo si somma nella posizione successiva 

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
    cout << endl << a;
    (b >= 0) ? cout << " + " : cout << " ";
    cout << b << " = ";
    
    int carry = 0;
    while(b){
        carry = (a & b) << 1; 
        a ^= b;
        b = carry;
    }
    cout << a;
    return 0;
}