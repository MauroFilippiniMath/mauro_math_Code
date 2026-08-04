/******************************************************************************
Ricevuti in input 2 interi a e b diversi da 0 il programma, implementando
l'algoritmo di Blankinship calcola l'MCD(a, b) e i coefficienti h e k
dell'identità di Bezout: MCD(n, m) = h*n + k*m.
    
    Matrice di Blankinship
    m h k 
    n j w 
*******************************************************************************/
#include <iostream>
using namespace std;

void swap(int &a, int &b){
    a += b;
    b = a - b;
    a -= b;
}

int main(){

    unsigned a, b;          // numeri di input da elaborare
    do{
        cout << "a = ";
        cin >> a;
    } while (!a);
    do{
        cout << "b = ";
        cin >> b;
    } while (!b);
    
           
    int h = 1;    
    int k = 0;
    int j = 0;
    int w = 1;
    int n = a;  
    int m = b;
    
    if(n > m) swap(n, m); 
    do{
        unsigned q = m / n; 
        m %= n;             
        h -= j * q;
        k -= w * q;
        swap(n, m);
        swap(h, j);
        swap(k, w);
    } while (n != 0);            

    cout << endl << "MCD(" << a << ", " << b << ") = " << m << endl;
    cout << "h = " << h << endl;
    cout << "k = " << k << endl;
    cout << "(" << h << ")*" << a << " + (" << k << ")*" << b << " = " << m;
    return 0;
}