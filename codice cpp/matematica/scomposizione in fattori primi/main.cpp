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
    
    for (i = 2; true; i++){                         //con questo ciclo si scorrono tutti i possibili divisori di n
        if (!(n % i)){                              //ha trovato un divisore 
            primo = n / i;                          //aggiorna primo inserendo il numero diviso il divisore che quindi al primo ciclo conterrà il divisore maggiore
            b = 0;                                  //variabile usata per ottimizzare il ciclo, se rimane a 0 il divisore trovato è primo

            for (y = 2; y * y <= primo; y++){       //ciclo che verifica la primarietà del divisore trovato
                        if(!(primo % y)){           //non è primo il divisore trovato
                    b = 1;                          //quindi si imposta che bisogna fare altri tentavi per trovarlo
                    break;                          //si interrompe siccome trovato un divisore il numero non è certamente primo
                }
            }
            if (b == 0) break; //se il divisore trovato è primo allora si provede alla seconda fase, se non si aggiorna il divisore
        }
    }   
    if(primo == 1){ //primo non è mai stato variato quindi il numero è primo
        cout << "il numero è primo";
    }
    else{
        
        n /= primo; //ora bisogna bisogna scomporre n e poi aggiunegere per primo
        int c; //contatore, esponente di ogni divisore
        
        for(y = 2 ; n != 1; y = y + 2){               //con questo ciclo si decrementa il maggiore possibile divisore ancora da stampare
            c = 0;                              //serve per contare quante volte è stato trovato lo stesso divisore primo
            while(!(n % y)){                    //ha trovato un divisore e vi rimane fino a quando può dividere quel numero per quel divisore
                c++;                            //incrementa il contatore
                n /= y;                         //aggiorna n per potere ricontrollare se è ancora divisibile per quello stesso divisore
            }
            if(c){                              //ha trova un divisore
                if(y == primo) c++;             //il divisore coincide con il numero primo che dovrebbe stampare alla fine (lo si usa per 16)
                cout << y;
                if(c != 1){                     //tale divisore ha esponente maggiore di 1
                    cout << "^" << c; 
                }
            if (y != primo) cout << " * ";      //ci sono ancora alri divisori da stampare infatti primo sarà l'ultimo divisore
            }
        }
        if (y - 1 != primo) cout << primo;      //l'ultimo divisore stampato coincideva con primo 
    }
    return 0;
}