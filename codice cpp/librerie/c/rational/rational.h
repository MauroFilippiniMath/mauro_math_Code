#ifndef rational _H
#define rational _H

typedef struct{
    int n;
    int d;
} Rational;

int gcd(int a, int b);                                      // calcola il MCD tra 2 numeri 
void rational_simplify(Rational* a);                        // riduce la funzione 
Rational rational_create(int n, int d);                     // crea una frazione

/* Operazioni algebriche */
Rational sum_two_rational(Rational a, Rational b);          // somma 2 frazioni
Rational dif_two_rational(Rational a, Rational b);          // differenza di 2 frazioni
Rational mul_two_rational(Rational a, Rational b);          // moltiplicazione tra 2 frazioni
Rational div_two_rational(Rational a, Rational b);          // divisione tra 2 frazioni
Rational pow_rational(Rational a, int e);                   // eleva la frazione per un certo esponente 

/* Confronto */
int rational_equal_to(Rational a, Rational b);

/* Utility */
void rational_print(Rational a);                            // stampa una frazione 

#endif
