#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


int search(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}


struct node* buildTree(int inorder[], int postorder[],
                       int inStart, int inEnd, int *postIndex)
{
    if(inStart > inEnd)
        return NULL;


    struct node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

   
    if(inStart == inEnd)
        return root;

    int inIndex = search(inorder, inStart, inEnd, root->data);


    root->right = buildTree(inorder, postorder,
                            inIndex + 1, inEnd, postIndex);

    root->left = buildTree(inorder, postorder,
                           inStart, inIndex - 1, postIndex);

    return root;
}


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

    struct node* root = buildTree(inorder, postorder,
                                 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}
