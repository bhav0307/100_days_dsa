#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node* next;
};

struct Graph
{
    int numVertices;
    struct Node** adjLists;
};

struct Queue
{
    int items[100];
    int front;
    int rear;
};

struct Node* createNode(int v)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for(int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void initQueue(struct Queue* q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q)
{
    return q->front == -1;
}

void enqueue(struct Queue* q, int value)
{
    if(q->rear == 99)
        return;

    if(q->front == -1)
        q->front = 0;

    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q)
{
    int item = q->items[q->front];

    if(q->front >= q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return item;
}

void BFS(struct Graph* graph, int startVertex)
{
    int visited[graph->numVertices];

    for(int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    struct Queue q;
    initQueue(&q);

    visited[startVertex] = 1;
    enqueue(&q, startVertex);

    while(!isEmpty(&q))
    {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while(temp)
        {
            int adjVertex = temp->vertex;

            if(!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }

            temp = temp->next;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int source;
    scanf("%d", &source);

    BFS(graph, source);

    return 0;
}
