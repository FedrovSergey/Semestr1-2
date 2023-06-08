#include <stdio.h>

/*y = x^10 + 2 * x^9 + 3 * x^8 + ... + 10 * x + 11*/
/*вводится число, вывести его двойной факториал (числа с одной четностью с исходным считаются)*/

int main() {
	/*основное задание*/
	/*
	int x;
	printf("enter number:");
	if ((scanf("%d", &x, "\n")) != 1) {
		printf("error");
	}
	else {
		long long y = 11, st = x;
		for (int i = 0; i < 10; i++){
			y = y + (10 - i) * st;
			st = st * x;
		}
		printf("result:%d", y); 
	}
	*/
	/*доп*/
	int x, clarity;
	long long doubleFactorial = 1;
	printf("enter number:");
	if ((scanf("%d", &x, "\n")) != 1) {
		printf("error");
	}
	else {
		clarity = x % 2;
		for (int i = 2; i <= x; i++){
			if (i % 2 == clarity) {
				doubleFactorial *= i;
			}
		}
		printf("result:%d", doubleFactorial);
	}
	return 0;
}