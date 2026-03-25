#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int hd; 
    struct node *left, *right;
};


struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->hd = 0;
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


void findMinMax(struct node* root, int hd, int *min, int *max) {
    if (root == NULL)
        return;

    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;

    findMinMax(root->left, hd - 1, min, max);
    findMinMax(root->right, hd + 1, min, max);
}


void printVerticalLine(struct node* root, int line, int hd) {
    if (root == NULL)
        return;

    if (hd == line)
        printf("%d ", root->data);

    printVerticalLine(root->left, line, hd - 1);
    printVerticalLine(root->right, line, hd + 1);
}

void verticalOrder(struct node* root) {
    int min = 0, max = 0;

    findMinMax(root, 0, &min, &max);

    for (int i = min; i <= max; i++) {
        printVerticalLine(root, i, 0);
        printf("\n");
    }
}


int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order values (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* root = buildTree(arr, n, 0);

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}
