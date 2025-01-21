// Implement the matrix multiplication algorithm in C.
// Input: Two matrices A and B
// Output: Resultant matrix C = A * B
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

#include <stdio.h>

void matrix_multiplication(int A[10][10], int B[10][10], int C[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int m, n, p;
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &m, &n);
    int A[10][10];
    printf("Enter the elements of matrix A: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter the number of columns of matrix B: ");
    scanf("%d", &p);
    int B[10][10];
    printf("Enter the elements of matrix B: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    int C[10][10];
    matrix_multiplication(A, B, C, m, n, p);
    printf("Resultant matrix C = A * B: \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
Algorithm for Matrix Multiplication:
1. Initialize the resultant matrix C with zeros.
2. For each element in matrix C, compute the dot product of the corresponding row from matrix A and column from matrix B.
3. Store the result in the corresponding element of matrix C.

Pseudo code:
Input: Matrices A of size m x n and B of size n x p
Output: Resultant matrix C of size m x p

Algorithm matrix_multiplication(A, B, C, m, n, p):
    for i from 0 to m-1:
        for j from 0 to p-1:
            C[i][j] = 0
            for k from 0 to n-1:
                C[i][j] = C[i][j] + A[i][k] * B[k][j]
    return C
*/
