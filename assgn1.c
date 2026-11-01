#include <stdio.h>

#define MAX 10

// Function to read a matrix
void readMatrix(int mat[MAX][MAX], int row, int col, char name) {
    printf("Enter elements of matrix %c (%dx%d):\n", name, row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c[%d][%d] = ", name, i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

// 1. Matrix Addition: C[i][j] = A[i][j] + B[i][j]
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

// 2. Matrix Subtraction: C[i][j] = A[i][j] - B[i][j]
void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

// 3. Matrix Multiplication: C[i][j] = Σ (A[i][k] × B[k][j])
void multiplyMatrices(int a[MAX][MAX], int r1, int c1, int b[MAX][MAX], int r2, int c2, int res[MAX][MAX]) {
    // Initialize result matrix to 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// 4. Transpose of a Matrix: AT[i][j] = A[j][i][cite: 1]
void transposeMatrix(int mat[MAX][MAX], int res[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[j][i] = mat[i][j];
        }
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("--- Matrix Operations in C ---\n");
    
    while (1) {
        printf("\nChoose an Operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Transpose\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Addition
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (r1 != r2 || c1 != c2) {
                    printf("Error: Matrix addition requires both matrices to have the same dimensions[cite: 1]!\n");
                    break;
                }

                readMatrix(a, r1, c1, 'A');
                readMatrix(b, r2, c2, 'B');
                addMatrices(a, b, result, r1, c1);
                
                printf("\nResult of Matrix Addition:\n");
                displayMatrix(result, r1, c1);
                break;

            case 2: // Subtraction
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (r1 != r2 || c1 != c2) {
                    printf("Error: Matrix subtraction requires both matrices to have the same dimensions[cite: 1]!\n");
                    break;
                }

                readMatrix(a, r1, c1, 'A');
                readMatrix(b, r2, c2, 'B');
                subtractMatrices(a, b, result, r1, c1);
                
                printf("\nResult of Matrix Subtraction:\n");
                displayMatrix(result, r1, c1);
                break;

            case 3: // Multiplication
                printf("Enter rows and columns for Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns for Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2) {
                    printf("Error: Number of columns of Matrix A must equal the number of rows of Matrix B for multiplication[cite: 1]!\n");
                    break;
                }

                readMatrix(a, r1, c1, 'A');
                readMatrix(b, r2, c2, 'B');
                multiplyMatrices(a, r1, c1, b, r2, c2, result);
                
                printf("\nResult of Matrix Multiplication:\n");
                displayMatrix(result, r1, c2);
                break;

            case 4: // Transpose
                printf("Enter rows and columns for the Matrix: ");
                scanf("%d %d", &r1, &c1);

                readMatrix(a, r1, c1, 'A');
                transposeMatrix(a, result, r1, c1);
                
                printf("\nResult of Matrix Transpose:\n");
                displayMatrix(result, c1, r1);
                break;

            case 5:
                printf("Exiting program. Good luck with your assignment!\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option between 1 and 5.\n");
        }
    }

    return 0;
}
