#include <stdio.h>

int main() {
    int matrix_int[2][2];
    int matrix_square[2][2] = {0};

    printf("¬ведите 4 значени€ дл€ матрицы 2x2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Ёлемент [%d][%d]: ", i, j);
            scanf("%d", &matrix_int[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                matrix_square[i][j] += matrix_int[i][k] * matrix_int[k][j];
            }
        }
    }

    printf(" вадрат матрицы:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix_square[i][j]);
        }
        printf("\n");
    }

    return 0;
}
