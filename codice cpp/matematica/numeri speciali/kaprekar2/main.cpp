/******************************************************************************

1) contare le cifre 


*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{   
    unsigned n; //n = numero da analizzare
    
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
    unsigned n_c = 4; // n_c = numero delle cifre 
    unsigned m = 0; // m = copia del numero
    unsigned dif = n;
    cout << endl << "Sequenza di Kaprekar: " << n;
    
    do{    
        n = dif;
        m = dif;
        /*
        n_c = 0;
        do{ 
            n_c++;
            m /= 10;
        } while (m); 
        */
        unsigned asc = 0; //asc = numero con cifre ordinate in ordine crescente
        unsigned desc = 0; //desc = numero con cifre ordinate in ordine decrescente
        unsigned t = dif; //t = variabile temporanea
        
        for(unsigned i = 0; i < n_c; i++){
            unsigned cmax = 0; //cmax = cifra maggiore
            unsigned c = 0; //c = cifra corrente
            unsigned ten = 1; //ten = potenza di 10 corrispondente
            unsigned del = 0; //del = prodotto tra cifra massima e la potenza della sua posizione
            
            m = t; 
            for(unsigned j = 0; j < n_c; j++){
                c = m % 10;
                m /= 10;
                if (c > cmax){
                    cmax = c;
                    del = cmax * ten;
                } 
                ten *= 10;
            }
            t -= del;
            desc = desc * 10 + cmax;
        }
        t = desc; 
        
        for(unsigned i = 0; i < n_c; i++){
            asc = asc * 10 + t % 10;
            t /= 10;
        }
        dif = desc - asc;
        cout << ", " << dif;
    } while (n != dif);
    
    cout << endl << "Il numero di Kaprekar è: " << dif;
    return 0;
}