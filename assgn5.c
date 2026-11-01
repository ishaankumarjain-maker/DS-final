
#include <stdio.h>
#include <stdlib.h>

struct Node {
    float coeff;
    int exp;
    struct Node *next;
};

// Insert a term
void insert(struct Node **head, float c, int e) {
    struct Node *newNode, *temp;

    if (c == 0)
        return;

    newNode = malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    temp = *head;

    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

// Create polynomial
struct Node *createPolynomial() {
    struct Node *head = NULL;
    int n, e, i;
    float c;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%f %d", &c, &e);

        insert(&head, c, e);
    }

    return head;
}

// Display polynomial
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("0\n");
        return;
    }

    do {
        printf("%.2fx^%d", temp->coeff, temp->exp);

        temp = temp->next;

        if (temp != head)
            printf(" + ");

    } while (temp != head);

    printf("\n");
}

// Add two polynomials
struct Node *addPolynomial(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;
    struct Node *temp;

    if (p1 != NULL) {
        temp = p1;

        do {
            insert(&result, temp->coeff, temp->exp);
            temp = temp->next;
        } while (temp != p1);
    }

    if (p2 != NULL) {
        temp = p2;

        do {
            // Add coefficients of like exponents
            struct Node *r = result;
            int found = 0;

            if (result != NULL) {
                do {
                    if (r->exp == temp->exp) {
                        r->coeff += temp->coeff;
                        found = 1;
                        break;
                    }
                    r = r->next;
                } while (r != result);
            }

            if (!found)
                insert(&result, temp->coeff, temp->exp);

            temp = temp->next;
        } while (temp != p2);
    }

    return result;
}

// Main function
int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;
    int choice;

    do {
        printf("\n--- Polynomial Operations ---\n");
        printf("1. Create Polynomial 1\n");
        printf("2. Display Polynomial 1\n");
        printf("3. Create Polynomial 2\n");
        printf("4. Display Polynomial 2\n");
        printf("5. Add Polynomials\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                poly1 = createPolynomial();
                break;

            case 2:
                printf("Polynomial 1: ");
                display(poly1);
                break;

            case 3:
                poly2 = createPolynomial();
                break;

            case 4:
                printf("Polynomial 2: ");
                display(poly2);
                break;

            case 5:
                sum = addPolynomial(poly1, poly2);
                printf("Sum: ");
                display(sum);
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
