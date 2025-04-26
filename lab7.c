#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define ARRAY_SIZE 4

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int birthYear;
} humen;

void sortByBirthYear(humen arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].birthYear > arr[j + 1].birthYear) {
                humen temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(humen arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Имя: %s, Фамилия: %s, Год рождения: %d\n", arr[i].firstName, arr[i].lastName, arr[i].birthYear);
    }
}

int main() {
    humen array1[ARRAY_SIZE];
    humen array2[ARRAY_SIZE];

    printf("Введите данные для %d человек:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Человек %d:\n", i + 1);
        printf("Имя: ");
        scanf("%s", array1[i].firstName);
        printf("Фамилия: ");
        scanf("%s", array1[i].lastName);
        printf("Год рождения: ");
        scanf("%d", &array1[i].birthYear);
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array2[i] = array1[i];
    }

    sortByBirthYear(array2, ARRAY_SIZE);

    printf("\nОтсортированный список по годам рождения:\n");
    printArray(array2, ARRAY_SIZE);

    return 0;
}
