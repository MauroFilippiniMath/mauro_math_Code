/******************************************************************************

*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
    int n; //indica quanti numeri felici si vogliono individuare
    bool b; //variabile di controllo per il ciclo di input
    
    do {
        b = false; //se i controlli vanno a buon fine esce dal ciclo 
        cout << "Isnerire un numero naturale minore di " << INT_MAX - 1 << "\nNumero inserito : " ;
        cin.clear ();
        cin >> n; 
        
        if (n == LLONG_MAX) { //il numero è troppo grande 
            cout << "Il numero inserito è troppo grande! riprovare" << endl;
            b = true; //così rimane nel ciclo 
            continue;//in questo modo riparte dall'inizio della fase di inpu
            }
        if (n < 0) {
            cout << "Il numero inserito è troppo piccolo quindi minore di 0! riprovare" << endl;
            b = true; //così rimane nel ciclo 
            }
    } while (b); 
    
    if (n == 1) {
        cout << "Il primo numero felice è: 1";
        return EXIT_SUCCESS;
    }
    cout << "I primi " << n << " numeri felici sono : 1";
    
    int f = 2;          //variabile usata per individuare se un numero è felice o no
    int c = 1;      //indica quanti numeri felici sono stati trovati
    
    while(c < n){   //ciclo che fa scorrere uno a uno tutti i numeri 
        unsigned t = f; 
        while (t != 1 && t != 4) {
            unsigned a = t;
            t = 0;
            while (a) {                         //procede fino a quando non ha sommato tutti i quadrati di ogni cifra
                unsigned u = a % 10;            //calcolo della cifra
                t += u * u;                     //quadrato della cifra 
                a /= 10;                        //aggiorna la cifra
            }
        }
        if (t == 1){
            cout << ", " << f;
            c++;                                            //incremento il contatore   
        }
        f++;                                    //incremento del possibile numero felice
   }
    
    return 0;
}
    