/******************************************************************************

Calcolo della potenza di una certa base (a) con un ceerto esponente (n)
calcola il risultato senza usare la funzione per generare le potenzae e
senza utilizzare la moltiplicazione ma solo le somme, proprio come 
farebbe il computer che ragiona soltanto attraverso le somme 

*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
    int a; //a = base della potenza
    int n; //n = esponente della potenza
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
        cout << "Inserire l'esponente n (n < " << INT_MAX - 1 << "): n = ";
        cin.clear ();
        cin >> n; 
        if (n == INT_MAX || n < 0){  
            cout << "\tWARNING! rispettare i limiti" << endl;
            continue;
        }
        break;
    } 
    long long tot = 1; //tot = potenza finale
    long long p = 1; //p = potenza usata per i calcoli
    
    for (int i = 0; i < n; i++){            //tanti cicli quanti l'esponente 
        for (int y = 0; y < a - 1; y++) tot += p;
        p = tot;                    //calcola la potenza ogni volta 
    }                               //che l'esponente sale di grado
    
    cout << endl << a << "^" << n << " = " << tot; 
    return 0;
}