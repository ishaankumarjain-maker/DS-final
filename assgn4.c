
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int RegNo;
    char Name[50];
    struct Student *next;
};

typedef struct Student Node;

// Add student
void addStudent(Node **head) {
    Node *newNode, *temp;

    newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Registration Number: ");
    scanf("%d", &newNode->RegNo);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", newNode->Name);

    newNode->next = NULL;

    if (*head == NULL)
        *head = newNode;
    else {
        temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Student added successfully.\n");
}

// Remove student
void removeStudent(Node **head) {
    Node *temp = *head, *prev = NULL;
    int no;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter Registration Number to remove: ");
    scanf("%d", &no);

    while (temp != NULL && temp->RegNo != no) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Student deleted successfully.\n");
}

// Display students
void displayList(Node *head) {
    Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nRegNo\tName\n");

    while (temp != NULL) {
        printf("%d\t%s\n", temp->RegNo, temp->Name);
        temp = temp->next;
    }
}

// Count students
void countParticipants(Node *head) {
    int count = 0;
    Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total Participants: %d\n", count);
}

// Sort students
void sortList(Node *head) {
    Node *temp;
    int r, swapped;
    char n[50];

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    do {
        swapped = 0;
        temp = head;

        while (temp->next != NULL) {
            if (temp->RegNo > temp->next->RegNo) {
                r = temp->RegNo;
                temp->RegNo = temp->next->RegNo;
                temp->next->RegNo = r;

                strcpy(n, temp->Name);
                strcpy(temp->Name, temp->next->Name);
                strcpy(temp->next->Name, n);

                swapped = 1;
            }

            temp = temp->next;
        }

    } while (swapped);

    printf("List sorted successfully.\n");
}

// Reverse students
void reverseList(Node **head) {
    Node *prev = NULL, *current = *head, *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

    printf("List reversed successfully.\n");
}

// Main function
int main() {
    Node *head = NULL;
    int choice;

    do {
        printf("\n--- Workshop Enrollment System ---\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display List\n");
        printf("4. Count Participants\n");
        printf("5. Sort List\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&head);
                break;

            case 2:
                removeStudent(&head);
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                countParticipants(head);
                break;

            case 5:
                sortList(head);
                break;

            case 6:
                reverseList(&head);
                break;

            case 7:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}
