/******************************************************************************

In questo programma si vuole calcolare la scomposizione in fatti primi nel modo 
più semplice

*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
    long long n; //numero di cui si vogliono determinare i divisori
    
    while (true){ //fase di input
        cout << "Inserire il numero di cui si vuole determinare la somma dei divisori (n < ";
        cout << INT_MAX - 1 << "): n = ";
        cin.clear ();
        cin >> n; 
        if (n == INT_MAX || n < 0){ 
            cout << "\tWARNING! rispettare i limiti" << endl;
            continue;
        }
        break;
    }  
    
    cout << endl << n << " = ";;
    int c = 0;                      //numero di volte che si ripete il fattore nella scomposizione
    
    if (!(n % 2)){                          //il numero è pari
        while (!(n % 2)) {                  //il numero è divisibile per 2 
        c++;                        //calcolo della molteplicità del divisore 2
        n /= 2;
        }
        cout << "2";             //stampo l'output
        if (c > 1) cout << "^" << c; 
        if (n > 1) cout << " * ";
    }
    
    for (int i = 3; i*i <= n; i += 2) {      //ora i fattori primi sono certamente dispari
        c = 0;                      //azzero il contatore  
        while(!(n % i)){                    //procede fino a quando quel fattore è contenuto
            c++;                    //aumento del contatore
            n /= i;                         //aggiorno n dividendolo per il fattore primo già memorizzato
        }
        if (c){                     //è stato trovato un fattore
            cout << i;                      //stampa l'output
            if (c > 1) cout << "^" << c; //il fattore ha una molteplicità maggiore di 1
            if (n > 1) cout << " * ";       //ci sarà almeno un altro fattore da stampare
        }
    }
    if(n > 1) cout << n;        //quando arriva qui o n = 1 (già fattorizzato) oppure n > 1 (n è l'ultimo fattore primo)
    
    return 0;
}