
#include "rational.h"
#include <stdio.h>

int main(){

    /* gcd */
    int a = 4;
    int b = 6;
    printf("gcd(%d, %d) = %d", a, b, gcd(a, b));
    printf("\n");

    /* create */
    int n = -4;
    int d = -8;
    Rational c = rational_create(a, b);
    Rational e = rational_create(n, d);
    
    /* print */
    rational_print(c);

    /* equal to */
    if(rational_equal_to(c, e)){
        printf("\n");
        rational_print(c);
        printf(" = ");
        rational_print(e);
    }
    else{
        printf("\n");
        rational_print(c);
        printf(" != ");
        rational_print(e);        
    }

    /* sum */
    Rational sum = sum_two_rational(c, e);
    printf("\n");
    rational_print(c);
    printf(" + ");
    rational_print(e);
    printf(" = ");
    rational_print(sum);

    /* dif */
    Rational dif = dif_two_rational(c, e);
    printf("\n");
    rational_print(c);
    printf(" - ");
    rational_print(e);
    printf(" = ");
    rational_print(dif);

    /* mul */
    Rational mul = mul_two_rational(c, e);
    printf("\n");
    rational_print(c);
    printf(" * ");
    rational_print(e);
    printf(" = ");
    rational_print(mul);

    /* div */
    Rational div = div_two_rational(c, e);
    printf("\n");
    rational_print(c);
    printf(" / ");
    rational_print(e);
    printf(" = ");
    rational_print(div);

    /* pow */
    int esp = 2;
    Rational p = pow_rational(c, esp);
    printf("\n(");
    rational_print(c);
    printf(") ^ %d = ", esp);
    rational_print(p);

    return 0;
}
