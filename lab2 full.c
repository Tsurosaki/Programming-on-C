#include <stdio.h>
/*Объявить массив данных типа double размером 3 на 3. 
Ввести с консоли его значения, 
вывести на консоль сумму его элементов, 
расположенных на главной диагонали и сумму элементов, 
расположенных на  побочной диагонали. 
Объявить массив данных типа int размером 2 на 2. 
 Ввести с консоли его значе-ния, вывести на консоль квадрат данной матрицы.
*/
int main() {
    double doubleMatrix[3][3];
    double mainDiagonalSum = 0.0;
    double secondaryDiagonalSum = 0.0;
    printf("Введите элементы массива типа double размером 3 на 3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &doubleMatrix[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        mainDiagonalSum += doubleMatrix[i][i];          // главная диагональ
        secondaryDiagonalSum += doubleMatrix[i][2 - i]; // побочная диагональ
    }
    printf("Сумма элементов главной диагонали: %.2lf\n", mainDiagonalSum);
    printf("Сумма элементов побочной диагонали: %.2lf\n", secondaryDiagonalSum);
    int intMatrix[2][2];
    int squareMatrix[2][2];
    printf("Введите элементы массива типа int размером 2 на 2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &intMatrix[i][j]);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            squareMatrix[i][j] = intMatrix[i][0] * intMatrix[0][j] + intMatrix[i][1] * intMatrix[1][j];
        }
    }
    printf("Квадрат данной матрицы:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", squareMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
