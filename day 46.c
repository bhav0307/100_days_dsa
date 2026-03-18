#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(&q, temp->left);

        if (temp->right != NULL)
            enqueue(&q, temp->right);
    }
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = createNode(arr[0]);

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* current = dequeue(&q);

        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}
