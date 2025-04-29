#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Rus");
    FILE *input, *output;
    char line[MAX_LINE_LENGTH];
    char s1[50], s2[50], s3[50];
    int year;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Íå óäàëîñü îòêðûòü âõîäíîé ôàéë");
        return EXIT_FAILURE;
    }
    output = fopen("output.txt", "w+");
    if (output == NULL) {
        perror("Íå óäàëîñü îòêðûòü âûõîäíîé ôàéë");
        fclose(input);
        return EXIT_FAILURE;
}

    while (fscanf(input, "%s %s %s %d", s1, s2, s3, &year) != EOF) {
       if (sscanf(line, "%s %s %s %d", s1, s2, s3, &year) == 4) {
            if (year > 1980) {
                fprintf(output, "%s", line);
            }
        } else {
            printf("Îøèáêà ôîðìàòà ñòðîêè: %s", line);
        }
    }

    fclose(input);
    fclose(output);

    printf("Îáðàáîòêà çàâåðøåíà. Ðåçóëüòàò çàïèñàí â output.txt\n");

    return 0;
}
