#include <math.h>

// Функция для вычисления периметра треугольника
double calculate_perimeter(double a, double b, double c) {
    return a + b + c;
}

// Функция для вычисления площади треугольника по формуле Герона
double calculate_area(double a, double b, double c) {
    double s = (a + b + c) / 2; // Полупериметр
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double calculate_height(double area, double base) {
    return (2 * area) / base; // Высота по основанию
}
