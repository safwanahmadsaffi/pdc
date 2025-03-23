#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define N 500  // Matrix size
#define NUM_THREADS 12  // Adjust based on CPU cores
void multiply_matrices_parallel(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
