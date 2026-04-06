#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int V;
    struct Node** adj;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));

    for(int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adj[dest];
    graph->adj[dest] = newNode;
}

int dfs(struct Graph* graph, int v, int visited[], int parent)
{
    visited[v] = 1;

    struct Node* temp = graph->adj[v];

    while(temp)
    {
        int adjVertex = temp->vertex;

        if(!visited[adjVertex])
        {
            if(dfs(graph, adjVertex, visited, v))
                return 1;
        }
        else if(adjVertex != parent)
        {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int hasCycle(struct Graph* graph)
{
    int visited[graph->V];

    for(int i = 0; i < graph->V; i++)
        visited[i] = 0;

    for(int i = 0; i < graph->V; i++)
    {
        if(!visited[i])
        {
            if(dfs(graph, i, visited, -1))
                return 1;
        }
    }

    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    if(hasCycle(graph))
        printf("YES");
    else
        printf("NO");

    return 0;
}
