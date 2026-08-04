/******************************************************************************

dato un numero naturale di 4 cifre determina attraverso di esso la costante 
di Kaprekar.
Sapendo che essa si ottiene quando si ha la ripetizione dello stesso numero in 
una particolare sequenza:
La sequenza è data dalla differenza tra il numero maggiore e minore che si può
ottenere cambiando l'ordine delle cifre che costituiscono il precedente numero
della sequenza

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{   
    unsigned n;              //n = numero da analizzare
    
    while (true) {
        cout << "Inserire un numero naturale di 4 cifre: n = ";
        cin >> n;
        if (n < 1001 || n > 9998){
            cout << "WARNING, inserire n (1000 < n < 9999)!" << endl;
            continue;
        }  
        unsigned m = n; //m = copia di n
        unsigned c = m % 10; //c = cifra corrente
        do {
            m /= 10;
        } while (c == m % 10);
        if (m) break;
        cout << "WARNING, inserire un numero con almeno una cifra diversa dalle altre!" << endl;
    }
    cout << endl << "La sequenza di Kaprekar è: " << n; 
    
    unsigned a, b, c, d;     //a, b, c, d = le 4 cifre che costituiscono il numero 
    int t;              //t = variabile temporale usata per invertire i valori di 2 variabili 
    int k = n;          //k = numero corrente della sequenza, il primo è n
    int r;              //r = numero precedente nella sequenza
    
    while (k != r) {    //fino a quando il numero precedente e quello corrente sono diversi
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
        r = k;                                          //si aggiorna il precedente numero
        k = 999*(a - d) + 90*(b - c);        //si aggiorna il numero corrente 
        n = k; 
        /*
            sarebbe il numero maggiore che si può avere cioè:
                1000*a + 100*b + 10*c +d
            a cui si sottrae il numero più piccolo che si può ottenere:
                a + 10*b + 100*c +1000*d 
            Quindi la differenza dà il valore assegnato a k
        */
        cout << ", " << k;
    }  
    cout << endl << "Il numero di Kaprekar è: " << k;
    
    return 0;
}