#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//ricevute le 4 lunghezze delle stringhe ne calcola la minore
int minore (int N1, int N2, int N3, int N4){
    int m = N1;           //valore più piccolo
    if(m > N2) m = N1;
    if(m > N3) m = N3;
    if(m > N4) m = N4;
    return m;
}

//cerca un carattere in un array, se lo trova dà l'indirizzo se non lo trova ritorna 200

int cerca (char find, string a, int l){
    bool b2 = true;
    int out = 200; //output
    int y = 0;
    while(b2){ //verifica se il valore analizzato è presente nell'array

      if(a[y] == find){
         b2 = false;
         out = y;
       }
      if(y > l) b2 = false;
      y++;
    }
    return out;
}

int codice (string v, string a, string b, string c, int &l1, int &l2, int &l3){
  int i = 0;
  int a1, b1, c1;
  while(true){
      char find = v[i];

      a1 = cerca(find, a, l1);
      if(a1 == 200){
          i++;
          continue;
      }
      b1 = cerca(find, b, l2);
      if(b1 == 200){
          i++;
          continue;
      }
      c1 = cerca(find, c, l3);
      if(c1 == 200){
          i++;
          continue;
      }
      //se arriva fino a qui vuol dire che ha trovato lo stesso carattere in ogni array
      find = v[i + 1]; //controlla se vi è il valore successivo
      if(a[a1 + 1] != find){ //errore
          i++;
          continue;
      }
      if(b[b1 + 1] != find){ //errore
          i++;
          continue;
      }
      if(c[c1 + 1] != find){ //errore
          i++;
          continue;
      }
      //ha trova il virus
      break;
  }
  //deve restituire l'output
  l1 = a1;
  l2 = b1;
  l3 = c1;
  return i;
  //i, a1, a2, a3

}

int main() {
    // decommenta le due righe seguenti se vuoi leggere/scrivere da file
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N1, N2, N3, N4;
        cin >> N1 >> N2 >> N3 >> N4;

        int M;
        cin >> M;

        string F1;
        cin >> F1;

        string F2;
        cin >> F2;

        string F3;
        cin >> F3;

        string F4;
        cin >> F4;

        int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

        int min = minore(N1, N2, N3, N4); //min = lunghezza della stringa minore

        if(min == N1){
            p1 = codice (F1, F2, F3, F4, N2, N3, N4);
            p2 = N2;
            p3 = N3;
            p4 = N4;
        }
        if(min == N2){
            p2 = codice (F2, F1, F3, F4, N1, N3, N4);
            p1 = N1;
            p3 = N3;
            p4 = N4;
        }
        if(min == N3){
            p3 = codice (F3, F1, F2, F4, N1, N2, N4);
            p1 = N1;
            p2 = N2;
            p4 = N4;
        }
        if(min == N4){
            p4 = codice (F4, F1, F2, F3, N1, N2, N3);
            p1 = N1;
            p2 = N2;
            p3 = N3;
        }

        cout << "Case #" << test << ": ";
        cout << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
    }

    return 0;
}