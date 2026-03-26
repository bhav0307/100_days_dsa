#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

void zigzagTraversal(struct node* root) {
    if (root == NULL)
        return;

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int level[100];

        for (int i = 0; i < size; i++) {
            struct node* temp = queue[front++];

            if (leftToRight)
                level[i] = temp->data;
            else
                level[size - i - 1] = temp->data;

            if (temp->left)
                queue[rear++] = temp->left;

            if (temp->right)
                queue[rear++] = temp->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n, 0);

    zigzagTraversal(root);

    return 0;
}
