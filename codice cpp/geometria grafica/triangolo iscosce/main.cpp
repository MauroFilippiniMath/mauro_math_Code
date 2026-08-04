/******************************************************************************

scrivi un programma che dati in input un numero intero stampi a video mediante
il carattere "*" un traingolo isoscele come in figura di base pari al numero
e altezza pari sempre allo stesso numero

es: se il numero vale 6 allora il triangolo sarà
   
     * 
    * *
   * * * 
  * * * *
 * * * * *
* * * * * *


*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int h; //altezza del triangolo e lunghezza della base
    int s; //indica il numero di spazi da stampare ogni volta 
    int l; //indica il numero di punti da stampare ogni volta 
    
    int i, j; //variabili per i cicli forr
    
    do{
        cout << "Inserire la lunghezza dell'altezza e della base espressa come numero intero e positivo : ";
        cin >> h; 
        
        if(h <= 0) cout << "Il numero inserito non è valido." << endl;
        
    } while(h <= 0); //fino a quando h non è un numero intero e positivo
    
    
    s = h - 1; //aggiorno il numero di spazi e di punti in base all'altezza 
    
    for(i = 0; i < h; i++){
        
        cout << endl;
        
        for(j = 0; j < s; j++){ //ciclo che stampa gli spazi 
            cout << " ";
        }
        for(j; j < h; j++){ //ciclo che stampa i punti 
            cout << "* ";
        }
        
        s--; //aggiorno il numero di spazi e di punti
    }

    return 0;
}