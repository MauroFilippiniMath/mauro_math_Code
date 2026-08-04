/******************************************************************************

dato un numero stabilire se tale numero è pari o dispari.
Limitazioni: non si può usare alcun operatore algebrico 

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    unsigned n = 0; 
    
    cout << "n = ";
    cin >> n; 
    cout << n << " è ";
    (n & 1) ? cout << "dispari" : cout << "pari";

    return 0;
}