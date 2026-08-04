/******************************************************************************

Scrivere il programma che data un'equazione diofantea determini:
    -se esistono soluzioni oppure no
    -nel caso in cui esistano ne determini le generiche coordinate
succesivamente nel caso in cui esistano deve applicare delle limitazioni 
date dall'utente:
    -date delle limitazioni nella forma n < x < m calcoli i punti che 
    appartengano alla retta e soddisfino le condizioni 
    -in modo analogo fare lo stesso ma con limitazione del tipo n_2 < y m_2 

*******************************************************************************/
#include <iostream>
using namespace std;

//funzione per invertire il valore di 2 variabili 
void swap(int &a, int &b){
    a += b;
    b = a - b;
    a -= b;
}

//funzione che risolve la generica ah + bk = d, secondo l'algoritmo di blankinship
void blankinship(int a, int b, int &d, int &h, int &k){ 
    // a h k
    // b j w
    h = 1;
    k = 0;
    int j = 0;
    int w = 1;
    
    do{
        int q = a / b;
        a %= b;
        h -= j*q;
        k -= w*q;
        swap(a, b);
        swap(h, j);
        swap(k, w);
    } while(b);
    d = a;          //ritorno del MCD
}

int main()
{   
    int a;              // ax + by = c 
    int b;
    int c;
    int d = 0;          // d = MCD(a, b)
    int h = 0;          // ah + bk = d
    int k = 0;
    
    cout << "Inserire i valori di a, b, c dell'equazione diofantea: ax + by = c";
    cout << endl << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << endl << "L'equazione diofantea: (" << a << ")* x + (" << b;
    cout << ")* y = " << c;
    
    blankinship(a, b, d, h, k);     // risoluzione di ah + bk = d

    if(c % d) cout << " non ammette soluzioni";
    else{
        cout << " ammette soluzioni";
        cout << endl << "Le soluzioni sono: " << endl;
        
        a /= d;
        b /= d;
        c /= d;
        
        int h_0 = c*h; 
        int k_0 = c*k;
        
        cout << "x = " << h_0 << " + (" << b << ")* t" << endl;
        cout << "y = " << k_0 << " - (" << a << ")* t";
        
        int x_min = 0;        // valori massimi e minimi di input 
        int x_max = 0;        // utilizzati per verificare se i punti sono accettabili
        int y_min = 0;
        int y_max = 0;
        
        cout << endl << "Inserire limitazioni sulle ascisse: (min <= x <= max)" << endl;
        cout << "x_min = ";
        cin >> x_min;
        cout << "x_max = ";
        cin >> x_max;
        cout << endl << "Inserire limitazioni sulle ordinate: (min <= y <= max)" << endl;
        cout << "y_min = ";
        cin >> y_min;
        cout << "y_max = ";
        cin >> y_max;
        cout << x_min << " <= x <= " << x_max << endl;
        cout << y_min << " <= y <= " << y_max << endl;
        
        int min_t = (x_min - h_0)/b; // calcolo delle coordinate massime
        int max_t = (x_max - h_0)/b; // o delle coordinate minime
    
        if(h_0 + b*min_t < x_min) min_t++;
        if(h_0 + b*max_t > x_max) max_t--;
        
        for(int t = min_t; t < max_t+1; t++){       // scorre tutti gli ipotetici valori
            int y = k_0 - a*t;
            if(y > y_min-1 && y < y_max+1){
                int x = h_0 + b*t;
                cout << "t = " << t << "\t(" << x << ", " << y << ")" << endl;
            }
        }
    }

    return 0;
}