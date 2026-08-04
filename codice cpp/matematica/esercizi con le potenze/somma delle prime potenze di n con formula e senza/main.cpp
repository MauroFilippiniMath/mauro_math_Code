/******************************************************************************

Calcola la somma delle prime n potenze di un certo numero la cui base è a 

risolvi il problema creando due problemi, uno in cui si calcoli il risultato
usando il metodo più semplice ovvero attraverso la somma di diverse potenze 

E inoltre lo si risolva utilizzando la formula per calcolare la somma delle 
prime potenze con una certa base 

In seguito si calcoli anche la durata di entrambi i programmi e si restituisca 
la durata in millisecondi

*******************************************************************************/
#include <iostream>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

int main () {
    int a;                  //base della potenza
    int n;                  //esponente massimo
    clock_t start, end;     //variabili usate per misurare il tempo
    long long p;            //p = potenza totale
    
    while (true){ //fase di input
        cout << "Inserire la base a (a < " << INT_MAX - 1 << "): a = ";
        cin.clear ();
        cin >> a; 
        if (a == INT_MAX || a < 0){ 
            cout << "\tWARNING! rispettare i limiti" << endl;
            continue;
        }
        break;
    } 
    while (true){
        cout << "Inserire la potenza massima n (n < " << INT_MAX - 1 << "): n = ";
        cin.clear ();
        cin >> n; 
        if (n == INT_MAX || n < 0){  
            cout << "\tWARNING! rispettare i limiti" << endl;
            continue;
        }
        break;
    } 
                                            //calcolo attraverso la somma di potenze 
    long long s = 1;                        //s = somma
    p = 1;
    start = clock();                        //start = tempo iniziale
    
    for(int i = 0; i < n ; i++){         
        p *= a;
        s += p;
    }
    cout << endl;
    cout << "1 + " << a << " + " << a << "^2 + " << a << "^3 + ... + ";
    cout << a << "^(" << n - 2 << ") + " << a << "^(" << n - 1 << ") + ";
    cout << a << "^(" << n << ") = " << s;
    
    end = clock();                          //end = tempo finale 
    cout << endl << "Il tempo impiegato è di : ";
    cout << (double(end - start) / double(CLOCKS_PER_SEC))*1000 << setprecision(6);
    cout << " millisecondi";    //il valore sarebbe espresso in secondi ma esso sarebbe troppo piccolo 
                                //per questo viene espresso in millisecondi
    
    start = clock();                        //calcolo attraverso la formula
    p = 1; 
    for(int i = 0; i < n + 1; i++){         //calcola a^(n + 1)
        p *= a;
    }
    p = (p - 1) / (a - 1);                  //(a^(n+1) -1) / (a - 1)
    cout << endl;
    cout << "1 + " << a << " + " << a << "^2 + " << a << "^3 + ... + ";
    cout << a << "^(" << n - 2 << ") + " << a << "^(" << n - 1 << ") + ";
    cout << a << "^(" << n << ") = " << p;
    
    end = clock();
    cout << endl << "Il tempo impiegato è di : ";
    cout << (double(end - start) / double(CLOCKS_PER_SEC))*1000 << setprecision(6);
    cout << " millisecondi";
    
    return 0;
}