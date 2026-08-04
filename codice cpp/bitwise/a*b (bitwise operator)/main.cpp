/******************************************************************************

calcolare il prodotto tra 2 numeri interi usando i bitwise

*******************************************************************************/
#include <iostream>
using namespace std;

int somma(int a, int b){
    int carry = 0;
    while(b){
        carry = (a & b) << 1; 
        a ^= b;
        b = carry;
    }
    return a;  
}

int main(){
    
    unsigned a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << endl << a << " * " << b << " = ";
    
    unsigned p = 0;                       // p = prodotto 
    while(b){
        if(b & 1){                      //bisogna eseguire la somma 
            int t = a;
            int carry = 0;
            while(t){                       //esegue tante volte una somma 
                carry = (t & p) << 1; 
                p ^= t;
                t = carry;
            }            
        }
        a = (a << 1);                       // moltiplicazioni e divisioni per 2 
        b = (b >> 1);                       //se non serve la somma si procede moltiplicando e dividento
    }
    cout << p;

    return 0;
}