#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

int main()
{
    int n, k, i, value;
    struct node *head = NULL, *temp = NULL, *last = NULL;

    scanf("%d", &n);

    if(n <= 0)
        return 0;

    // Create list
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if(head == NULL)
        {
            head = createnode(value);
            last = head;
        }
        else
        {
            temp = createnode(value);
            last->next = temp;
            last = temp;
        }
    }

    scanf("%d", &k);

    // If k >= n, reduce it
    k = k % n;

    if(k == 0)
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Make circular
    last->next = head;

    // Move to (n - k)th node
    int steps = n - k;
    temp = head;
    for(i = 1; i < steps; i++)
        temp = temp->next;

    // New head
    head = temp->next;

    // Break circle
    temp->next = NULL;

    // Print rotated list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
