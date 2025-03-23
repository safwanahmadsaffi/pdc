#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500  // Matrix size
void multiply_matrices(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
double get_execution_time() {
    int A[N][N], B[N][N], C[N][N];

    // Initialize matrices with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }
    clock_t start = clock();
    multiply_matrices(A, B, C);
    clock_t end = clock();
    
    return (double)(end - start) / CLOCKS_PER_SEC;
}
int main() {
    double total_time = 0.0;
    int runs = 10;
    for (int i = 0; i < runs; i++) {
        total_time += get_execution_time();
    }
    printf("Average Execution Time (Sequential): %.6f seconds\n", total_time / runs);
    return 0;
}
