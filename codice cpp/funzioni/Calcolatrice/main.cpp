/******************************************************************************

Scrivere un programma che simuli una calcolatrice 

*******************************************************************************/
#include <iostream>

using namespace std;

void input (float &a, float &b, char &c);           //si occupa dell'input
float calcolatrice (float &a, float &b, char &c);   //fa il calcolo

int main()
{
    float a, b;         //numeri da usare nell'operazione 
    char c;             //c = operazione da eseguire
    float t = calcolatrice (a, b, c); //calcola il risulta e controlla l'input
    
    cout << a << " " << c << " " << b << " = " << t;

    return 0;
}

void input (float &a, float &b, char &c){
    cout << "Inserire l'operazione (+, -, *, /),";
    cout << " e dopo ogni numero e operazione premere invio:" << endl;
    cin >> a;
    cin >> c; //operazione 
    cin >> b;    
}

float calcolatrice (float &a, float &b, char &c){ //&a siccome dentro la funz. vi è l'input
    bool end; //variabile di controlo per il ciclo
    do{
        end = false;        //condizione per uscire dal ciclo
        input(a, b, c);
        switch (c){         //controlla quale operazione è stata inserita
            case '+':
                return a + b;
                break;
            
            case '-':
                return a - b;
                break;
            
            case '*':
                return a * b;
                break;
            
            case '/':
                if(b == 0){
                    end = true;     //non si può dividere per 0 
                    cout << "WARNING! NON si può dividere per 0!";
                }
                else return a / b;
                break;
            default :               //l'operazione inserita non è valida
                end = true;
                cout << "WARNING! Inserisci una TRA queste operazioni"
                << "(+, -, *, /)!" << endl;
                break;
        }       
    } while(end);
    return EXIT_FAILURE;
}