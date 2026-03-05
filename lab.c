#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *Dijkstra(int *L, int n) {
    int *dist = (int *)malloc(n * sizeof(int));
    int *visited = (int *)calloc(n, sizeof(int));
    
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[0] = 0;
    
    for (int count = 0; count < n - 1; count++) {
        int u = -1, minDist = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        
        for (int v = 0; v < n; v++) {
            int weight = L[u * n + v];
            if (!visited[v] && weight != -1 && dist[u] != INT_MAX) {
                int newDist = dist[u] + weight;
                if (newDist < dist[v])
                    dist[v] = newDist;
            }
        }
    }
    
    free(visited);
    return dist;
}

int main() {
    int n = 5, i = 0, j = 0, *d, *g;
    g = (int *)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100;  g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;   g[0 * n + 4] = 10;
    g[1 * n + 2] = 20;   g[3 * n + 1] = 20;
    g[3 * n + 2] = 20;   g[4 * n + 3] = 10;

    d = Dijkstra(g, n);
    for (i = 0; i < n - 1; i++)
        printf("%d ", d[i]);
    return 0;
}