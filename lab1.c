#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a, b, c;
	double x, x1, x2, d;
	char choice;
	do {
	a = 5.3;
	b = 12.5;
	c = 1.1;
	d = b*b - 4*a*c;
	if (d > 0) {
		x1 = -b/(2*a) + sqrt(d)/(2*a);
		x2 = -b/(2*a) - sqrt(d)/(2*a);
		printf("x1 = %lf\n", x1);
		printf("x2 = %lf\n", x2);
	} 
	if (d = 0) {
	    x = -b/(2*a);
	    printf("x = %lf\n", x);
	}
	else {
		printf("Êîðíåé íåò, äèñêðèìèíàíò ìåíüøå íóëÿ.\n");
	}
	    printf("Ðåøèòü ñíîâà?\n");
	    while (getchar() != '\n');
	    scanf("%c", &choice);    
	    printf("choice = %c \n", choice);
} while (choice == 'y');
	return 0;
}
