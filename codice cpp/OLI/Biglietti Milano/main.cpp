#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {
    if(A * M < B) return N * A;
    if(N % M * A < B) return (N / M)* B + (N % M)* A;
    return ((N / M) + 1)* B;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}