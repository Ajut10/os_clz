#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations
#define MAX_ITERATIONS 100 // Maximum number of iterations
#define ERROR_THRESHOLD 0.0001 // Error threshold for convergence

void gaussSeidel(float mat[N][N+1]) {
    int i, j, iter;
    float roots[N] = {0}; // Initial guess for roots
    float prevRoots[N]; // Previous iteration roots
    float error;

    // Perform Gauss-Seidel iterations
    for (iter = 0; iter < MAX_ITERATIONS; iter++) {
        // Store current roots for error calculation
        for (i = 0; i < N; i++) {
            prevRoots[i] = roots[i];
        }

        // Update roots
        for (i = 0; i < N; i++) {
            float sum = 0;
            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum += mat[i][j] * roots[j];
                }
            }
            roots[i] = (mat[i][N] - sum) / mat[i][i];
        }

        // Check for convergence
        error = 0;
        for (i = 0; i < N; i++) {
            error += fabs(roots[i] - prevRoots[i]);
        }
        if (error < ERROR_THRESHOLD) {
            break; // Converged
        }
    }

    // Print solution
    printf("Solution after %d iterations:\n", iter + 1);
    for (i = 0; i < N; i++) {
        printf("x%d = %.4f\n", i+1, roots[i]);
    }
}

int main() {
    float mat[N][N+1] = {{10, 2, 1, 9},
                         {2, 20, -2, -44},
                         {-2, 3, 10, 22}};

    gaussSeidel(mat);

    return 0;
}

