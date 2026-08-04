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

/*

In questo codice si sfrutta il fatto che il rombo è costituito da 2 triangoli simmetrici 
i quali presentano, alla stessa distanza dalla diagonale minore, uno stesso spazio che li 
separa dal margine.

Quindi continuando a decrementare gli spazi di 1 e calcolandone ogni volta il modulo 
si ottiene il corretto numero di spazi da stampare 

*/

int main()
{
    int d; //diagonale maggiore del rombo 
    int s; //indica il numero di spazi da stampare ogni volta 
    
    int m; //conterra il modulo si s
    
    int i, j; //variabili per i cicli forr
    
    do{
        cout << "Inserire la lunghezza della diagonale maggiore del rombo espressa come numero intero e maggiore di 2 : ";
        cin >> d; 
        
        if(d <= 2) cout << "Il numero inserito non è valido." << endl;
        
    } while(d <= 2); //fino a quando h non è un numero intero e maggiore di 2
    
    d = ((d % 2) * d) + ((!(d % 2)) * (d + 1));
    
    
    s = (d / 2); //aggiorno il numero di spazi e di punti in base all'altezza 
    
    for(i = 0; i < d; i++){
        
        cout << endl;
        
        m = ((- ((s < 0) * s)) + ((!( s < 0)) * s)); //calcolo del modulo di s
        
        for(j = 0; j < m; j++){ //ciclo che stampa gli spazi 
            cout << " ";
        }
        for(j; j < ((d / 2) + 1); j++){ //ciclo che stampa i punti 
            cout << "* ";
        }
        
        s--;
    }

    return 0;
}