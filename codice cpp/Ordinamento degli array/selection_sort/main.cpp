#include <iostream>

using namespace std;

// scambia due elementi tra di loro
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
// stampa dell'array
void print_array(int a[], int l){
    for(int i = 0; i < l - 1; i++){
        cout << a[i] << ", ";
    }
    cout << a[l - 1];
}
// selection_sort usando solo il minimo 
unsigned selection_sort(int a[], int l){
    unsigned c = 0;
    unsigned pos = 0;           // positione fino a cui l'array è già ordinato
    for(int i = 0; i < l - 1; i++){
        int min = pos;
        for(int j = l - 1; j > pos; j--){
            if(a[min] > a[j]) min = j;
            c++;
        } 
        swap(a[min], a[pos]);
        pos++;
    }
    return c;
};
// selection_sort usando minimo e massimo
unsigned selection_sort_double(int a[], int l){
    unsigned c = 0;
    unsigned pos = 0;           // positione fino a cui l'array è già ordinato
    l--;
    for(int i = 0; i < l - pos; i++){
        int min = pos;
        int max = pos; 
        for(int j = l - pos; j > pos; j--){
            if(a[min] > a[j]) min = j;
            if(a[max] < a[j]) max = j;
            c++;
        } 
        // nel caso peggiore se fa i 2 scambi fa sempre lo stesso scambio 2 volte 
        // e quindi non cambia nulla
        if(max != pos){
            swap(a[min], a[pos]);
            swap(a[max], a[l - pos]);
        }
        else swap(a[max], a[min]);      // serve per non fare 2 scambi uguali 

        // questo linee di codice sono identiche alle precedenti 
        /*      
        if(max != pos){
            swap(a[min], a[pos]);
        }
        swap(a[max], a[l - pos]);
        */
        pos++;
    }
    return c;
};
int main()
{
    unsigned l = 10;
    //int a[l] = {10, 9, 7, 3, 8, 5, 4, 6, 2, 1};
    int a[l] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    //cout << "selection_sort: " << selection_sort(a, l) << endl;
    cout << "selection_sort_double: " << selection_sort_double(a, l) << endl;
    print_array(a, l);
    
    return 0;
}