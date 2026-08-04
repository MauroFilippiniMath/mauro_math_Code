#include <iostream>

using namespace std; 

void print_array(int a[], unsigned l){
    for(int i = 0; i < l - 1; i++) cout << a[i] << ", ";
    cout << a[l - 1];
}
    
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

unsigned bubble_sort_optimized(int a[], unsigned l){ 
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
void bubble_sort_rec(int *a, const unsigned l){
    if(l > 1){
        for(int i = 1; i < l ; i++){
            if(a[i-1] > a[i]) swap(a[i-1], a[i]);
        }   
        bubble_sort_rec(a, l-1);
    }
}

void bubble_sort_opt_rec(int *a, const unsigned l){
    if(a && l > 1){
        unsigned last_swap = 0;
        for(int i = 1; i < l; i++){
            if(a[i-1] > a[i]){
                swap(a[i-1], a[i]);
                last_swap = i;
            } 
        }   
        bubble_sort_rec(a, last_swap);
    }
}
void bubble_sort_rec_comp(int *a, unsigned l, unsigned lower = 0){
    if(l > 1){                      //condizione per la fine dell'ordinamento 
        if(lower == l - 1){         //condizione uscita dagli swap
            return bubble_sort_rec_comp(a, l - 1, 0);//riduzione della lunghezza (while)
        }  
        if(a[lower] > a[lower + 1]) swap(a[lower], a[lower + 1]); //fa swap (for)
        bubble_sort_rec_comp(a, l, lower + 1);
    }
}

void bubble_sort_rec_comp_sentinel(int *a, unsigned l, unsigned lower = 0, unsigned last_swap = 0){
    if(l > 1){
        if(lower == l - 1) return bubble_sort_rec_comp_sentinel(a, last_swap + 1, 0, 0);
        if(a[lower] > a[lower + 1]){
            swap(a[lower], a[lower + 1]);
            last_swap = lower;
        }
        bubble_sort_rec_comp_sentinel(a, l, lower + 1, last_swap);
    }
}

int main(){   
    unsigned l = 10;
    int a[l] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    //int a[l] = {6, 7, 8, 9, 6, 10, 4, 3, 2, 1};
    //int a[l] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //cout << "bubble sort optimized = " << bubble_sort_optimized(a, l) << endl;
    //bubble_sort_rec(a, l);
    //bubble_sort_opt_rec(a, l);
    //bubble_sort_rec_comp(a, l);
    bubble_sort_rec_comp_sentinel(a, l);
    print_array(a, l);
    
    return 0;
}