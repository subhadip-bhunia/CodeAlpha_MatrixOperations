#include <stdio.h>
int i,j,k;
// Function to take matrix input
void inputMatrix(int matrix[10][10], int row, int col) {
    printf("Enter elements of the matrix (%d x %d):\n", row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[10][10], int row, int col) {
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addMatrix(int A[10][10], int B[10][10], int result[10][10], int row, int col) {
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function for matrix multiplication
void multiplyMatrix(int A[10][10], int B[10][10], int result[10][10], int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        printf("Matrix multiplication not possible!\n");
        return;
    }

    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (k = 0; k < col1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for matrix transpose
void transposeMatrix(int matrix[10][10], int transposed[10][10], int row, int col) {
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// Main function
int main() {
    int A[10][10], B[10][10], result[10][10], transposed[10][10];
    int row1, col1, row2, col2;
    int choice;

    printf("========== MATRIX OPERATIONS ==========\n");

    do {
        printf("\nMenu:\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter rows and columns of matrices: ");
                scanf("%d%d", &row1, &col1);
                printf("Matrix A:\n");
                inputMatrix(A, row1, col1);
                printf("Matrix B:\n");
                inputMatrix(B, row1, col1);

                addMatrix(A, B, result, row1, col1);
                printf("\nResultant Matrix (A + B):\n");
                displayMatrix(result, row1, col1);
                break;

            case 2:
                printf("\nEnter rows and columns of Matrix A: ");
                scanf("%d%d", &row1, &col1);
                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &row2, &col2);

                printf("Matrix A:\n");
                inputMatrix(A, row1, col1);
                printf("Matrix B:\n");
                inputMatrix(B, row2, col2);

                if (col1 != row2) {
                    printf("Matrix multiplication not possible!\n");
                } else {
                    multiplyMatrix(A, B, result, row1, col1, row2, col2);
                    printf("\nResultant Matrix (A × B):\n");
                    displayMatrix(result, row1, col2);
                }
                break;

            case 3:
                printf("\nEnter rows and columns of Matrix: ");
                scanf("%d%d", &row1, &col1);
                printf("Matrix:\n");
                inputMatrix(A, row1, col1);

                transposeMatrix(A, transposed, row1, col1);
                printf("\nTranspose of the Matrix:\n");
                displayMatrix(transposed, col1, row1);
                break;

            case 4:
                printf("\nExiting program. Thank you!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
