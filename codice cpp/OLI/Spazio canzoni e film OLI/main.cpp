// NOTA: si raccomanda di usare questo template anche se non lo si capisce completamente.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void film (int &N, int &F, int &nf);
void canzoni (int &N, int &C, int &nc);

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, F, C;
        cin >> N >> F >> C;

        int nf = 0, nc = 0;

        film (N, F, nf);
        canzoni (N, C, nc);

        cout << "Case #" << test << ": ";
        cout << nf << " " << nc << endl;
    }

    return 0;
}
void film (int &N, int &F, int &nf){
    while(N >= F){
            nf++;
            N -= F;
        }
}
void canzoni (int &N, int &C, int &nc){
    while(N >= C){
            nc++;
            N -= C;
        }
}

