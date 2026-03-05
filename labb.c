#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy(int *w, int *v, int n, int wx) ;

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int *x = KnapsackGreedy(w, v, n, wx);
    for (int i = 0; i < n; i++) printf("%d ", x[i]);
    return 0;
}
int *KnapsackGreedy(int *w, int *v, int n, int wx) {
    int *idx = (int *)malloc(n * sizeof(int));
    int *result = (int *)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++) idx[i] = i;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[idx[j]] * w[idx[j+1]] < v[idx[j+1]] * w[idx[j]]) {
                int tmp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = tmp;
            }
        }
    }
    
    int remaining = wx;
    for (int i = 0; i < n; i++) {
        int item = idx[i];
        if (w[item] <= remaining) {
            result[item] = 1;
            remaining -= w[item];
        }
    }
    
    free(idx);
    return result;
}