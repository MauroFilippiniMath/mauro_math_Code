#include "rational.h"
#include <stdio.h>
#include <math.h>

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a % b);
}

void rational_simplify (Rational* a){
    int d = gcd(a->n, a->d);
    if(d < 0) d *= -1;
    a->n /= d;
    a->d /= d;
}

Rational rational_create(int n, int d){
    if(d == 0) d = 1;
    if(d < 0){
        n *= -1;
        d *= -1;
    }
    Rational r = {n, d};
    rational_simplify(&r);
    return r;
}

/* Operazioni algebriche */
Rational sum_two_rational(Rational a, Rational b){
    int mcd = gcd(a.d, b.d); 
    a.d /= mcd;
    b.d /= mcd;
    return rational_create(a.n*b.d + b.n*a.d, a.d*b.d*mcd);
}

Rational dif_two_rational(Rational a, Rational b){
    Rational opposite = mul_two_rational(b, (Rational){-1, 1});
    return sum_two_rational(a, opposite);
}

Rational mul_two_rational(Rational a, Rational b){
    int mcd = gcd(a.n, b.d);
    a.n /= mcd;
    b.d /= mcd;
    mcd = gcd(b.n, a.d);
    b.n /= mcd;
    a.d /= mcd;
    return rational_create(a.n*b.n, a.d*b.d);
}

Rational div_two_rational(Rational a, Rational b){
    return mul_two_rational(a, (Rational){b.d, b.n});
}

Rational pow_rational(Rational a, int e){
    return (e < 0) ? rational_create(pow(a.d, -e), pow(a.n, -e)) : rational_create(pow(a.n, e), pow(a.d, e));
}

/* Confronto */
int rational_equal_to(Rational a, Rational b){
    return (a.n == b.n) && (a.d == b.d);
}

/* Utility */
void rational_print(Rational a){
    printf("%d / %d", a.n, a.d);
}
