#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int d;
static int L;
static int* messaggio;
static char* plaintext;

// Declaring functions
void decifra(int N, int d, int L, int* messaggio, char* plaintext);

int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
        fscanf(fr, "%d %d %d", &N, &d, &L);
	messaggio = (int*)malloc(100 * sizeof(int));
	plaintext = (char*)malloc(110 * sizeof(char));
	for (i0 = 0; i0 < L; i0++)
            fscanf(fr, "%d", &messaggio[i0]);

	// Calling functions
	decifra(N, d, L, messaggio, plaintext);

	// Writing output
        fprintf(fw, "%s\n", plaintext);
	
	fclose(fr);
	fclose(fw);
	return 0;
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    for(int i = 0; i < L; i++){
        long long d2 = d;
        long long modulo = messaggio[i] % N;
        modulo = (modulo * modulo) % N; //assegna il valore che è c^2 mod N
        long long parz = messaggio[i] % N; //parz = valore parziale alla fine contiene quello corretto
        long long pot = 2; //usato per capire quando si è superato il valore da codificare

        while(pot <= d2){ //comincia cercando di analizzare i quadrati, per diminuire velocemente i casi
            parz = (parz * parz) % N; //inizialmente vi codifica ^2 poi ^4 e poi ^8...
            pot *= 2; //calcola il successivo valore da codificare
        }
        d2 -= (pot / 2); //sottrae il valore già codificato

        while(d2 >= 2){ //qunado mance solo c^1 o c^0 esce dal ciclo
          pot = 2; //si azzera codificato per ricominciare con il contatore
          long long p = 4; //serve sempre gestire quanto codificato perchè non si usano più le potenze ma ^2 ^6 ^14
          long long parz2 = modulo; //tutte le volte codifica i multilpi di 2 lascindo il caso dispari alla fine
          while(pot <= d2){
              parz = (parz * parz2) % N; //calcolo del valore codificato
              parz2 = (parz2 * parz2) % N; //preparazione del successivo valore da codificare
              pot += p; //aggiorna le variabili necessarie per i controlli 
              p *= 2;
          }
          d2 -= (pot - (p / 2)); //sottrae il valore già codificato
        }
        if(d2) parz = (parz * (messaggio[i] % N)) % N; //nel caso in cui manchi c^1
        plaintext[i] = parz;
      }
      plaintext[L] = '\0';
}


