#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    char operation;
    
    printf("Введите размерность матриц n: ");
    scanf("%d", &n);
    
    double **matrix1 = (double **)malloc(n * sizeof(double *));
    double **matrix2 = (double **)malloc(n * sizeof(double *));
    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrix1[i] = (double *)malloc(n * sizeof(double));
        matrix2[i] = (double *)malloc(n * sizeof(double));
        result[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Введите элементы первой матрицы:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &matrix1[i][j]);

    // Ввод элементов второй матрицы
    printf("Введите элементы второй матрицы:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &matrix2[i][j]);

    // Ввод операции
    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &operation);

    // Вычисление результатов
    compute_matrices(matrix1, matrix2, result, n, operation);

    // Вывод результата
    printf("Результат:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%lf ", result[i][j]);
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
