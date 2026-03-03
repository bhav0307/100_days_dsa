#include <stdio.h>

int stack[100];
int top = -1;

int main() {
    int n, type, value;
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &type);

        if(type == 1) {          // Push
            scanf("%d", &value);
            stack[++top] = value;
        }
        else if(type == 2) {     // Pop
            if(top == -1)
                printf("Stack Underflow\n");
            else
                printf("%d\n", stack[top--]);
        }
        else if(type == 3) {     // Display
            if(top == -1)
                printf("Stack is Empty\n");
            else {
                for(int i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
                printf("\n");
            }
        }
    }

    return 0;
}
