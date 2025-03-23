#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 500  // Matrix size
#define NUM_THREADS 4  // Adjust based on CPU cores

void multiply_matrices_parallel(int A[N][N], int B[N][N], int C[N][N]) {
    #pragma omp parallel for schedule(static) num_threads(NUM_THREADS)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;  // Ensure proper initialization before summing
        }
        for (int k = 0; k < N; k++) {  
            #pragma omp simd
            for (int j = 0; j < N; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

double get_parallel_execution_time() {
    int A[N][N], B[N][N], C[N][N];

    // Initialize matrices with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0; // Initialize C to zero
        }
    }

    double start = omp_get_wtime();
    multiply_matrices_parallel(A, B, C);
    double end = omp_get_wtime();
    
    return end - start;
}

int main() {
    double total_time = 0.0;
    int runs = 10;

    for (int i = 0; i < runs; i++) {
        total_time += get_parallel_execution_time();
    }

    printf("Average Execution Time (Optimized Parallel): %.6f seconds\n", total_time / runs);
    return 0;
}
