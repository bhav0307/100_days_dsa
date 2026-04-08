#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

void dfs(int node, int V, int adj[MAX][MAX], bool visited[]) {
    visited[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, V, adj, visited);
        }
    }

    push(node);  // push after visiting all neighbors
}

void topologicalSort(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V, adj, visited);
        }
    }

    printf("Topological Ordering:\n");

    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int V = 6;

    int adj[MAX][MAX] = {
        {0,1,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    topologicalSort(V, adj);

    return 0;
}
