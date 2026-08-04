/******************************************************************************

Dato un numero si calcoli la somma dei primi n numeri naturali 

*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
    long long n;            //n = numero di cui si vogliono determinare i divisori

    while (true){           //fase di input
        cout << "Inserire il numero n di cui si vogliono determiante i divisori (n < ";
        cout << LLONG_MAX - 1 << "): n = ";
        cin.clear ();
        cin >> n; 
        if (n == INT_MAX || n < 0){ 
            cout << "\tWARNING! rispettare i limiti" << endl;
            continue;
        }
        break;
    } 
    cout << endl;
    cout << "La somma dei primi " << n << " numeri è : " << (n * (n + 1)) / 2;
    
    return 0;
}