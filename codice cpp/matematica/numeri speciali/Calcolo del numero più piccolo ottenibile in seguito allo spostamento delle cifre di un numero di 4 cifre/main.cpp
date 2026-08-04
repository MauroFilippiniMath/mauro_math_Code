/******************************************************************************

Individua il numero più piccolo che si può realizzare in seguito allo spostamento 
delle cifre di un numero di 4 cifre

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{   
    int n;              //n = numero da analizzare
    
    while (true) {
        cout << "Inserire un numero naturale di 4 cifre: n = ";
        cin >> n;
        if(n < 1000){
            cout << "Warning il numero inserito ha 3 cifre, riprovare!" << endl;
            continue;
        }  
        if(n > 9999){
            cout << "Warning il numero inserito ha 5 cifre, riprovare!" << endl;
            continue;
        }
        break;          //se arriva a questo punto il numero inserito è accettabile 
    }
    
    int a, b, c, d;     //a, b, c, d = le 4 cifre che costituiscono il numero 
    int t;              //t = variabile temporale usata per invertire i valori di 2 variabili 
    
    a = n % 10;         //calcolo di ogni cifra del numero 
    n /= 10;
    b = n % 10;
    n /= 10;
    c = n % 10;
    n /= 10;
    d = n % 10;
    n /= 10;
    /*
            Per ordinare le 4 cifre servono 5 controlli.
            inoltre ogni volta che si trova una cifra nella posizione sbaglita 
            la si inverte in modo da avere a > b > c > d.
            Infatti, se a è la cifra più granda allora per il calcolo del maggiore 
            sarà a * 1000 grazie alle proprietà del sistema posizionale
        */
        if (a < c) {        //controlli necessari per ordinare le 4 cifre
            t = a;
            a = c; 
            c = t; 
        }
        if (b < d) {        
            t = b;
            b = d; 
            d = t; 
        }
        if (a < b) {
            t = a;
            a = b; 
            b = t; 
        }
        if (c < d) {
            t = c;
            c = d; 
            d = t; 
        }
        if (b < c) {
            t = b;
            b = c; 
            c = t; 
        }

    cout << "Il numero più piccolo ottenibile dalle cifre del numero inserito è: "
    << d * 1000 + c * 100 + b * 10 + a; 
    
    return 0;
}