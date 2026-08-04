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
    long long j;
    long long n_copy = n;
    
    for(i = 2; i*i <= n; i++){
        if(!(n % i)){
            n /= i;
            for(j = 2; j * j <= n; j++){
                if(!(n % j)){
                    n /= j;
                    j--;
                }
            }
            break;
        }
    }

    if(n != n_copy){
        cout <<"I divisori proprio di : " << n_copy << " sono :\n1\n";
        for(i = 2; i <= n_copy / n; i++){
            if(!(n_copy % i)){
                cout << i << endl;
            }
        }
        if (i <= n){
            for(j = 1; j < i - 1; j++){
                if(!(n_copy % j)){
                    cout << n * j << endl;
                }
            }
        }
        else{
            for(j = 3; j < n; j++){
                if(!(n_copy % j)){
                    cout << n * j << endl;
                }
            }
        }
    }
    else cout << "Il numero : " << n_copy << " è primo";

    return 0;
}