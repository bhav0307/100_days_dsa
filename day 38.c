#include<stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int x)
{
    if(front == 0)
        printf("Overflow\n");
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else
    {
        front--;
        deque[front] = x;
    }
}

void push_back(int x)
{
    if(rear == MAX-1)
        printf("Overflow\n");
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else
    {
        rear++;
        deque[rear] = x;
    }
}

void pop_front()
{
    if(front == -1)
        printf("Underflow\n");
    else if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(rear == -1)
        printf("Underflow\n");
    else if(front == rear)
        front = rear = -1;
    else
        rear--;
}

int get_front()
{
    if(front == -1)
        return -1;
    return deque[front];
}

int get_back()
{
    if(rear == -1)
        return -1;
    return deque[rear];
}

int empty()
{
    if(front == -1)
        return 1;
    return 0;
}

int size()
{
    if(front == -1)
        return 0;
    return rear - front + 1;
}

void clear()
{
    front = rear = -1;
}

void display()
{
    if(front == -1)
        return;

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    printf("%d\n", get_front());
    printf("%d\n", get_back());
    printf("%d\n", size());

    pop_front();
    pop_back();

    display();

    clear();

    printf("%d\n", empty());

    return 0;
}
