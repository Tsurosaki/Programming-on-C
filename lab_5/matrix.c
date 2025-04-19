#include <stdio.h>
#include <math.h>

void compute_matrices(double **matrix1, double **matrix2, double **result, int n, char operation) {
    switch (operation) {
        case '+':
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
            break;

        case '-':
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
            break;

        case '*':
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < n; k++)
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            break;

        default:
            printf("Недействительная операция\n");
    }
}