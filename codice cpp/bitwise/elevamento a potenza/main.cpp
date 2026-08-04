/******************************************************************************

Scrivere un programma che calcoli l'elevamento a potenza di un numero data
la base e l'esponente usando soltanto i bitwise operator

*******************************************************************************/
#include <iostream>

using namespace std;

// funzione per eseguire un prodotto tra 2 numeri a, b secondo l'algoritmo del
// contadino russo
int prodotto(int a, int b) {
	unsigned p = 0;                             // p = prodotto
	while(b) {
		if(b & 1) {                         //bisogna eseguire la somma
			int t = a;
			int carry = 0;
			while(t) {                      //esegue tante volte una somma
				carry = (t & p) << 1;
				p ^= t;
				t = carry;
			}
		}
		a = (a << 1);                       // moltiplicazioni e divisioni per 2
		b = (b >> 1);                       //se non serve la somma si procede moltiplicando e dividento
	}
	return p;
}


int main()
{
	int b = 0;          // b = base dell'operazione
	int esp = 0;        // e = esponente dell'operazione
	int c = 0;          // c = controllo (1 se esponente C( dispari)

	cout << "Base = ";
	cin >> b;
	cout << "Esponente = ";
	cin >> esp;
	cout << endl << b << "^" << esp << " = ";

// dimininuisce di 1 l'esponente nel caso in cui sia dispari per poi poterlo rappresentare
// usando soltanto come potenza minima ^2
	if(esp & 1) {
		esp ^= 1;       //elimina la cifra meno significativa
		c = 1;
	}
	int r = 1;          // r = risultato della potenza
	int p = 0;          // p = parte della potenza giC  calcolata
	int e = 0;          // e = esponente successivo da rappresentare

// queste variabili servono calcolare i risultati parziali che poi vanno moltiplicati al risultato finale

	while(esp) {
		e = 2;                      // la minima potenza rappresentabile sarC  b^(2-1)
		p = b;
		while(e <= esp) {           // fino a quando non si eccede nella codifica
			p = prodotto(p, p);
			e <<= 1;
		}
		r = prodotto(p, r);         // memorizza il valore giC  calcolato
		esp -= e >> 1;              // aggiorna l'esponente eliminando ciC2 che C( giC  stato rappresentato
	}

	if(c) {                         //bisogna moltiplicare il risultato per la base sulla base del primo controllo
		r = prodotto(b, r);
	}
	cout << r;

	return 0;
}