/******************************************************************************

data l'altezza di un triangolo rettangolo rappresenta il triangolo graficamente 
sia normalmente che allo specchio utilizzando il carattere "*"

per esempio altezza = 6

* 
* *
* * * 
* * * *   
* * * * * 
* * * * * *
* * * * * * *


            * 
          * *
        * * * 
      * * * *   
    * * * * * 
  * * * * * *
* * * * * * *




*******************************************************************************/
#include <iostream>

using namespace std;  

int main()
{
    int h; //variabile che indica l'altezza del triangolo
    int i, y; //variabili per i cicli for 

    
    do{ //verifica che l'altezza inserità sia l'altezza di un triangolo
        
        cout << "Inserire l'altezza del triangolo : "; 
        cin >> h; 
        
        if(h <= 0) cout << "L'altezza inserita non corrisponde a nessun traingolo" << endl;
        
    } while(h <= 0);
    
    cout << "\n\n";
    
    for(i = 0; i < h; i++){ //con questo ciclo si scorrono le linee 
        
        for(y = 0; y <= i; y++){ //con questo ciclo si tampa il numero corretto di punti per ogni riga 
           cout << " *"; 
        }
        
    cout << endl; //ora bisogna tampare a video il triangolo specchiato 
        
    }
    
    cout << "\n\n";
    
    for(i = 0; i < h; i++){ //con questo ciclo si scorrono le linee 
        
        for(y = 0; y < (h - i - 1); y++){ //questa volta prima bisogna stampare gli spazi per poi potere stampare i punti 
           cout << "  "; 
        }
        
        for(y; y < h; y++){ //ora si stampano i punti
            cout << " *"; 
        }
        
        cout << endl;
        
    }
    
    

    return 0;
}