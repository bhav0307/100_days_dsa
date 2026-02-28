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
    int n, i, value;
    struct node *head = NULL, *temp = NULL, *last = NULL;

    scanf("%d", &n);

    if(n <= 0)
        return 0;

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

    
    last->next = head;


    temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    return 0;
}
