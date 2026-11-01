
#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

// Create student database
void createDatabase(struct Student s[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Name: ");
        scanf("%49s", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\nDatabase created successfully!\n");
}

// Display student database
void displayDatabase(struct Student s[], int n) {
    printf("\n-----------------------------------------\n");
    printf("           STUDENT DATABASE\n");
    printf("-----------------------------------------\n");

    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");

    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-10.2f\n",
               s[i].rollNo, s[i].name, s[i].marks);
    }

    printf("-----------------------------------------\n");
}

// Linear Search
int linearSearch(struct Student s[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (s[i].rollNo == key)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(struct Student s[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (s[mid].rollNo == key)
            return mid;

        if (s[mid].rollNo < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Insertion Sort
void insertionSort(struct Student s[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].rollNo > key.rollNo) {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(struct Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (s[j].rollNo < s[min_idx].rollNo)
                min_idx = j;
        }

        if (min_idx != i) {
            struct Student temp = s[i];
            s[i] = s[min_idx];
            s[min_idx] = temp;
        }
    }
}

// Shell Sort
void shellSort(struct Student s[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Student temp = s[i];
            int j;

            for (j = i; j >= gap &&
                 s[j - gap].rollNo > temp.rollNo; j -= gap) {
                s[j] = s[j - gap];
            }

            s[j] = temp;
        }
    }
}

// Main Function
int main() {
    struct Student students[MAX];
    int n = 0, choice, key, result;

    do {
        printf("\n=========================================\n");
        printf("    STUDENT DATABASE: SEARCH & SORT\n");
        printf("=========================================\n");

        printf("1. Create Student Database\n");
        printf("2. Display Database\n");
        printf("3. Linear Search\n");
        printf("4. Insertion Sort\n");
        printf("5. Selection Sort\n");
        printf("6. Shell Sort\n");
        printf("7. Binary Search\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);

                if (n <= 0 || n > MAX) {
                    printf("Invalid number of records!\n");
                    n = 0;
                } else {
                    createDatabase(students, n);
                }
                break;

            case 2:
                if (n == 0)
                    printf("Database is empty.\n");
                else
                    displayDatabase(students, n);
                break;

            case 3:
                if (n == 0) {
                    printf("Database is empty.\n");
                } else {
                    printf("Enter Roll Number: ");
                    scanf("%d", &key);

                    result = linearSearch(students, n, key);

                    if (result != -1)
                        printf("Student found: %s, Marks: %.2f\n",
                               students[result].name,
                               students[result].marks);
                    else
                        printf("Student not found.\n");
                }
                break;

            case 4:
                if (n == 0)
                    printf("Database is empty.\n");
                else {
                    insertionSort(students, n);
                    printf("Insertion Sort completed!\n");
                    displayDatabase(students, n);
                }
                break;

            case 5:
                if (n == 0)
                    printf("Database is empty.\n");
                else {
                    selectionSort(students, n);
                    printf("Selection Sort completed!\n");
                    displayDatabase(students, n);
                }
                break;

            case 6:
                if (n == 0)
                    printf("Database is empty.\n");
                else {
                    shellSort(students, n);
                    printf("Shell Sort completed!\n");
                    displayDatabase(students, n);
                }
                break;

            case 7:
                if (n == 0) {
                    printf("Database is empty.\n");
                } else {
                    printf("Enter Roll Number: ");
                    scanf("%d", &key);

                    result = binarySearch(students, 0, n - 1, key);

                    if (result != -1)
                        printf("Student found: %s, Marks: %.2f\n",
                               students[result].name,
                               students[result].marks);
                    else
                        printf("Student not found.\n");
                }
                break;

            case 8:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}
