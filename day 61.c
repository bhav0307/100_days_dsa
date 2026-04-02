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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Search root in inorder array
int search(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree from inorder & postorder
struct node* buildTree(int inorder[], int postorder[],
                       int inStart, int inEnd,
                       int *postIndex)
{
    if(inStart > inEnd)
        return NULL;

    // Root = last element of postorder
    struct node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    // If leaf node
    if(inStart == inEnd)
        return root;

    int index = search(inorder, inStart, inEnd, root->data);

    // Build right subtree first
    root->right = buildTree(inorder, postorder,
                            index + 1, inEnd, postIndex);

    // Build left subtree
    root->left = buildTree(inorder, postorder,
                           inStart, index - 1, postIndex);

    return root;
}

// Preorder traversal (Output)
void preorder(struct node* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct node* root =
        buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}
