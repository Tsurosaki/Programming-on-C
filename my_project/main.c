#include <stdio.h>
#include "triangle.h"

// Функция для проверки, является ли тройка чисел длинами сторон треугольника
int is_valid_triangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    double a, b, c;

    printf("Введите длину первой стороны треугольника: ");
    scanf("%lf", &a);
    printf("Введите длину второй стороны треугольника: ");
    scanf("%lf", &b);
    printf("Введите длину третьей стороны треугольника: ");
    scanf("%lf", &c);

    if (is_valid_triangle(a, b, c)) {
        double perimeter = calculate_perimeter(a, b, c);
        double area = calculate_area(a, b, c);
        printf("Периметр треугольника: %.2lf\n", perimeter);
        printf("Площадь треугольника: %.2lf\n", area);
    } else {
        printf("Ошибка: введенные длины не могут образовать треугольник.\n");
    }

    return 0;
}