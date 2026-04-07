#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool dfs(int node, int V, int adj[MAX][MAX], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            }
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = false;
    return false;
}

int hasCycle(int V, int adj[MAX][MAX]) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V = 4;

    int adj[MAX][MAX] = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,1,0,0}  // cycle exists (3 → 1)
    };

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
