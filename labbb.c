#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP(int *w, int *v, int n, int wx) ;

int main() {
    int n = 5, wx = 11;
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    int *x;
    x = KnapsackDP(w, v, n, wx);
    for (int i = 0; i < n; i++) printf("%d ", x[i]);
    return 0;
}
int *KnapsackDP(int *w, int *v, int n, int wx) {
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        dp[i] = (int *)calloc(wx + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= wx; j++) {
            dp[i][j] = dp[i-1][j];
            if (w[i-1] <= j) {
                int take = dp[i-1][j - w[i-1]] + v[i-1];
                if (take > dp[i][j])
                    dp[i][j] = take;
            }
        }
    }

    int *result = (int *)calloc(n, sizeof(int));
    int j = wx;
    for (int i = n; i >= 1; i--) {
        if (dp[i][j] != dp[i-1][j]) {
            result[i-1] = 1;
            j -= w[i-1];
        }
    }

    for (int i = 0; i <= n; i++) free(dp[i]);
    free(dp);

    return result;
}
