#include <stdio.h>

#define SIZE 3   // Matrix size (3x3 for example)

void printMatrix(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], sum[SIZE][SIZE], product[SIZE][SIZE], transpose[SIZE][SIZE];

    // Input matrices
    printf("Enter elements of matrix A (%dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B (%dx%d):\n", SIZE, SIZE);
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            scanf("%d", &B[i][j]);

    // Matrix Addition
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            sum[i][j] = A[i][j] + B[i][j];

    // Matrix Multiplication
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            product[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Transpose of Matrix A
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            transpose[j][i] = A[i][j];

    // Output results
    printf("\nMatrix A:\n");
    printMatrix(A);

    printf("\nMatrix B:\n");
    printMatrix(B);

    printf("\nSum of A and B:\n");
    printMatrix(sum);

    printf("\nProduct of A and B:\n");
    printMatrix(product);

    printf("\nTranspose of Matrix A:\n");
    printMatrix(transpose);

    return 0;
}
