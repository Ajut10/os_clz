#include <stdio.h>

#define N 3 // Number of equations

void gaussJordan(float mat[N][N+1]) {
    int i, j, k;
    float ratio;

    for (i = 0; i < N; i++) {
        // Partial pivoting
        for (k = i + 1; k < N; k++) {
            if (mat[i][i] < mat[k][i]) {
                for (j = 0; j <= N; j++) {
                    float temp = mat[i][j];
                    mat[i][j] = mat[k][j];
                    mat[k][j] = temp;
                }
            }
        }

        // Make all elements of current row except mat[i][i] equal to 0
        for (j = 0; j < N; j++) {
            if (i != j) {
                ratio = mat[j][i] / mat[i][i];
                for (k = 0; k <= N; k++) {
                    mat[j][k] -= ratio * mat[i][k];
                }
            }
        }
    }

    // Make all diagonal elements equal to 1
    for (i = 0; i < N; i++) {
        ratio = mat[i][i];
        for (j = 0; j <= N; j++) {
            mat[i][j] /= ratio;
        }
    }

    printf("Solution:\n");
    for (i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, mat[i][N]);
    }
}

int main() {
    float mat[N][N+1] = {{1, 1, 1, 9},
                         {2, -3, 4, 13},
                         {3, 4, 5, 40}};

    gaussJordan(mat);

    return 0;
}

