
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

// Push operation
void push(char str[]) {
    strcpy(stack[++top], str);
}

// Pop operation
void pop(char str[]) {
    strcpy(str, stack[top--]);
}

// Operator precedence
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    char s[MAX];
    int i, j = 0, t = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            s[++t] = ch;

        else if (ch == ')') {
            while (t != -1 && s[t] != '(')
                postfix[j++] = s[t--];

            if (t != -1)
                t--;
        }

        else {
            while (t != -1 && s[t] != '(' &&
                  (precedence(s[t]) > precedence(ch) ||
                  (precedence(s[t]) == precedence(ch) && ch != '^')))
                postfix[j++] = s[t--];

            s[++t] = ch;
        }
    }

    while (t != -1)
        postfix[j++] = s[t--];

    postfix[j] = '\0';
}

// Prefix to Infix
void prefixToInfix(char prefix[], char infix[]) {
    int i;
    char a[MAX], b[MAX], temp[MAX];

    top = -1;

    for (i = strlen(prefix) - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            char ch[2] = {prefix[i], '\0'};
            push(ch);
        }
        else if (prefix[i] != ' ') {
            pop(a);
            pop(b);

            sprintf(temp, "(%s%c%s)", a, prefix[i], b);
            push(temp);
        }
    }

    pop(infix);
}

// Postfix to Infix
void postfixToInfix(char postfix[], char infix[]) {
    int i;
    char a[MAX], b[MAX], temp[MAX];

    top = -1;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            char ch[2] = {postfix[i], '\0'};
            push(ch);
        }
        else if (postfix[i] != ' ') {
            pop(b);
            pop(a);

            sprintf(temp, "(%s%c%s)", a, postfix[i], b);
            push(temp);
        }
    }

    pop(infix);
}

// Main function
int main() {
    int choice;
    char expr[MAX], result[MAX];

    do {
        printf("\n--- STACK EXPRESSION CONVERSION ---\n");
        printf("1. Infix to Postfix\n");
        printf("2. Prefix to Infix\n");
        printf("3. Postfix to Infix\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                fgets(expr, MAX, stdin);
                expr[strcspn(expr, "\n")] = '\0';

                infixToPostfix(expr, result);
                printf("Postfix: %s\n", result);
                break;

            case 2:
                printf("Enter Prefix Expression: ");
                fgets(expr, MAX, stdin);
                expr[strcspn(expr, "\n")] = '\0';

                prefixToInfix(expr, result);
                printf("Infix: %s\n", result);
                break;

            case 3:
                printf("Enter Postfix Expression: ");
                fgets(expr, MAX, stdin);
                expr[strcspn(expr, "\n")] = '\0';

                postfixToInfix(expr, result);
                printf("Infix: %s\n", result);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
