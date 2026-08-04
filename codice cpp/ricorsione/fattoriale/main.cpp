#include <iostream>

using namespace std;

// calcolo del fattoriale con ricorsione 
unsigned long factorial_rec(unsigned n) {
	if(n == 0) return 1;
	return n * factorial_rec(n - 1);
}

// calcolo del fattoriale con la tail call 
unsigned long factorial_t_rec(unsigned n, unsigned long acc = 1){
    if(n <= 1) return acc;
    return factorial_t_rec(n - 1, acc * n);
}

int main()
{
    unsigned n = 5;

    cout << "algoritmo ricorsivo: " << n << "!" << " = " << factorial_rec(n) << endl;
    cout << "algoritmo ricorsivo (tail call): " << n << "!" << " = " << factorial_t_rec(n) << endl;

	return 0;
}