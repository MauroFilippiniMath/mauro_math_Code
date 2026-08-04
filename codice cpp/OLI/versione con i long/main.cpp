// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long MCD (long long a, long long b);                   //calcola il MCD
long long mcm (long long a, long long b, long long c);      //calcola il mcm in funzione del MCD

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
     ifstream cin("input.txt");
     ofstream cout("output.txt");
    
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        long long prec = 1;

        vector<int> V(N);
        for (int i = 0; i < N; ++i) cin >> V[i]; //input
        for (int i = 0; i < N; ++i) prec = mcm (prec, V[i]);

        cout << "Case #" << test << ": ";
        cout << prec << endl;
    }

    return 0;
}

//cosa riceve in input e cosa calcola o restituisce GCD
long long MCD (long long a, long long b){
    long long p;
    do{
        p = a % b;
        a = b;
        b = p;
    } while(p); //se p = 0 allora a è il MCD
    return a;
}

//cosa riceve in input e cosa calcola o restituisce 
long long mcm (long long a, long long b){
    return (a * b) / MCD(a, b);
}













