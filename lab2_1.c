#include <stdio.h>
int main() {
    double matrix[3][3];
    double main_diagonal_sum = 0.0, secondary_diagonal_sum = 0.0;
    printf("Введите значения для матрицы 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Элемент [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        main_diagonal_sum += matrix[i][i];
    }
    for (int i = 0; i < 3; i++) {
        secondary_diagonal_sum += matrix[i][2 - i];
    }
    printf("Сумма элементов на главной диагонали: %.2lf\n", main_diagonal_sum);
    printf("Сумма элементов на побочной диагонали: %.2lf\n", secondary_diagonal_sum);
    return 0;
}
