#include <stdio.h>

#define MAX_TERMS 101
#define MAX_COL 50

// Structure to represent a triplet element
struct Sparse {
    int row;
    int col;
    int value;
};

// Function to read a matrix and convert it into 3-tuple (triplet) representation
void createSparseMatrix(struct Sparse s[]) {
    int rows, cols, i, j, val, k = 1;
    
    printf("Enter total number of rows: ");
    scanf("%d", &rows);
    printf("Enter total number of columns: ");
    scanf("%d", &cols);
    
    s[0].row = rows;
    s[0].col = cols;
    
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &val);
            if (val != 0) {
                s[k].row = i;
                s[k].col = j;
                s[k].value = val;
                k++;
            }
        }
    }
    s[0].value = k - 1; // Total number of non-zero elements
}

// Function to display the sparse matrix in triplet form
void displaySparseMatrix(struct Sparse s[]) {
    int i, n = s[0].value;
    printf("\nTriplet Representation (Row | Column | Value):\n");
    printf("%d\t%d\t%d\n", s[0].row, s[0].col, s[0].value);
    printf("-------------------\n");
    for (i = 1; i <= n; i++) {
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].value);
    }
}

// Function to perform Simple Transpose
void simpleTranspose(struct Sparse a[], struct Sparse b[]) {
    int n, i, j, currentb;
    
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    n = b[0].value = a[0].value;
    
    if (n > 0) {
        currentb = 1;
        for (i = 0; i < a[0].col; i++) {
            for (j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[currentb].row = a[j].col;
                    b[currentb].col = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
            }
        }
    }
}

// Function to perform Fast Transpose
void fastTranspose(struct Sparse a[], struct Sparse b[]) {
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i, j, num_cols = a[0].col, num_nz = a[0].value;
    
    b[0].row = num_cols;
    b[0].col = a[0].row;
    b[0].value = num_nz;
    
    if (num_nz > 0) {
        // Initialize rowTerms to 0
        for (i = 0; i < num_cols; i++) {
            rowTerms[i] = 0;
        }
        
        // Count frequency of each column in original matrix (which becomes row in transpose)
        for (i = 1; i <= num_nz; i++) {
            rowTerms[a[i].col]++;
        }
        
        // Find the starting position of each row in the transposed matrix
        startingPos[0] = 1;
        for (i = 1; i < num_cols; i++) {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }
        
        // Place elements into their correct positions in the transposed matrix
        for (i = 1; i <= num_nz; i++) {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

int main() {
    struct Sparse a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS];
    
    printf("--- Sparse Matrix Realization ---\n");
    createSparseMatrix(a);
    
    printf("\nOriginal Sparse Matrix:");
    displaySparseMatrix(a);
    
    // Simple Transpose
    simpleTranspose(a, b);
    printf("\n--- Simple Transpose ---");
    displaySparseMatrix(b);
    
    // Fast Transpose
    fastTranspose(a, c);
    printf("\n--- Fast Transpose ---");
    displaySparseMatrix(c);
    
    return 0;
}
