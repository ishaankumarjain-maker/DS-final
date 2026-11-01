
#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    int jobId;
    char title[50];
} PrintJob;

typedef struct {
    PrintJob jobs[MAX];
    int front, rear;
} CircularQueue;

// Initialize queue
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    printf("Queue initialized successfully.\n");
}

// Check if queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Check if queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

// Add a print job
void enqueue(CircularQueue *q, int jobId, const char *title) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->rear = (q->rear + 1) % MAX;

    q->jobs[q->rear].jobId = jobId;
    strcpy(q->jobs[q->rear].title, title);

    printf("Print job added successfully.\n");
}

// Remove a print job
void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Processed Job ID: %d\n", q->jobs[q->front].jobId);
    printf("Title: %s\n", q->jobs[q->front].title);

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % MAX;
    }
}

// Display all pending jobs
void display(CircularQueue *q) {
    int i;

    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("\nPending Print Jobs:\n");

    i = q->front;

    while (1) {
        printf("Job ID: %d | Title: %s\n",
               q->jobs[i].jobId, q->jobs[i].title);

        if (i == q->rear)
            break;

        i = (i + 1) % MAX;
    }
}

// Main function
int main() {
    CircularQueue q;
    int choice, jobId;
    char title[50];

    initQueue(&q);

    do {
        printf("\n--- PRINTER QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &jobId);

                printf("Enter Document Title: ");
                scanf("%49s", title);

                enqueue(&q, jobId, title);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Program terminated successfully.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
