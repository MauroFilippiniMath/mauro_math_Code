/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

long long iter_pow(int b, unsigned e){
    if(e == 0) return 1;
    long long p = iter_pow(b, e/2);
    if(e % 2) return p*p*b;
    return p*p;
}

int main()
{
    int b = -3;
    unsigned e = 5;
    
    cout << iter_pow(b, e);
    return 0;
}