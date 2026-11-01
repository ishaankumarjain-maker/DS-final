
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int n) {
    stack[++top] = n;
}

// Pop operation
int pop() {
    return stack[top--];
}

// Evaluate postfix expression
int evaluate(char exp[]) {
    int i, a, b;

    for (i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == ' ' || exp[i] == '\n')
            continue;

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else {
            b = pop();
            a = pop();

            if (exp[i] == '+')
                push(a + b);
            else if (exp[i] == '-')
                push(a - b);
            else if (exp[i] == '*')
                push(a * b);
            else if (exp[i] == '/')
                push(a / b);
        }
    }

    return pop();
}

// Main function
int main() {
    char exp[MAX];

    printf("Enter Postfix Expression: ");
    fgets(exp, MAX, stdin);

    printf("Result = %d\n", evaluate(exp));

    return 0;
}
