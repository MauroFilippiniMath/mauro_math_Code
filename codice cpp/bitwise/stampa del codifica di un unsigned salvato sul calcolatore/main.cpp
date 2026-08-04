/******************************************************************************

usando i bitwise stampare la codifica del numero memorizzata nel calcolatore 

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    unsigned n; 
    cout << "n = ";
    cin >> n; 
    cout << n << "_(10) = ";
    
    int l = sizeof(unsigned) * 8;
    
    unsigned m = (1 << l - 1); // m = maschera 
    
    for(int i = 0; i < l; i++){
        n & m ? cout << 1 : cout << 0;
        m >>= 1;                                       //divide per 2
    }
    
    cout << "_(2)";
    return 0;
}