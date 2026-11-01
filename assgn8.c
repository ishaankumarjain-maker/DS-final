
#include <stdio.h>
#include <string.h>

#define MAX 5

struct PrintJob {
    int jobID;
    char documentTitle[50];
};

struct PrintJob queue[MAX];
int front = -1, rear = -1;

// Function declarations
void enqueue();
void dequeue();
void display();

int main() {
    int choice;

    do {
        printf("\n--- PRINT QUEUE MENU ---\n");
        printf("1. Enqueue Print Job\n");
        printf("2. Dequeue Print Job\n");
        printf("3. Display Print Jobs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminates successfully.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}

// Add a print job
void enqueue() {
    int id;
    char title[50];

    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter Job ID: ");
    scanf("%d", &id);

    printf("Enter Document Title: ");
    scanf(" %49[^\n]", title);

    if (front == -1)
        front = 0;

    rear++;

    queue[rear].jobID = id;
    strcpy(queue[rear].documentTitle, title);

    printf("Print job added successfully.\n");
}

// Remove a print job
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Processed Job ID: %d\n", queue[front].jobID);
    printf("Document Title: %s\n", queue[front].documentTitle);

    front++;

   
}

// Display all print jobs
void display() {
    int i;

    if (front == -1) {
        printf("No pending print jobs.\n");
        return;
    }

    printf("\nPrint Jobs in FIFO Order:\n");

    for (i = front; i <= rear; i++) {
        printf("Job ID: %d | Document Title: %s\n",
               queue[i].jobID, queue[i].documentTitle);
    }
}
