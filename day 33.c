/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x = stack[top];
    top--;
    return x;
}

int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, j = 0;

    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        if(isalnum(infix[i]))   // operand
        {
            postfix[j++] = infix[i];
        }
        else                    // operator
        {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}
