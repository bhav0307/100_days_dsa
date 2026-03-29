#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create new node
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue structure for level order insertion
struct queue
{
    struct node* arr[100];
    int front, rear;
};

void initQueue(struct queue* q)
{
    q->front = q->rear = -1;
}

int isEmpty(struct queue* q)
{
    return q->front == -1;
}

void enqueue(struct queue* q, struct node* temp)
{
    if(q->rear == 99)
        return;

    if(q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = temp;
}

struct node* dequeue(struct queue* q)
{
    if(isEmpty(q))
        return NULL;

    struct node* temp = q->arr[q->front];

    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

// Build tree from level order
struct node* buildTree(int arr[], int n)
{
    if(n == 0 || arr[0] == -1)
        return NULL;

    struct queue q;
    initQueue(&q);

    struct node* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while(i < n)
    {
        struct node* curr = dequeue(&q);

        // Left child
        if(arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if(i >= n)
            break;

        // Right child
        if(arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Mirror the tree
void mirror(struct node* root)
{
    if(root == NULL)
        return;

    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n);

    mirror(root);

    inorder(root);

    return 0;
}
