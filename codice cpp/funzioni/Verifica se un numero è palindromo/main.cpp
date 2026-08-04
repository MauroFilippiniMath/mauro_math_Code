/*
    Verifica se un numero è palindromo
*/

#include <iostream>
#include <climits>

using namespace std;

int inverso (int a);    //calcola il numero con le cifre invertite

int main()
{
    int n;          //n = numero 
    bool c;         //c = variabile di controllo per l'input 
    
    do {
        c = false;              //può uscire dal ciclo
        cout << "Inserire un numero naturale n (0 < n < " << INT_MAX << "). n = ";
        cin >> n; 
        cin.clear();
        
        if(n < 1 || n == INT_MAX){
            cout << "WARNING! Il valore inserito non è accettabile" << endl;
            c = true;           //non può uscire dal ciclo
        }
    } while (c);
    
    if(n == inverso(n)) cout << "Il numero  " << n << " è palindromo";
    else cout << "Il numero " << n << " non è palindromo";
    
    return 0;
}

int inverso (int a){
    int t = 0; //t = numero con le cifre invertite
    while(a){
        t *= 10; //fa salire di una posizione tutte le cifre 
        t += a % 10; //aggiunge la nuova cifra nella posizione meno significativa
        a /= 10;
    }
    return t;
}
