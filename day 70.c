#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

void bellmanFord(int n, int m, Edge edges[], int source) {

    int dist[MAX];

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    // Step 2: Relax edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Detect negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Print shortest distances
    printf("Shortest distances from source %d:\n", source);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

int main() {

    int n, m, source;

    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    Edge edges[m];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    printf("Enter source vertex:\n");
    scanf("%d", &source);

    bellmanFord(n, m, edges, source);

    return 0;
}
