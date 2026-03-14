#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;
struct node *top = NULL;

void enqueue(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}


int dequeue() {
    struct node *temp = front;
    int val = temp->data;
    front = front->next;
    if(front == NULL) rear = NULL;
    free(temp);
    return val;
}

// Stack push
void push(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

// Stack pop
int pop() {
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    int n, x;

    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        enqueue(x);
    }

    while(front != NULL) {
        push(dequeue());
    }

    while(top != NULL) {
        enqueue(pop());
    }

    while(fron
