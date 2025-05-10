#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100

int is_operator(char c) {
    return c == '+' || c == '-';
}

double calculate_expression(const char *input) {
    char expr[1024];
    strncpy(expr, input, sizeof(expr) - 1);
    expr[sizeof(expr) - 1] = '\0';

    double numbers[MAX_TOKENS];
    char operators[MAX_TOKENS];
    int num_count = 0, op_count = 0;

    char processed[2048];
    int j = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '+' || expr[i] == '-') {
            if (i > 0 && processed[j-1] != ' ') {
                processed[j++] = ' ';
            }
            processed[j++] = expr[i];
            if (expr[i+1] != ' ' && expr[i+1] != '\0') {
                processed[j++] = ' ';
            }
        } else if (expr[i] != ' ') {
            processed[j++] = expr[i];
        } else {
        }
    }
    processed[j] = '\0';

    char *token = strtok(processed, " ");
    int expect_number = 1;

    while (token != NULL) {
        if (expect_number) {
            if ((strcmp(token, "+") == 0 || strcmp(token, "-") == 0)) {
                char sign = token[0];
                token = strtok(NULL, " ");
                if(token == NULL) {
                    fprintf(stderr, "Ошибка: неподходящий формат выражения\n");
                    exit(1);
                }
                char number_str[100];
                if (sign == '-')
                    snprintf(number_str, sizeof(number_str), "-%s", token);
                else
                    snprintf(number_str, sizeof(number_str), "%s", token);

                double val = strtod(number_str, NULL);
                numbers[num_count++] = val;
            } else {
                double val = strtod(token, NULL);
                numbers[num_count++] = val;
            }
            expect_number = 0;
        } else {
            if (strlen(token) != 1 || !is_operator(token[0])) {
                fprintf(stderr, "Ошибка: ожидался оператор '+/-', а получено: %s\n", token);
                exit(1);
            }
            operators[op_count++] = token[0];
            expect_number = 1;
        }

        token = strtok(NULL, " ");
    }

    if (num_count == 0) {
        fprintf(stderr, "Ошибка: нет чисел для вычисления\n");
        exit(1);
    }
    if (num_count != op_count + 1) {
        fprintf(stderr, "Ошибка: несоответствие количества чисел и операций\n");
        exit(1);
    }

    double result = numbers[0];
    for (int i = 0; i < op_count; i++) {
        if (operators[i] == '+') {
            result += numbers[i+1];
        } else if (operators[i] == '-') {
            result -= numbers[i+1];
        }
    }
    return result;
}

int main() {
    char input[1024];
    printf("Введите выражение: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Ошибка при вводе\n");
        return 1;
    }

    input[strcspn(input, "\\n")] = '\0';

    double result = calculate_expression(input);
    printf("Результат: %.10g\n", result);

    return 0;
}
