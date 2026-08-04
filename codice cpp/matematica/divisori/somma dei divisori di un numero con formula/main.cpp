/******************************************************************************

Calcola la somma dei divisori di un numero a partire dalla loro scomposizione 
in fattori primi attraverso una specifica somma 

per calcolare la somma dei divisori di un numero bisogna:
trovato ogni fattore calcolare la somma di tutte le potenze di quel fattore fino
alla sua potenza massima e poi si moltiplicano questi valori tra di loro
es:
36 = 2^2 + 3^2 
quindi si calcola 2^0 + 2^1 + 2^2 = 7
3^0 + 3^1 + 3^2 = 13
quindi somma = 7 * 13 = 91

*******************************************************************************/
#include <iostream>
#include <climits>

using namespace std;

int main () {
	long long n; //numero di cui si vogliono determinare i divisori

	while (true){ //fase di input
        cout << "Inserire il numero di cui si vuole determinare la somma dei divisori (n < ";
        cout << INT_MAX - 1 << "): n = ";
        cin.clear ();
        cin >> n; 
        if (n == INT_MAX || n < 0){ 
            cout << "\tWARNING! rispettare i limiti" << endl;
            continue;
        }
        break;
    } 

	cout << endl << n << " = ";
	int c = 0;              //numero di volte che si ripete il fattore nella scomposizione

	long long som = 0;              //valore della somma delle potenze di un numero
	long long tot = 1;              //conterrà la somma dei divisori di un numero

	if (!(n % 2)) {                 //il numero è pari
		while (!(n % 2)) {          //il numero è divisibile per 2
			c++;                    //calcolo della molteplicità  del divisore 2
			n /= 2;
		}
		cout << "2";             
		if (c > 1) cout << "^" << c;
		if (n > 1) cout << " * ";

		som = 1;
		for(int i = 0; i < c + 1; i++) { //calcola n^((e + 1) + 1)
			som *= 2;
		}
		tot *= (som - 1) / (2 - 1); //la formula sarebbe (n^(e+1+1) -1) / (n - 1)
	}

	for (int i = 3; i*i <= n; i += 2) {     //ora i fattori primi sono certamente dispari
		c = 0;                              //azzero il contatore
		while(!(n % i)) {                   //procede fino a quando quel fattore C( contenuto
			c++;                            //aumento del contatore
			n /= i;                         //aggiorno n dividendolo per il fattore primo giC  memorizzato
		}
		if (c) {                            //è stato trovato un fattore
			cout << i;                    
			if (c > 1) cout << "^" << c;    //il fattore ha una molteplicità  maggiore di 1

			som = 1;                        //quindi ora si va ad applicare la somma delle prime potenze di numero
			for(int y = 0; y < c + 1; y++) {    //calcola n^((e + 1) + 1)
				som *= i;
			}
			som = (som - 1) / (i - 1);          //la formula sarebbe (n^(e+1+1) -1) / (n - 1)
			tot *= som;
			if (n > 1) cout << " * ";           //ci sarò almeno un altro fattore da stampare
		}
	}
	if(n > 1) {
		cout << n;        //quando arriva qui o n = 1 (già  fattorizzato) oppure n > 1 (n è l'ultimo fattore primo)
		tot *= (n + 1);
	}
	cout << endl << "La somma dei divisori è di " << tot;

	return 0;
}