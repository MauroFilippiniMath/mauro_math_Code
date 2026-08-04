/******************************************************************************

scrivi un programma che ricevuto input un numero intero maggiore di 2 stampi a video mediante
il carattere "*" un rombo come in figura di diagonale maggiore pari a n se n è dispari
mentre se n è pari di diagonale n + 1

es: se il numero vale 8 allora il triangolo sarà di diagonale maggiore = 9
     
    * 
   * * 
  * * * 
 * * * * 
* * * * * 
 * * * *
  * * * 
   * * 
    * 
 
*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int d; //diagonale maggiore del rombo 
    int s; //indica il numero di spazi da stampare ogni volta 
    
    int i, j; //variabili per i cicli forr
    
    do{
        cout << "Inserire la lunghezza della diagonale maggiore del rombo espressa come numero intero e maggiore di 2 : ";
        cin >> d; 
        
        if(d <= 2) cout << "Il numero inserito non è valido." << endl;
        
    } while(d <= 2); //fino a quando h non è un numero intero e maggiore di 2
    
    d = ((d % 2) * d) + ((!(d % 2)) * (d + 1));
    
    
    s = (d / 2); //aggiorno il numero di spazi e di punti in base all'altezza 
    
    for(i = 0; i < (d / 2); i++){
        
        cout << endl;
        
        for(j = 0; j < s; j++){ //ciclo che stampa gli spazi 
            cout << " ";
        }
        for(j; j < ((d / 2) + 1); j++){ //ciclo che stampa i punti 
            cout << "* ";
        }
        
        s--; //aggiorno il numero di spazi e di punti
    }
    
    for(i; i < d; i++){ //ora stampo il triangolo sotto 
        
        cout << endl;
        
        for(j = 0; j < s; j++){ //ciclo che stampa gli spazi 
            cout << " ";
        }
        for(j; j < ((d / 2) + 1); j++){ //ciclo che stampa i punti 
            cout << "* ";
        }
        
        s++; //aggiorno il numero di spazi e di punti
    }

    return 0;
}