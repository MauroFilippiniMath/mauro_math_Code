/******************************************************************************

dato un numero decimale naturale < di 4000 determina la sua codifica in 
numero romano

*******************************************************************************/
#include <iostream>
using namespace std;

void lettere(char &a, char &b, char d); //serve per individuare i caratteri da stampare

void stampa (char a, char b, char c, char t); //output

int main()
{
    unsigned n; //n = numero da codificare
    
    while (true){
        cout << "Inserire un numero naturale n (n < 4000): n = ";
        cin >> n;
        if(n < 1 || n > 3999){
            cout << "WARNING! Inserire n (0 < n < 4000), riprovare!" << endl;
            continue;
        }
        break;
    }
    cout << endl << n << " => "; 
    
    unsigned d = 1000; //indica la potenza di 10 che si sta analizzando
    char a = 'M', b = 'M', c = 'M'; //a, b, c = lettere corrispondenti alle cifre
    
    while(n){
        c = b;              //la cifra minima che poteva stampare prima, ora è una delle più grandi 
        lettere(a, b, d); //individua gli altri 2 caratteri da stampare 
        
        unsigned t = n / d;     //t = cifra più signficativa 
        n -= t*d;               //sottrae le cifre che rappresenterà 
        d /= 10;                //diminuisce la massima otenza du dieci 
        
        stampa (a, b, c, t); //fase di output
    }
    return 0;
}

void lettere(char &a, char &b, char d){
    switch (d){         //salvva in a, b, c le possibili cifre da stampare 
        case 100:       //M D C 
            a = 'D';
            b = 'C';
            break;
        case 10:        //C L X
            a = 'L';
            b = 'X';
            break;
        case 1:         //C V I
            a = 'V';
            b = 'I';
            break;
    }
}

void stampa (char a, char b, char c, char t){
    switch (t){ //stampa l'output in base ai casi
        case 4: 
            cout << b << a;
            break;
        case 9: 
            cout << b << c;
            break;
        default:                    //caso generae 
            if(t > 4){
                t -= 4;
            }
            for(int i = 0; i < t; i++) cout << b;
            break;
    }
}
















