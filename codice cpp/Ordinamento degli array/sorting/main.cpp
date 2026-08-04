/******************************************************************************

unsigned test1(int a[], unsigned l){
    unsigned pos = 1;       //tiene conto della posizione 
    unsigned c = 0; 
    while(pos < l){
        for(int i = pos; i > 0; i--){
            c++;
            if(a[i - 1] < a[i]) swap(a[i - 1], a[i]);
            else i = 0;
        }
        pos++;
    }
    return c;
}

*******************************************************************************/
#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
unsigned bubble_sort(int a[], unsigned l){ //45
    unsigned c = 0;
    while(l > 1){    
        for(int i = 0; i < l - 1; i++){
            c++;
            if(a[i] > a[i+1]) swap(a[i], a[i+1]);
        }        
        l--;
    }   
    return c;
}
unsigned bubble_sort_with_sentinel(int a[], unsigned l){ //39
    unsigned c = 0;
    bool s = true;
    while(l > 1 && s){  
        s = false;
        for(int i = 0; i < l - 1; i++){
            c++;
            if(a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                s = true;
            } 
        }        
        l--;
    }   
    return c;
}
unsigned bubble_sort_optimized(int a[], unsigned l){ //33
    unsigned c = 0;
    while(l > 1){  
        unsigned t = 0;
        for(int i = 1; i < l ; i++){
            c++;
            if(a[i-1] > a[i]){
                swap(a[i-1], a[i]);
                t = i;
            } 
        }        
        l = t;
    }   
    return c;
}
void print_array(int a[], unsigned l){
    for(int i = 0; i < l - 1; i++) cout << a[i] << ", ";
    cout << a[l - 1];
}

/*ordina un numero alla volta, e ad ogni volta si occupa di ordinare il successivo, tuttavia 
se sta provando a posizionare il nuovo numero e quando fa il controllo non necessità 
di essere spostato, allora vuole dire che si trova già nella posizione corretta 
*/
unsigned insertion_sort_swap(int a[], unsigned l){ 
    unsigned c = 0;         // contatore 
    for(int pos = 1; pos < l; pos++){
        for(int i = pos; i > 0 && a[i] < a[i - 1]; i--){
            swap(a[i - 1], a[i]);
            c++;
        }
    }
    return c;
}
/*confronta 2 voti alla volta prima quelle tra le posizioni pari e poi quelli tra le posizioni dispari 
forse se si confrontano la prima e l'ultima in quelle dispere 
*/

unsigned insertion_sort(int a[], unsigned l){ 
    unsigned c = 0;         // contatore 
    for(int pos = 1; pos < l; pos++){
        int t = a[pos];                     //valore da posizionare
        int i = pos;
        for(; i > 0 && t < a[i - 1]; i--){
            a[i] = a[i - 1];
            c++;
        }
        a[i] = t;
    }
    return c;
}

unsigned binary_search(int* a, unsigned left, unsigned right, int n){
    while(left < right){
        unsigned m = left + (right - left) / 2;
        if(n > a[m]) left = m + 1;
        else right = m;
    }
    return left;
}

unsigned insertion_sort_binary(int a[], unsigned l){ 
    unsigned c = 0;         // contatore 
    for(unsigned i = 1; i < l; i++){
        int t = a[i];                     //valore da posizionare
        unsigned pos = binary_search(a, 0, i, t);
        for(unsigned j = i; j > pos; j--){
            a[j] = a[j - 1];
            c++;
        }
        a[pos] = t;
    }
    return c;
}

unsigned selection_sort_min(int* a, unsigned l){
    unsigned c = 0;
    if(a && l > 1){
        for(int i = 0; i < l-1; i++){
            int t = i;
            for(int j = i; j < l; j++){
                if(a[j] < a[t]){
                    t = j;
                    c++;
                } 
            }
            if(t > i){
                swap(a[t], a[i]);
                c++;
            }
        }
    }
    return c;
}

int main()
{
    unsigned l = 10;
    
    //int a[l] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    //int a[l] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a[l] = {9, 10, 7, 8, 5, 6, 3, 4, 2, 1};

    //cout << "bubble sort = " << bubble_sort(a, l) << endl;
    //cout << "bubble sort with sentinel = " << bubble_sort_with_sentinel(a, l) << endl;
    //cout << "bubble sort optimized = " << bubble_sort_optimized(a, l) << endl;
    //cout << "insertion_sort_swap = " << insertion_sort_swap(a, l) << endl;
    //cout << "insertion_sort = " << insertion_sort(a, l) << endl;
    //cout << "insertion_sort_binary = " << insertion_sort_binary(a, l) << endl;
    
    cout << "selection_sort_min = " << selection_sort_min(a, l) << endl;
    print_array(a, l);
    

    return 0;
}