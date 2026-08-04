/******************************************************************************

scrivi un programma che dati in input 2 numeri interi x e y stampi a video mediante
il carattere "*" un trapezio rettangolo come in figura di base maggiore pari al maggiore 
tra x e y e altezza pari al minore tra x e y.
se x = y si aumenta x di una unità 
es: x = 5 e y = 8 allora il trapezio sarà

        * * * *
      * * * * *
    * * * * * *
  * * * * * * * 
* * * * * * * *

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{   
    int x, y; //base maggiore e altezza del trapezio
    int scambio; //variabile usata per scambiare i valori tra x e y
    int i, j; //variabile per i cicli 
    
    int l; //indica il numero di spazi da stampare per ogni riga 
    
    do{
        cout << "Inserire i 2 numeri interi positivi corrispondenti alla misura della base maggiore e dell'altezza del trapezio : ";
        cin >> x >> y;
        
        if((x <= 0) || (y <= 0)) cout << "I numeri inseriti non sono interi e positivi." << endl;
        
    } while((x <= 0) || (y <= 0)); //i numeri inseriti devono essere interi e positivi 
    
    if(x < y){
        scambio = x;
        x = y; 
        y = scambio;
    }
    if(x == y) x++;
    
    //ora x è il maggiore (base maggiore) mentre y il minore (altezza)
    
    l = y - 1; //numero di spazi per la prima riga 
    
    for(i = 0; i < y; i++){ //ciclo che scorre le righe 
        
        cout << endl;
        
        for(j = 0; j < l; j++){ //ciclo che indica quanti punti stampare per riga 
            cout << "  ";
        }
        for(j; j < x; j++){
            cout << "* ";
        }
        
        l--; //ogni volta i punti per ogni riga aumentano 
    }

    return 0;
}