#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>   // Needed for time()
using namespace std;

#define prec 100000

//calcola in modo casuale quante volte ha preso la scossa dato il numero di scrigni
int quante (int n){
    int c = 0;      //c = contatore del numero di volte in cui ha preso la scossa
    int fail = n;   //fail = numero di scrigni che si possono aprire prima di aprire quello corretto

    while(n){           //indica quanti scrigni restano da ordinare
        if(rand() % fail < fail - 1){ //ha preso la scossa
            c++;        //si aumenta il numero di scosse prese
            fail--;     //si diminuisce di 1 gli scrigni che si possono aprire
        }
        else{           //non ha preso la scossa
            n--;        //il numero di scrigni da ordinare è diminuito
            fail = n;   //si resetta il numero di scrigni che si possono apire in totale
        }
    }
    return c;
}

//calcola secondo la legge dei grandi numeri quante volte si prende la scossa in media dato il numero di scrigni
double scosse(int N) {
    srand(time(0));             //imposta il tempo per la funzione random
    double somma = 0;           //somma = somma di tutte le volte che si prende la scossa andrà diviso per il numero di tentativi
    for(int i = 0; i < prec; i++) somma += quante(N); //calcola il quante volte si prende la scossa
    return ((((N-1)*N)/4)+(somma / prec))/2;      //restituisce la media
}


int main() {
    ifstream fr("input.txt");
    ofstream fw("output.txt");
    int N;

    assert(fr >> N);
    fw << fixed << scosse(N) << "\n";

    return 0;
}




