/******************************************************************************


*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
    long long n; //numero di cui si vogliono determinare i divisori
    bool b; //variabile di controllo per il ciclo di input
    
    do {
        b = false; //se i controlli vanno a buon fine esce dal ciclo 
        cout << "Isnerire un numero naturale minore di " << LLONG_MAX - 1 << "\nNumero inserito : " ;
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
    
    long long i;
    long long y;
    long long primo = 1; //variabile usata per verificare se il numero è primo e anche per contenere il divisore
    
    for (i = 2; i * i <= n; i++){                   //con questo ciclo si scorrono tutti i possibili divisori di n
        if (!(n % i)){                              //ha trovato un divisore 
            primo = n / i;                          //aggiorna primo inserendo il quoziente diviso il divisore che quindi al primo ciclo conterrà il divisore maggiore
            b = false;                              //variabile usata per ottimizzare il ciclo, se rimane a 0 il divisore trovato è primo
            cout << primo << endl;                  //stampa il divisore trovato 
            for (y = 2; y * y <= primo; y++){       //ciclo che verifica la primalità del divisore trovato
                if(!(primo % y)){                   //non è primo il divisore trovato
                    b = true;                          //quindi si imposta che bisogna fare altri tentavi per trovarlo
                    break;                          //si interrompe siccome trovato un divisore il numero non è certamente primo
                }
            }
            if (!b) break; //se il divisore trovato è primo allora si provede alla seconda fase, se non si aggiorna il divisore
        }
    }   
    if(primo == 1){ //primo non è mai stato variato quindi il numero è primo
        cout << "il numero è primo";
    }
    else{
        primo = n / primo;                      //si imposta primo con il divisore più grande ancora da stampare
        if(primo * primo == n) primo --;        //se n è un quadrato perfettto si decremnta il divisore più grande ancora da trovare per non stampare 2 volte la radice del quadrato
        for(y = primo ; y >= 1; y--){           //con questo ciclo si decrementa il maggiore possibile divisore ancora da stampare
            if(!(n % y)) cout << y << endl;     //se il divisore provato è un divisore allora lo si stampa
        }
    }
    return 0;
}