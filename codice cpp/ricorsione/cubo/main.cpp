#include <iostream>

using namespace std;

// funziona che calcola il quadrato usata per la ricorsività
unsigned long square_t_rec(unsigned n, unsigned long acc = 0){
    if(n == 0) return acc;
    return square_t_rec(n - 1, acc + n + n - 1); 
}

// calcolo del cubo usando l'iterazione

// n*n*n visto come tante somme 
unsigned long cube_sum(unsigned n){
    unsigned long c = 0;
    for(unsigned i = 0; i < n; i++){
        for(unsigned j = 0; j < n; j++){
            c += n;
        }
    }
    return c;
}

//n^3 = [(n-1)+1]^3 = (n-1)^3 + 3*(n-1)^2 + 3*(n-1) + 1 
unsigned long cube_iter(unsigned n){
    unsigned long c = 0;
    for(unsigned i = 1; i < n + 1; i++){
        c += 3*square_t_rec(i-1) + 3*(i-1) + 1;
    }
    return c;
}

// calcolo del cubo usando la ricorsività

//n^3 = [(n-1)+1]^3 = (n-1)^3 + 3*(n-1)^2 + 3*(n-1) + 1 
unsigned long cube_rec(unsigned n){
    if(n == 0) return 0;
    unsigned long q = cube_rec(n - 1) + 3* square_t_rec(n) - 3*n + 1;
    return q;
}

// stesso ragionamento di prima ma ora tail call (richiamo solo la funzione)
unsigned long cube_t_rec(unsigned n, unsigned long acc = 0){
    if(n == 0) return acc;
    return cube_t_rec(n - 1, acc + 3* square_t_rec(n) - 3*n + 1);
}

int main(){

    unsigned n = 2;

    cout << "algoritmo iterativo come somma: " << n << "^3 = " << cube_sum(n) << endl;
    cout << "algoritmo iterativo: " << n << "^3 = " << cube_iter(n) << endl;
    
    cout << "algoritmo ricorsivo: " << n << "^3 = " << cube_rec(n) << endl;
    cout << "algoritmo ricorsivo (tail call): " << n << "^3 = " << cube_t_rec(n) << endl;

    return 0;
}