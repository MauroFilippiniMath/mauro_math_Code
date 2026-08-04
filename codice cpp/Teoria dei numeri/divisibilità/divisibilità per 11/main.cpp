/******************************************************************************

    n è divisibile per 11 se e solo se la differenza, in valore assoluto,
    fra la somma delle cifre di posto pari e la somma delle cifre di posto dispari
    è 0 o un multiplo di 11.
    
*******************************************************************************/
#include <iostream>
using namespace std;

//calcola il modulo della differenza tra la somma delle cifre in posizione pari 
//e quelle in posizione dispari 
int dif_pari_disp(int n){ 
    unsigned pari = 0;      //somma cifre posizione pari
    unsigned disp = 0;      //somma cifre posizione dispari
    
    while (n){
        disp += n % 10;
        n /= 10;
        pari += n % 10;
        n /= 10;                    //elimina l'ultima cifra 
    }
    n = pari - disp;
    n = (n >= 0) * n - (n < 0) * n; 
    return n;
}

int main()
{
    int n; 
    cout << "n = ";
    cin >> n; 
    cout << endl << n;
    
    while(n > 11) n = dif_pari_disp(n);
    
    if(n != 11 && n) cout << " non";
    cout << " è divisibile per 11";

    return 0;
}