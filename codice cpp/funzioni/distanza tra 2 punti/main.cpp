/******************************************************************************

Date in input le coordinate di 2 punti su un piano cartesiano restituire il valore
della loro distanza usando una funzione

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float distanza(float x_1, float y_1, float x_2, float y_2); //distanza

int n_cifre(int a); //calcolo del numero delle cifre da stampere con il setprecision

int main()
{
	float x_1, y_1, x_2, y_2; //coordinate dei numeri

	cout << "Inserire le ascisse del primo numero. x = ";
	cin >> x_1;
	cout << "Inserire le ordinate del primo numero. y = ";
	cin >> y_1;
	cout << "Inserire le ascisse del secondo numero. x = ";
	cin >> x_2;
	cout << "Inserire le ordinate del secondo numero. y = ";
	cin >> y_2;
	cout << endl << "La distanza tra i punti A(" << x_1 << ", " << y_1;
	cout << ") e B(" << x_2 << ", " << y_2 << ") vale: ";
	
	float d = distanza(x_1, y_1, x_2, y_2);
	
	cout << setprecision(n_cifre(d) + 2) << d; //stampa il numero corretto di cifre

	return 0;
}

float distanza(float x_1, float y_1, float x_2, float y_2) { //calcolo distanza tra 2 punti 
	float d = (x_1 - x_2)*(x_1 - x_2) + (y_1 - y_2)*(y_1 - y_2);
	d = sqrt(d);
	return d;
}

int n_cifre(int a){ //calcola il numero di cifre 
    int c = 0; //numero di cifre
    
    while(a){
        a /= 10;
        c++;
    }
    
    return c;
}



