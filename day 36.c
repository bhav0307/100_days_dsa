#include <stdio.h>

int main() {
    int queue[100];
    int front = -1, rear = -1;
    int n, m, x;
    int size = 100;

    scanf("%d", &n);

    // Enqueue
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        queue[rear] = x;
    }

    // Dequeue operations
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // Display queue
    if (front != -1) {
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
    }

    return 0;
}
