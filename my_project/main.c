#include <stdio.h>
#include "triangle.h"

int main() {
    double a, b, c;

    printf("Длины сторон треугольника: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (is_valid_triangle(a, b, c)) {
        double perimeter = calculate_perimeter(a, b, c);
        double area = calculate_area(a, b, c);
        printf("Периметр треугольника: %.2lf\n", perimeter);
        printf("Площадь треугольника: %.2lf\n", area);
    
        double height = calculate_height(area, b);
        printf("Высота треугольника по выбранной стороне %.2lf: %.2lf\n", b, height);
    } 
    else {
        printf("Введенные длины не могут образовать треугольник.\n");
    }
    return 0;
}
