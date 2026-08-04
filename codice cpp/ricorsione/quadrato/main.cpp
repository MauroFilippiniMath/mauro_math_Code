#include <iostream>

using namespace std;

// calcolo del quadro usando l'iterazione 

// (n*n) come somma di tante volte n 
unsigned long square_sum(unsigned n){
    unsigned long q = 0;
    for(int i = 0; i < n; i++) q += n;
    
    
    return q;
}

// n^2 = [(n-1) +1]^2 = (n-1)^2 + 2*(n-1) + 1
unsigned long square_iter(unsigned n){
    unsigned long q = 0;
    for(int i = 1; i < n + 1; i++){
        // q += 2*(i-1) + 1;
        q += i + i - 1;
    }
    return q;
}

// calcolo del quadrato usando la ricorsione 

// n^2 = [(n-1) +1]^2 = (n-1)^2 + 2*(n-1) + 1
unsigned long square_rec(unsigned n){
    if(n == 0) return 0;
    return square_rec(n - 1) + n + n - 1; 
}

// stesso ragionamento di prima ma ora tail call (richiamo solo la funzione)
unsigned long square_t_rec(unsigned n, unsigned long acc = 0){
    if(n == 0) return acc;
    return square_t_rec(n - 1, acc + n + n - 1); 
}


int main(){

    unsigned n = 4;

    cout << "algoritmo iterativo come somma: " << n << "^2 = " << square_sum(n) << endl;
    cout << "algoritmo iterativo: " << n << "^2 = " << square_iter(n) << endl;
    
    cout << "algoritmo ricorsivo: " << n << "^2 = " << square_rec(n) << endl;
    cout << "algoritmo ricorsivo (tail call): " << n << "^2 = " << square_t_rec(n) << endl;

    return 0;
}