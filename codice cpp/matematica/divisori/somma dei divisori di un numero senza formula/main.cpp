/******************************************************************************

Scrivi un programma che calcoli la somma di tutti i divisori di un numero
senza utilizzare nessuna formula particolare

PS: questo programma è stato realizzato con la logica del divisori corrente e 
del divisore precedente

*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
    long long n;        //numero di cui si vogliono determinare i divisori
    
    while (true){       //fase di input
        cout << "Inserire il numero di cui si vuole determinare la somma dei divisori (n < ";
        cout << INT_MAX - 1 << "): a = ";
        cin.clear ();
        cin >> n; 
        if (n == INT_MAX || n < 0){ 
            cout << "\tWARNING! rispettare i limiti" << endl;
            continue;
        }
        break;
    } 
    
    long long d;            //divisore corrente 
    long long d_old = 0;    //divisore precedente 
    long long tot = 0;      //tot = totale richiesto
    
    /*
    prima di tutto si stampano i divisori partendo da 1 e poi arrivati a metà dei divisori si può tornare
    indietro sfruttando il fatto che ci vuole di meno a passare dalla metà dei divisori a 0 
    che dalla metà dei divisori fino a trovarli tutti,
    per esempio con 96 ci si mette di meno ad controllare i possibili divisori da 0 a 12 che da 12 ad 48
    infatti poi quando si arriva a 12 basta ripassare a quello primo cioè 8 e fare il procedimento opposto 
    stampando di volta in volta il numero diviso il divisore trovato
    
    per individuare la metà o il divisore e quello precedente moltiplicati danno il numero 
    oppure se è un quadrato perfetto il divisore moltiplicato per se stesso da il numero 
    */
    bool primo = true; //indica se il numero è primo o no e se è già stato trovato un divisore
    
    for(d = 2; d*d <= n; d++){ 
        if (!(n % d)) {                 //ha trovato un divisore
            if (primo) {                //se è il primo imposta che il numero non è primo
                primo = false; 
                cout << "1" << endl;    //stampa 1 in modo che se il numero è primo non stampi 1 
                tot += 1;
            }
            cout << d << endl;          //procedi stampando gli altri divisori    
            tot += d;
            if (((d * d_old) == n) || ((d * d) == n) ){ //si è arrivati alla metà dei divisori
                break;                  //d * d serve per i quadrati perfetti
            }
            d_old = d;                      //aggiorno il vecchio divisore
        }
    }
    if (primo){                         //solo se il numero è primo
        cout <<  "Il numero è primo";
    }
    else{
        if ((d_old) && (d_old * d_old != n)){ //d_old &&, lo si mette per verificare che non si abbia trovato
            cout << n / d_old << endl;          //un solo divisore come nel caso di 4 e che quindi d_old sia ancora = 0
            tot += n / d_old;
        }
        for(d_old -= 1; d_old > 1; d_old--){    //scorre il vecchio divisore al contrario partendo 
                                                //dal divisore meno uno in modo da 
            if (!(n % d_old)){                  //non stampare 2 volte lo stesso divisore 
                cout << n / d_old << endl;      //se trova un divisore stampa il numero diviso per esso
                tot += n / d_old;
            } 
        }
        cout << endl << "La somma dei divisori è : " << tot;
    }
    return 0;
}