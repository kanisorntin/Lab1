#include <stdio.h>
#include <stdlib.h>

int bestValue = 0;
int *bestX;
int gn;

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) ;

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int *x, vx;

    x = (int *)calloc(n, sizeof(int));
    bestX = (int *)calloc(n, sizeof(int));
    bestValue = 0;

    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d ", vx);
    for (int i = 0; i < n; i++) printf("%d ", bestX[i]);
    return 0;
}
int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    gn = n;
    
    if (i == n) {
        int totalW = 0, totalV = 0;
        for (int k = 0; k < n; k++) {
            totalW += x[k] * w[k];
            totalV += x[k] * v[k];
        }
        if (totalW <= wx && totalV > bestValue) {
            bestValue = totalV;
            for (int k = 0; k < n; k++)
                bestX[k] = x[k];
        }
        return bestValue;
    }

    x[i] = 0;
    KnapsackBT(w, v, n, wx, i + 1, x);

    x[i] = 1;
    KnapsackBT(w, v, n, wx, i + 1, x);

    x[i] = 0;

    return bestValue;
}