#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push operation
void push(int value) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    
    return value;
}

// Evaluate postfix
int evaluatePostfix(char exp[]) {
    int i = 0;
    
    while (exp[i] != '\0') {
        
        // If digit push to stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        
        // If operator
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            
            int b = pop();
            int a = pop();
            
            switch(exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        
        i++;
    }
    
    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("Result = %d", result);

    return 0;
}
