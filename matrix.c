#include <stdio.h>

#define MAX 10

// Function to read a matrix
void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

// Function to print a matrix
void printMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

// Matrix Multiplication
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

// Matrix Transpose
void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = mat[i][j];
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("=== Matrix Operations ===\n");
    printf("1. Matrix Addition\n2. Matrix Multiplication\n3. Matrix Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter rows and columns for both matrices: ");
            scanf("%d %d", &r1, &c1);
            r2 = r1; c2 = c1;

            printf("Matrix A:\n");
            readMatrix(a, r1, c1);
            printf("Matrix B:\n");
            readMatrix(b, r2, c2);

            addMatrix(a, b, result, r1, c1);

            printf("Sum of Matrices:\n");
            printMatrix(result, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Multiplication not possible. Columns of A must equal rows of B.\n");
                break;
            }

            printf("Matrix A:\n");
            readMatrix(a, r1, c1);
            printf("Matrix B:\n");
            readMatrix(b, r2, c2);

            multiplyMatrix(a, b, result, r1, c1, c2);

            printf("Product of Matrices:\n");
            printMatrix(result, r1, c2);
            break;

        case 3:
            printf("Enter rows and columns of Matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Matrix:\n");
            readMatrix(a, r1, c1);

            transposeMatrix(a, result, r1, c1);

            printf("Transpose of Matrix:\n");
            printMatrix(result, c1, r1);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}