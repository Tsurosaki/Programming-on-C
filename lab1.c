#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a, b, c;
	double x1, x2, x, d;
	char choice;
	do {
	printf("Вам необходимо ввести ваши значения: \n");
	scanf("%lf %lf %lf", &a, &b, &c);
	d = (b*b) - (4*a*c);
	printf("%lf\n", d);
	if (d > 0) {
		x1 = -b + sqrt(d)/(2*a);
		x2 = -b - sqrt(d)/(2*a);
		printf("x1 = %lf\n", x1);
		printf("x2 = %lf\n", x2);
	}
	else if (d == 0) {
		x = -b/(2*a);
		printf("x = %lf\n", x);
	}
	else {
		printf("Дискриминант меньше нуля, корней нет\n");
	}
	    printf("Хотите начать ещё раз? \n");
	    while(getchar () != '\n');
	    scanf("%c", &choice);
	    printf("choice = %c\n", choice);
} while(choice == 'x');
	return 0;
}
