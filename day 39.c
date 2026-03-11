#include <stdio.h>

int deque[100];
int front = -1;
int rear = -1;

void push_front(int x)
{
    if(front == -1)
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
    if(front == -1)
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
    if(front == -1 || front > rear)
        return;
    front++;
}

void pop_back()
{
    if(front == -1 || front > rear)
        return;
    rear--;
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);
    pop_front();
    pop_back();

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    return 0;
}
