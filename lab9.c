#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
double calculate(const char *expression) {
    double result = 0.0;
    char *token;
    char *expr_copy = strdup(expression); // Создаем копию строки для разбора
    token = strtok(expr_copy, " "); // Разбиваем строку по пробелам
    double current_value = 0.0; // Текущая числовая величина
    char operation = '+'; // Начальная операция (по умолчанию сложение)
    while (token != NULL) {
        // Проверяем, является ли токен числом
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            current_value = atof(token); // Преобразуем токен в число

            // Выполняем операцию в зависимости от предыдущей операции
            switch (operation) {
                case '+':
                    result += current_value;
                    break;
                case '-':
                    result -= current_value;
                    break;
            }
        } else if (token[0] == '+' || token[0] == '-') {
            operation = token[0]; // Обновляем текущую операцию
        }

        token = strtok(NULL, " "); // Переходим к следующему токену
    }

    free(expr_copy); // Освобождаем память, выделенную для копии строки
    return result; // Возвращаем результат вычисления
}

int main() {
    char expression[256]; // Буфер для ввода выражения

    printf("Введите арифметическое выражение: ");
    fgets(expression, sizeof(expression), stdin); // Читаем ввод пользователя

    double result = calculate(expression); // Вычисляем результат
    printf("Результат: %.2f\n", result); // Выводим результат

    return 0; // Завершаем программу с кодом возврата 0 (успешно)
}
