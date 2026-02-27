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

int getLength(struct node* head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct node* findIntersection(struct node* head1, struct node* head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;
    
    if(len1 > len2)
    {
        diff = len1 - len2;
        while(diff--)
            head1 = head1->next;
    }
    else
    {
        diff = len2 - len1;
        while(diff--)
            head2 = head2->next;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data == head2->data)
            return head1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main()
{
    int n, m, i, value;
    struct node *head1 = NULL, *head2 = NULL, *temp;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if(head1 == NULL)
        {
            head1 = createnode(value);
            temp = head1;
        }
        else
        {
            temp->next = createnode(value);
            temp = temp->next;
        }
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        scanf("%d", &value);
        if(head2 == NULL)
        {
            head2 = createnode(value);
            temp = head2;
        }
        else
        {
            temp->next = createnode(value);
            temp = temp->next;
        }
    }

    struct node* intersection = findIntersection(head1, head2);

    if(intersection != NULL)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}
