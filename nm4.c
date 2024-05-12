#include <stdio.h>

#define N 3 // Number of equations

void gaussElimination(float mat[N][N + 1]);

int main() {
    float mat[N][N + 1] = {
        {2, 3, 4, 5},
        {3, 4, 5, 6},
        {4, 5, 6, 7}
    };

    gaussElimination(mat);

    printf("Solution:\n");
    for(int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, mat[i][N]);
    }

    return 0;
}

void gaussElimination(float mat[N][N + 1]) {
    int i, j, k;
    float ratio, x[N];

    // Forward elimination
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            ratio = mat[j][i] / mat[i][i];
            for (k = 0; k <= N; k++) {
                mat[j][k] = mat[j][k] - ratio * mat[i][k];
            }
        }
    }

    // Back substitution
    for (i = N - 1; i >= 0; i--) {
        x[i] = mat[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] = x[i] / mat[i][i];
    }

    // Assigning values of x to solution matrix
    for (i = 0; i < N; i++) {
        mat[i][N] = x[i];
    }
}

