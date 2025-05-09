#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 100

#define MAX_IN_ARRAY(arr, count) ({        \
    int max_val = (count) > 0 ? (arr)[0] : 0;  \
    for (int i = 1; i < (count); ++i) {   \
        if ((arr)[i] > max_val)            \
            max_val = (arr)[i];            \
    }                                     \
    max_val;                              \
})

int main() {
    char input[1024];
    int numbers[MAX_NUMBERS];
    int count = 0;

    printf("Введите числа через пробел: ");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Ошибка чтения строки.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = 0;

    char *token = strtok(input, " ");
    while (token != NULL && count < MAX_NUMBERS) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    if (count == 0) {
        printf("Числа не введены.\n");
        return 1;
    }

    int max_value = MAX_IN_ARRAY(numbers, count);

    printf("Максимальное число: %d\n", max_value);

    return 0;
}

