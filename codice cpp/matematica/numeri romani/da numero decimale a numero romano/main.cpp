/******************************************************************************

dato un numero decimale naturale < di 4000 determina la sua codifica 
nel sistema posizionale romano

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    unsigned n; //n = numero da codificare
    
    while (true){
        cout << "Inserire un numero naturale n (n < 4000): n = ";
        cin >> n;
        if(n < 1 || n > 3999){
            cout << "WARNING! Inserire n (0 < n < 4000), riprovare!" << endl;
            continue;
        }
        break;
    }
    cout << endl << n << " => "; 
    
    unsigned m = n; //m = copia di n
    unsigned ten = 1; //ten = posizone massima decimale parte da 10^0 quindi poi andrà diviso per 10
    unsigned c; //c = cifra che si sta codificando
    
    while (m){ //calcolo della potenza di 10 massima
        ten *= 10;
        m /= 10;
    }
    ten /= 10; //ten contiene un valore che ha una posizione in più, siccome parte da 10^0
    m = n;

    while (m){      //switch case per capire quali caratteri utilizzare es: M o I
        c = m / ten; //estra l'ultima cifra, quella più significativa
        m -= c * ten; //sottrae l'ultima cifra perchè già usata
        switch (ten) {
            case 1000:      //migliaia (M)
                for(unsigned i = 0; i < c; i++) cout << "M";
                break;
            case 100:       //centinaia (CM, D, C)
                switch (c){
                    case 4: 
                        cout << "CD"; 
                        break;
                    case 9:
                        cout << "CM"; 
                        break;
                    default: //non è in uno dei 2 casi particolari
                        if(c > 4){
                            c -= 5;
                            cout << "D"; //la codifica di 600 e 100 è diversa solo per un D davanti
                        }
                        for(unsigned i = 0; i < c; i++) cout << "C";
                        break;
                }
                break;
            case 10:        //decine (C, L, X)
                switch (c){
                    case 4:
                        cout << "XL"; 
                        break;
                    case 9:
                        cout << "XC"; 
                        break;
                    default:
                        if(c > 4){
                            c -= 5;
                            cout << "L";
                        }
                        for(unsigned i = 0; i < c; i++) cout << "X";
                        break;
                }
                break;
            case 1:         //unità (X, V, I)
                switch (c){
                    case 4:
                        cout << "IV"; 
                        break;
                    case 9:
                        cout << "IX"; 
                        break;
                    default:
                        if(c > 4){
                            c -= 5;
                            cout << "V";
                        }
                        for(unsigned i = 0; i < c; i++) cout << "I";
                        break;
                }
                break;
        }
        ten /= 10; //le cifre da codificare sono diminuite di uno
    }
    return 0;
}